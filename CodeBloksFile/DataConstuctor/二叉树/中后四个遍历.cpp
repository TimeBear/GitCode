#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

/*说明：
1.前序+中序构造函数:creat()
2.前序+后序构造函数:postcreat()
3.析构函数:release()
4.前序遍历函数
5.中序遍历函数
6.后序遍历函数
7.层序遍历函数
8.求当前节点深度:depth()
9.求该树的叶子节点:leafs()
10.改变左右子树:changelr()
*/

struct BiNode {
	string data;			//数据域 
	BiNode *lchild,*rchild;		//左右孩子 
};

class BiTree {
	private:
		BiNode *root;		 //构造根节点 

		//creat letter	构建层
		//中后序序列 
		BiNode* postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2);

		//ergodic letter	遍历层
		void preorder(BiNode *bt);			//前序遍历 
		void inorder(BiNode *bt);			//中序遍历 
		void postorder(BiNode *bt);			//后序遍历 
		
		
	public:
		//构造函数 
		BiTree(char *post,char *ind) {
			root=postcreat(root,post,ind,0,strlen(post)-1,0,strlen(ind)-1);   //根节点的数据赋值 
		}

		//四大遍历函数
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

//建立二叉树 
BiNode * BiTree::postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2) {
	if((high1-low1)!=(high2-low2))cerr<<"String Error!";		//保证两个字符串长度相等 
	if(low1>high1)bt=NULL;										//建立二叉树 
	else {
		BiNode *t=new BiNode;
		t->data=post[high1];					//后序要从最后一个序列开始排数 
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

	cout<<"各种遍历"<<endl;
	test.preorder();

	test.inorder();
	test.postorder();

	return 0;
}
