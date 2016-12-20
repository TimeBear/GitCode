#include <iostream>
#include <memory.h>
using namespace std;

bool *isvisted; //bool�ͱ���


struct element
{
    int weight;
    int lchild,rchild,parent;
};

void select(element huffTree[],int *i1,int *i2,int n);



void show(element huffTree[],int n) //�������
{

    for(int i=0;i<2*n-1;i++)
        cout<<i<<'\t'<<huffTree[i].weight<<'\t'<<huffTree[i].parent<<'\t'<<huffTree[i].lchild<<'\t'<<huffTree[i].rchild<<endl;
}

void HuffmanTree(element huffTree[],int w[],int n)      //�������㷨
{
    for(int i=0;i<2*n-1;i++)    //��ʼ�������нڵ��û��˫�ף�����
    {
        huffTree[i].parent=-1;
        huffTree[i].lchild=-1;
        huffTree[i].rchild=-1;

    }
    for (int i=0;i<n;i++)
        huffTree[i].weight=w[i];

    int i1,i2;
    int nn=n;

    for(int k=n;k<2*n-1;k++)
    {
        select(huffTree,&i1,&i2,k);
        cout<<"i1 "<<i1<<" i2 "<<i2<<endl;
        huffTree[i1].parent=k;
        huffTree[i2].parent=k;
        huffTree[k].weight=huffTree[i1].weight+huffTree[i2].weight;
        huffTree[k].lchild=i1;
        huffTree[k].rchild=i2;
    }
}


int main()
{
    int n;
    cout<<"input num n:"<<endl;
    cin>>n;
    int *w;
    w=new int[n];
    cout<<"input weight:"<<endl;
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<"input done!"<<endl;
    element *huffman;
    huffman=new element[2*n-1];

isvisted=new bool[2*n-1];
memset(isvisted,0,sizeof(isvisted));

    HuffmanTree(huffman,w,n);
    show(huffman,n);
    return 0;
}

//����Ȩֵ��С���������ڵ㣬�±�Ϊi1��i2
void select(element huffTree[],int *i1,int *i2,int n)
{

    int min1=0,min2=0;
    cout<<"min1 is vited? "<<isvisted[min1]<<endl;
    while(isvisted[min1])min1++;
    for(int i=0;i<n;i++)
    {
        if(huffTree[min1].weight>huffTree[i].weight&&!isvisted[i])min1=i;
    }
    //�������С��min1
    isvisted[min1]=1;

    while(min1==min2||isvisted[min2])min2++;

    for(int i=0;i<n;i++)
    {
        if(huffTree[min2].weight>huffTree[i].weight&&!isvisted[i])min2=i;
    }
    isvisted[min2]=1;

    *i1=min1;
    *i2=min2;
    cout<<"n="<<n<<endl;
}

