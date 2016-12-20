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

struct BiNode
{
    string data;
    BiNode *lchild,*rchild;
};

class BiTree
{
	private:
        BiNode *root;
		//used for queue in leverorder


		/*
        BiNode* Q[20];//cengxu
        int front,rear;//cengxu
        */

        //creat letter	构建层
//		BiNode* creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2);
		BiNode* postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2);
//		void release(BiNode *bt);

		//ergodic letter	遍历层
		void preorder(BiNode *bt);
		void inorder(BiNode *bt);
		void postorder(BiNode *bt);

/*
		//function letter	功能层
		int depth(string loc,BiNode *bt,int d);                  //第二题：计算任意节点深度
		int leafs(BiNode *bt);                                   //第三题：计算叶子节点的数目
*/
	public:
//		BiTree(char *pre,char *ind){root=creat(root,pre,ind,0,strlen(pre)-1,0,strlen(ind)-1);}//前序+中序构造

        BiTree(char *post,char *ind){root=postcreat(root,post,ind,0,strlen(post)-1,0,strlen(ind)-1);} //打开开关开启后序构造函数

//		~BiTree(){release(root);cout<<"	delete sucessful!!	"<<endl;}		//析构函数



		//四大遍历函数
		void preorder(){cout<<"preorder: "<<endl;preorder(root);}
        void inorder(){cout<<"inorder: "<<endl;inorder(root);}
        void postorder(){cout<<"postorder: "<<endl;postorder(root);}
  //      void leverorder();


/*
		//三道功能性题目
		int  depth(string loc){return depth(loc,root,1);}		//第二题：计算任意节点深度
		int  leafs(){return leafs(root);}						//第三题：计算叶子节点的数目
		void changelr();										//第四题：改变左右子树位置
*/

};

/*
BiNode * BiTree::creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2)
{
    if((high1-low1)!=(high2-low2))cerr<<"String Error!";
    if(low1>high1)bt=NULL;
    else
    {
        BiNode *t=new BiNode;									//分配新空间
        t->data=pre[low1];
        bt=t;

        if(bt!=NULL)cout<<bt->data<<endl;						//输出正在构建的节点

        int s=low2;												//在中序序列中查找当前根节点位置
        while(s<high2&&ind[s]!=pre[low1]){
            s++;
        }

        if(ind[s]!=pre[low1])cerr<<"String Error！";				//程序控制权交给下一级
        else{
            t->lchild=creat(t->lchild,pre,ind,low1+1,low1+s-low2,low2,s-1);
            t->rchild=creat(t->rchild,pre,ind,low1+1+s-low2,high1,s+1,high2);
        }
    }
    return bt;
}
*/

BiNode * BiTree::postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2)
{
    if((high1-low1)!=(high2-low2))cerr<<"String Error!";
    if(low1>high1)bt=NULL;
    else
    {
        BiNode *t=new BiNode;
        t->data=post[high1];
        bt=t;

        if(bt!=NULL)cout<<bt->data<<endl;

        int s=high2;
        while(s>low2&&ind[s]!=post[high1]){
            s--;
        }

        if(ind[s]!=post[high1])cerr<<"String Error";
        else{

            t->lchild=postcreat(t->lchild,post,ind,low1,high1-(high2-s)-1,low2,s-1);
            t->rchild=postcreat(t->rchild,post,ind,high1-(high2-s),high1-1,s+1,high2);
        }
    }
    return bt;
}


/*
void BiTree::release(BiNode *bt)
{
	if(bt!=NULL){
		release(bt->lchild);
		release(bt->rchild);
		delete bt;
	}
}

*/


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


/*
void BiTree::leverorder()										//运用队列实现层序遍历
{
    cout<<"lever order:"<<endl;
    front=rear=-1;
    if(root==NULL)return ;
    Q[++rear]=root;
    while(front!=rear)
    {
        BiNode *q=Q[++front];
        cout<<q->data<<endl;;
        if(q->lchild!=NULL)Q[++rear]=q->lchild;
        if(q->rchild!=NULL)Q[++rear]=q->rchild;
    }
}
*/



/*
//第二题：深度函数
int  BiTree::depth(string loc,BiNode *bt,int d)	//因为节点的深度指递归的层数，所以只能在传入下一个递归函数参数时统计深度
{
    int static dep=0;           				//静态变量dep来存储遍历到loc对应节点时的深度

    if(bt==NULL)return dep;
	if(loc==bt->data)           				//找到了对应的节点，把当先深度交给dep保存
	{
		dep=d;
	}
    depth(loc,bt->lchild,d+1);  				//继续搜索
    depth(loc,bt->rchild,d+1);
    return dep;                 				//返回对应的深度值
}

//第三题：叶子节点计数器
int    BiTree::leafs(BiNode *bt)
{
    int static leaf=0;             				//静态变量以累加叶子节点数量

    if(bt==NULL){return leaf;}
    if(bt->lchild==NULL&&bt->rchild==NULL)++leaf;//如果该节点没有左右子树，他就是叶子节点
    leafs(bt->lchild);
    leafs(bt->rchild);
    return leaf;                				//返回累加的叶子节点个数
}

//第四题：改变左右子树
void BiTree::changelr()           				//利用层序遍历来交换左右子树       注意：这里只将同时有左右子树的节点的子树互换
{
    front=rear=-1;
    if(root==NULL)return ;
    Q[++rear]=root;
    while(front!=rear)
    {
        BiNode *q=Q[++front];
        if(q->lchild!=NULL&&q->rchild!=NULL){
            BiNode *temp;
            temp=q->lchild;
            q->lchild=q->rchild;
            q->rchild=temp;
        }
        if(q->lchild!=NULL)Q[++rear]=q->lchild;
        if(q->rchild!=NULL)Q[++rear]=q->rchild;
    }
}



*/

int main()
{
    char * pre="ABDEHCFG";
    char *ind="DBHEAFCG";
    char *post="DHEBFGCA";
    string loc="H";

	BiTree test(post,ind);

    cout<<"各种遍历"<<endl;
	test.preorder();

	test.inorder();
    test.postorder();
/*
	test.leverorder();

    cout<<"各种功能函数"<<endl;
    cout<<"leaf nums :"<<test.leafs()<<endl;;
	cout<<"depth of \""<<loc<<"\" is "<<test.depth(loc)<<endl;;
    cout<<"交换左右子树："<<endl;
    cout<<"变换前："<<endl;
    test.leverorder();
	test.changelr();
	cout<<"变换后："<<endl;
	test.leverorder();
	*/
	return 0;
}
