#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

/*˵����
1.ǰ��+�����캯��:creat()
2.ǰ��+�����캯��:postcreat()
3.��������:release()
4.ǰ���������
5.�����������
6.�����������
7.�����������
8.��ǰ�ڵ����:depth()
9.�������Ҷ�ӽڵ�:leafs()
10.�ı���������:changelr()
*/

struct BiNode {
	string data;			//������ 
	BiNode *lchild,*rchild;		//���Һ��� 
};

class BiTree {
	private:
		BiNode *root;		 //������ڵ� 

		//creat letter	������
		//�к������� 
		BiNode* postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2);

		//ergodic letter	������
		void preorder(BiNode *bt);			//ǰ����� 
		void inorder(BiNode *bt);			//������� 
		void postorder(BiNode *bt);			//������� 
		
		
	public:
		//���캯�� 
		BiTree(char *post,char *ind) {
			root=postcreat(root,post,ind,0,strlen(post)-1,0,strlen(ind)-1);   //���ڵ�����ݸ�ֵ 
		}

		//�Ĵ��������
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

//���������� 
BiNode * BiTree::postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2) {
	if((high1-low1)!=(high2-low2))cerr<<"String Error!";		//��֤�����ַ���������� 
	if(low1>high1)bt=NULL;										//���������� 
	else {
		BiNode *t=new BiNode;
		t->data=post[high1];					//����Ҫ�����һ�����п�ʼ���� 
		bt=t;

		if(bt!=NULL)cout<<bt->data<<endl;

		int s=high2;
		while(s>low2&&ind[s]!=post[high1]) {
			s--;
		}

		if(ind[s]!=post[high1])cerr<<"String Error";
		else {

			t->lchild=postcreat(t->lchild,post,ind,low1,high1-(high2-s)-1,low2,s-1);
			t->rchild=postcreat(t->rchild,post,ind,high1-(high2-s),high1-1,s+1,high2);
		}
	}
	return bt;
}

void BiTree::preorder(BiNode *bt) {
	if(bt==NULL) {
		return ;
	} else {
		cout<<bt->data<<endl;
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}

void BiTree::inorder(BiNode *bt) {
	if(bt==NULL)return ;
	else {
		inorder(bt->lchild);
		cout<<bt->data<<endl;
		inorder(bt->rchild);
	}
}

void BiTree::postorder(BiNode *bt) {
	if(bt==NULL)return ;
	else {
		postorder(bt->lchild);
		postorder(bt->rchild);
		cout<<bt->data<<endl;
	}
}

int main() {
	char * pre="ABDEHCFG";
	char *ind="DBHEAFCG";
	char *post="DHEBFGCA";

	BiTree test(post,ind);

	cout<<"���ֱ���"<<endl;
	test.preorder();

	test.inorder();
	test.postorder();

	return 0;
}
