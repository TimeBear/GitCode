#include<iostream>
#include <fstream>
#include <cstdlib>
#include<string>
using namespace std;
struct Bi_Node{
	char data;                  //数据域，存放该节点的数据
	Bi_Node *lchild=NULL;       //左指针域，存放指向做孩子的指针，当左孩子不存在时为空指针
	Bi_Node *rchile=NULL;       //右指针域，.......
};

class reset{
	Bi_Node *root=NULL;//根节点
	Bi_Node *Front=NULL;//储存前序序列
	Bi_Node *Mid=NULL;//储存中序序列
public:
	reset(string a,string b);           //构造函数传入前序序列，中序序列，序列长度
	Bi_Node* childRoot(int Flo,int Fhi,int Mlo,int Mhi);//还原方法
	void postOrder(Bi_Node *bt);//后序遍历验证
};

reset::reset(string a,string b){        //构造函数
	int length=a.length();
	Front=new Bi_Node[length];          //前序数组的建立
	Mid=new Bi_Node[length];            //后续数组的建立
	for(int i=0;i<length;i++){          //存放数据
		Front[i].data=a[i];
		Mid[i].data=b[i];
	}
	root=childRoot(0,length-1,0,length-1);
	postOrder(root);
}

Bi_Node* reset::childRoot(int Flo,int Fhi,int Mlo,int Mhi){
	if(Flo!=Fhi){
		int mid=Mlo;        //中序序列的工作数字
		while(Front[Flo].data!=Mid[mid].data)           //找根节点
			mid++;
		if(mid-1>=Mlo)              //  前小     前高     中小  中高
			Front[Flo].lchild=childRoot(Flo+1,Flo+mid-Mlo,Mlo,mid-1);
		if(mid+1<=Mhi)
			Front[Flo].rchile=childRoot(Flo+mid-Mlo+1,Fhi,mid+1,Mhi);
	}
	return &Front[Flo];
}

void reset::postOrder(Bi_Node *bt){
	if(bt==NULL) return;
	else{
		postOrder(bt->lchild);
		postOrder(bt->rchile);
		cout<<bt->data<<'\t';
	}
}

int main(){
	string a,b;
	ifstream infile("data.txt",ios::in);
	if(!infile)
	{
		cerr<<"error!";
		exit(1);
	}
	getline(infile,a);
	getline(infile,b);
	reset test(a,b);
}

