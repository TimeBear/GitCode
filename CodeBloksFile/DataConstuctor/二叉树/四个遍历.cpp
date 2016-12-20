#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

struct BiNode {
	string data;
	BiNode *lchild,*rchild;
};

class BiTree {
	private:
		BiNode *root;
		//creat letter	������
		BiNode* creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2);

		//ergodic letter	������
		void preorder(BiNode *bt);
		void inorder(BiNode *bt);
		void postorder(BiNode *bt);

	public:
		
		//ǰ���������й��� 
		BiTree(char *pre,char *ind) {
			root=creat(root,pre,ind,0,strlen(pre)-1,0,strlen(ind)-1);   //ǰ��+������
		}

		void preorder() {
			cout<<"preorder: "<<endl;
			preorder(root);
		}
		void inorder() {
			cout<<"inorder: "<<endl;
			inorder(root);
		}
		void postorder() {
			cout<<"postorder: "<<endl;
			postorder(root);
		}

};

BiNode * BiTree::creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2) {
	if((high1-low1)!=(high2-low2))cerr<<"String Error!";
	if(low1>high1)bt=NULL;
	else {
		BiNode *t=new BiNode;									//�����¿ռ�
		t->data=pre[low1];
		bt=t;

		//if(bt!=NULL)cout<<bt->data<<endl;						//������ڹ����Ľڵ�

		int s=low2;												//�����������в��ҵ�ǰ���ڵ�λ��
		while(s<high2&&ind[s]!=pre[low1]) {
			s++;
		}

		if(ind[s]!=pre[low1])cerr<<"String Error��";				//�������Ȩ������һ��
		else {
			t->lchild=creat(t->lchild,pre,ind,low1+1,low1+s-low2,low2,s-1);
			t->rchild=creat(t->rchild,pre,ind,low1+1+s-low2,high1,s+1,high2);
		}
	}
	return bt;		//����ָ�����͵����� �������ǵݹ飬����ÿ�ζ������һ���µ����� 
}

void BiTree::preorder(BiNode *bt)
{
    if(bt==NULL){return ;}
    else{
    cout<<bt->data<<endl;
    preorder(bt->lchild);
    preorder(bt->rchild);
    }
}

void BiTree::inorder(BiNode *bt)
{
    if(bt==NULL)return ;
    else{
    inorder(bt->lchild);
    cout<<bt->data<<endl;
    inorder(bt->rchild);
    }
}

void BiTree::postorder(BiNode *bt)
{
    if(bt==NULL)return ;
    else{
    postorder(bt->lchild);
    postorder(bt->rchild);
    cout<<bt->data<<endl;
    }
}

int main()
{
    char * pre="ABDEHCFG";
    char *ind="DBHEAFCG";
    char *post="DHEBFGCA";

	BiTree test(pre,ind);

    cout<<"���ֱ���"<<endl;
	test.preorder();
	test.inorder();
    test.postorder();
	return 0;
}

