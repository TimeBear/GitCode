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
		//creat letter	构建层
		BiNode* creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2);

		//ergodic letter	遍历层
		void preorder(BiNode *bt);
		void inorder(BiNode *bt);
		void postorder(BiNode *bt);

	public:
		
		//前序和中序进行构造 
		BiTree(char *pre,char *ind) {
			root=creat(root,pre,ind,0,strlen(pre)-1,0,strlen(ind)-1);   //前序+中序构造
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
		BiNode *t=new BiNode;									//分配新空间
		t->data=pre[low1];
		bt=t;

		//if(bt!=NULL)cout<<bt->data<<endl;						//输出正在构建的节点

		int s=low2;												//在中序序列中查找当前根节点位置
		while(s<high2&&ind[s]!=pre[low1]) {
			s++;
		}

		if(ind[s]!=pre[low1])cerr<<"String Error！";				//程序控制权交给下一级
		else {
			t->lchild=creat(t->lchild,pre,ind,low1+1,low1+s-low2,low2,s-1);
			t->rchild=creat(t->rchild,pre,ind,low1+1+s-low2,high1,s+1,high2);
		}
	}
	return bt;		//返回指针类型的数据 ，由于是递归，所以每次都会出来一个新的数字 
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

    cout<<"各种遍历"<<endl;
	test.preorder();
	test.inorder();
    test.postorder();
	return 0;
}

