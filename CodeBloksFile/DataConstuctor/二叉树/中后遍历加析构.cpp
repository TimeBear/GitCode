#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;

struct BiNode{
	string data;
	BiNode* lchild;
	BiNode* rchild;
}; 

class BiTree{
	private:
		BiNode *root;
		BiNode *creat(BiNode *bt, char *post, char *ind, int low1, int high1, int low2, int high2);
		void PreOrder(BiNode *bt);
		void InOrder(BiNode *bt);
		void PostOrder(BiNode *bt);
		void release(BiNode *bt);
		int depth(string loc, )
	public:
		
		BiTree(char *post, char *ind){
			root = creat(root, post, ind, 0, strlen(post)-1, 0, strlen(ind)-1);
		}
		~BiTree()
		{
			release(root);
			cout<<"delete sucessful";
		}
		void PreOrder(){				//加强记忆 
			cout<<"preorder"<<endl;
			PreOrder(root);
			cout<<endl;
		} 
		void InOrder(){
			cout<<"inorder"<<endl;
			InOrder(root);
			cout<<endl;
		}
		void PostOrder(){
			cout<<"postorder"<<endl;
			PostOrder(root);
			cout<<endl;
		}
};

BiNode* BiTree::creat(BiNode *bt, char *post, char *ind, int low1, int high1, int low2, int high2){
	if((high1 - low1) != (high2 - low2)) cerr<<"两个字符串不等长"<<endl;
	if(low1 > high1) bt =NULL;
	else
	{
		BiNode *t = new BiNode;
		t->data = post[high1];			//找到根节点 
		bt = t;
		int s = high2;
		while(s > low2 && ind[s] != post[high1]){
			s--;
		}
		if(ind[s] != post[high1]) cerr<<"中序找不到后序的根"<<endl;
		else
		{
			t->lchild = creat(t->lchild, post, ind, low1, high1-(high2-s)-1, low2, s-1);
			t->rchild = creat(t->rchild, post, ind, high1-(high2-s), high1-1, s+1, high2);
		}
	}
	return bt;
}

void BiTree::PreOrder(BiNode *bt)
{
	if(bt == NULL) return;
	else
	{
		cout<<bt->data<<'\t';
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
	
}

void BiTree::InOrder(BiNode *bt)
{
	if(bt == NULL)return;
	else
	{
		InOrder(bt->lchild);
		cout<<bt->data<<'\t';
		InOrder(bt->rchild);
	}
	
}

void BiTree::PostOrder(BiNode *bt)
{
	if(bt == NULL) return;
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data<<'\t';
	}
	
}

void BiTree::release(BiNode *bt)
{
	if(bt == NULL) return;
	else
	{
		release(bt->lchild);
		release(bt->rchild);
		delete bt;
	}
}
int main()
{
//	char * pre="ABDEHCFG";
    char *ind="DBHEAFCG";
    char *post="DHEBFGCA";

	BiTree test(post,ind);

    cout<<"各种遍历"<<endl;
	test.PreOrder();
	test.InOrder();
    test.PostOrder();
	return 0;
}
