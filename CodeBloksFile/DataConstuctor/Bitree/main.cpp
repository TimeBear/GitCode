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

        //creat letter	������
//		BiNode* creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2);
		BiNode* postcreat(BiNode *bt,char *post,char *ind,int low1,int high1,int low2,int high2);
//		void release(BiNode *bt);

		//ergodic letter	������
		void preorder(BiNode *bt);
		void inorder(BiNode *bt);
		void postorder(BiNode *bt);

/*
		//function letter	���ܲ�
		int depth(string loc,BiNode *bt,int d);                  //�ڶ��⣺��������ڵ����
		int leafs(BiNode *bt);                                   //�����⣺����Ҷ�ӽڵ����Ŀ
*/
	public:
//		BiTree(char *pre,char *ind){root=creat(root,pre,ind,0,strlen(pre)-1,0,strlen(ind)-1);}//ǰ��+������

        BiTree(char *post,char *ind){root=postcreat(root,post,ind,0,strlen(post)-1,0,strlen(ind)-1);} //�򿪿��ؿ��������캯��

//		~BiTree(){release(root);cout<<"	delete sucessful!!	"<<endl;}		//��������



		//�Ĵ��������
		void preorder(){cout<<"preorder: "<<endl;preorder(root);}
        void inorder(){cout<<"inorder: "<<endl;inorder(root);}
        void postorder(){cout<<"postorder: "<<endl;postorder(root);}
  //      void leverorder();


/*
		//������������Ŀ
		int  depth(string loc){return depth(loc,root,1);}		//�ڶ��⣺��������ڵ����
		int  leafs(){return leafs(root);}						//�����⣺����Ҷ�ӽڵ����Ŀ
		void changelr();										//�����⣺�ı���������λ��
*/

};

/*
BiNode * BiTree::creat(BiNode *bt,char *pre,char *ind,int low1,int high1,int low2,int high2)
{
    if((high1-low1)!=(high2-low2))cerr<<"String Error!";
    if(low1>high1)bt=NULL;
    else
    {
        BiNode *t=new BiNode;									//�����¿ռ�
        t->data=pre[low1];
        bt=t;

        if(bt!=NULL)cout<<bt->data<<endl;						//������ڹ����Ľڵ�

        int s=low2;												//�����������в��ҵ�ǰ���ڵ�λ��
        while(s<high2&&ind[s]!=pre[low1]){
            s++;
        }

        if(ind[s]!=pre[low1])cerr<<"String Error��";				//�������Ȩ������һ��
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
void BiTree::leverorder()										//���ö���ʵ�ֲ������
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
//�ڶ��⣺��Ⱥ���
int  BiTree::depth(string loc,BiNode *bt,int d)	//��Ϊ�ڵ�����ָ�ݹ�Ĳ���������ֻ���ڴ�����һ���ݹ麯������ʱͳ�����
{
    int static dep=0;           				//��̬����dep���洢������loc��Ӧ�ڵ�ʱ�����

    if(bt==NULL)return dep;
	if(loc==bt->data)           				//�ҵ��˶�Ӧ�Ľڵ㣬�ѵ�����Ƚ���dep����
	{
		dep=d;
	}
    depth(loc,bt->lchild,d+1);  				//��������
    depth(loc,bt->rchild,d+1);
    return dep;                 				//���ض�Ӧ�����ֵ
}

//�����⣺Ҷ�ӽڵ������
int    BiTree::leafs(BiNode *bt)
{
    int static leaf=0;             				//��̬�������ۼ�Ҷ�ӽڵ�����

    if(bt==NULL){return leaf;}
    if(bt->lchild==NULL&&bt->rchild==NULL)++leaf;//����ýڵ�û������������������Ҷ�ӽڵ�
    leafs(bt->lchild);
    leafs(bt->rchild);
    return leaf;                				//�����ۼӵ�Ҷ�ӽڵ����
}

//�����⣺�ı���������
void BiTree::changelr()           				//���ò��������������������       ע�⣺����ֻ��ͬʱ�����������Ľڵ����������
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

    cout<<"���ֱ���"<<endl;
	test.preorder();

	test.inorder();
    test.postorder();
/*
	test.leverorder();

    cout<<"���ֹ��ܺ���"<<endl;
    cout<<"leaf nums :"<<test.leafs()<<endl;;
	cout<<"depth of \""<<loc<<"\" is "<<test.depth(loc)<<endl;;
    cout<<"��������������"<<endl;
    cout<<"�任ǰ��"<<endl;
    test.leverorder();
	test.changelr();
	cout<<"�任��"<<endl;
	test.leverorder();
	*/
	return 0;
}
