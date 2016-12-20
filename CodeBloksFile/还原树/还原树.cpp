#include<iostream>
#include <fstream>
#include <cstdlib>
#include<string>
using namespace std;
struct Bi_Node{
	char data;                  //�����򣬴�Ÿýڵ������
	Bi_Node *lchild=NULL;       //��ָ���򣬴��ָ�������ӵ�ָ�룬�����Ӳ�����ʱΪ��ָ��
	Bi_Node *rchile=NULL;       //��ָ����.......
};

class reset{
	Bi_Node *root=NULL;//���ڵ�
	Bi_Node *Front=NULL;//����ǰ������
	Bi_Node *Mid=NULL;//������������
public:
	reset(string a,string b);           //���캯������ǰ�����У��������У����г���
	Bi_Node* childRoot(int Flo,int Fhi,int Mlo,int Mhi);//��ԭ����
	void postOrder(Bi_Node *bt);//���������֤
};

reset::reset(string a,string b){        //���캯��
	int length=a.length();
	Front=new Bi_Node[length];          //ǰ������Ľ���
	Mid=new Bi_Node[length];            //��������Ľ���
	for(int i=0;i<length;i++){          //�������
		Front[i].data=a[i];
		Mid[i].data=b[i];
	}
	root=childRoot(0,length-1,0,length-1);
	postOrder(root);
}

Bi_Node* reset::childRoot(int Flo,int Fhi,int Mlo,int Mhi){
	if(Flo!=Fhi){
		int mid=Mlo;        //�������еĹ�������
		while(Front[Flo].data!=Mid[mid].data)           //�Ҹ��ڵ�
			mid++;
		if(mid-1>=Mlo)              //  ǰС     ǰ��     ��С  �и�
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

