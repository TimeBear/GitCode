//�����ڽӾ���ʵ��ͼ�Ĵ洢������dfs,bfs�������㷨ʵ��ͼ�ı������� 
#include <iostream>
using namespace std;
const int n=6;            //������ඥ�����
bool visited[10]={0};     //�ж϶����Ƿ��ѷ��ʹ� 
struct GNode
{
	int num; 
};
class Graph
{
	private:
		struct GNode V[n];   //��������Ϣ 
		int arc[n][n];        //�����űߵ���Ϣ
		int VertexNum,ArcNum;     //��Ŷ������ͱ���
		int front,rear,Q[6];           //bfs�㷨�洢�����ڶ���Q�� 
	public:
		Graph();                         //Ĭ�Ϲ��캯��
		Graph(struct GNode a[],int n,int e);        //����n������e���ߵ�ͼ
		~Graph() {}                    //��������Ϊ��
		void DFSTraverse(int v);      //���ű���
		void BFSTraverse(int v);     //���ű��� 
};
Graph::Graph(struct GNode a[],int m,int e)
{
	VertexNum=m;     //����������
	ArcNum=e;        //��������
	int i;
	for(i=0;i<VertexNum;i++)    //�����Ŵ��� 
	   V[i]=a[i];
	int j;	
	for(j=0;j<VertexNum;j++)     //��ʼ���ڽӾ��� 
	{
		for(int k=0;k<VertexNum;k++)
		   {
		   	  arc[j][k]=0;
		   }
	}
	for(int l=0;l<ArcNum;l++)    //��������ÿһ���� 
	{
	   cout<<"����Դ����ײ���ʾ�����"<<l+1<<"���������������������ţ�"<<'\n';	
	   cin>>i>>j;             //������������Ķ����������� 
	   arc[i][j]=1;           //���б߱�־ 
	   arc[j][i]=1;         	
    }
} 
void Graph::DFSTraverse(int v)
{
	cout<<V[v].num<<'\t';   //����˿̶�����
	visited[v]=1;           //���ʺ���1
	for(int i=0;i<VertexNum;i++)
	{
	   if(arc[v][i]==0 && visited[i]==0)
	   DFSTraverse(i);	
	}	
}
void Graph::BFSTraverse(int v)
{
	front=rear=-1; 
//	cout<<"Ӧ��bfs�˿�Ҫ��ӵĶ���Ϊ��\n";         //���г�ʼ��
	cout<<V[v].num<<'\t';
	Q[++rear]=v;           //�����ʶ������ 
	visited[v]=1;
	while(front!=rear)
	{
	   v=Q[++front];
	   int i=0;
	   for(i=0;i<VertexNum;i++)
	   {
	      if(arc[v][i]==1 && visited[i]==0)
		  {
		  	cout<<V[i].num<<'\t';
		  	visited[i]=1;
		  	Q[++rear]=i;
		  }	
	   }	
    }
	 
} 
int main()
{
  struct GNode b[6];
  for(int i=0;i<6;i++)
  b[i].num=i;
  int e=9;   //����
  Graph Gobj1(b,n,e);
  cout<<"dfs���ͼ���Ϊ��\n";
  Gobj1.DFSTraverse(0);	
  int j;
  for(j=0;j<10;j++)
    visited[j]=0;
  cout<<"\nbfs���ͼ���Ϊ��\n";
  Gobj1.BFSTraverse(0); 
  return 0;	
}
/*ͼ�бߵ�������ϵ����:6�����������ǣ�0-5*/
/*01 04 05 12 23 24 34 35 45����9�������뼴��*/ 
