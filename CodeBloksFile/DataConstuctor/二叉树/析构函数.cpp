#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

/*说明：
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
	string data;
	BiNode *lchild,*rchild;
};

class BiTree {
	private:
		BiNode *root;
		BiNode* postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2);
		void release(BiNode *bt);

		//ergodic letter	遍历层
		void preorder(BiNode *bt);
		void inorder(BiNode *bt);
		void postorder(BiNode *bt);

	public:

		BiTree(char *post,char *ind) {
			root=postcreat(root,post,ind,0,strlen(post)-1,0,strlen(ind)-1);   //打开开关开启后序构造函数
						//前序和中序，中序和后序的根节点初始化是相同的 
		}

		~BiTree() {
			release(root);    //析构函数
			cout<<"	delete sucessful!!	"<<endl;
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

BiNode * BiTree::postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2) {
	if((high1-low1)!=(high2-low2))cerr<<"String Error!";
	if(low1>high1)bt=NULL;
	else {
		BiNode *t=new BiNode;
		t->data=post[high1];			//从后序的最高位开始存数据 
		bt=t;

		if(bt!=NULL)cout<<bt->data<<endl;

		int s=high2;				//在中序的序列找到后序中的根节点 
		//中序从最高位向下找 ，也可以从最低位向上找 
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

void BiTree::release(BiNode *bt) {
	if(bt!=NULL) {
		release(bt->lchild);
		release(bt->rchild);
		delete bt;
	}
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
	string loc="H";

	BiTree test(post,ind);

	cout<<"各种遍历"<<endl;
	test.preorder();

	test.inorder();
	test.postorder();

	return 0;
}

