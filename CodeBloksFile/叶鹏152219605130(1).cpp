//利用邻接矩阵实现图的存储、并用dfs,bfs及回溯算法实现图的遍历操作 
#include <iostream>
using namespace std;
const int n=6;            //储存最多顶点个数
bool visited[10]={0};     //判断顶点是否已访问过 
struct GNode
{
	int num; 
};
class Graph
{
	private:
		struct GNode V[n];   //顶点编号信息 
		int arc[n][n];        //数组存放边的信息
		int VertexNum,ArcNum;     //存放顶点数和边数
		int front,rear,Q[6];           //bfs算法存储顶点在队列Q中 
	public:
		Graph();                         //默认构造函数
		Graph(struct GNode a[],int n,int e);        //建立n个顶点e条边的图
		~Graph() {}                    //析构函数为空
		void DFSTraverse(int v);      //深优遍历
		void BFSTraverse(int v);     //广优遍历 
};
Graph::Graph(struct GNode a[],int m,int e)
{
	VertexNum=m;     //顶点数传入
	ArcNum=e;        //边数传入
	int i;
	for(i=0;i<VertexNum;i++)    //顶点编号传入 
	   V[i]=a[i];
	int j;	
	for(j=0;j<VertexNum;j++)     //初始化邻接矩阵 
	{
		for(int k=0;k<VertexNum;k++)
		   {
		   	  arc[j][k]=0;
		   }
	}
	for(int l=0;l<ArcNum;l++)    //依次输入每一条边 
	{
	   cout<<"按照源代码底部提示输入第"<<l+1<<"条边所依附的两个顶点编号！"<<'\n';	
	   cin>>i>>j;             //输入边所依附的顶点的两个编号 
	   arc[i][j]=1;           //置有边标志 
	   arc[j][i]=1;         	
    }
} 
void Graph::DFSTraverse(int v)
{
	cout<<V[v].num<<'\t';   //输出此刻顶点编号
	visited[v]=1;           //访问后置1
	for(int i=0;i<VertexNum;i++)
	{
	   if(arc[v][i]==0 && visited[i]==0)
	   DFSTraverse(i);	
	}	
}
void Graph::BFSTraverse(int v)
{
	front=rear=-1; 
//	cout<<"应用bfs此刻要入队的顶点为：\n";         //队列初始化
	cout<<V[v].num<<'\t';
	Q[++rear]=v;           //被访问顶点入队 
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
  int e=9;   //边数
  Graph Gobj1(b,n,e);
  cout<<"dfs输出图结果为：\n";
  Gobj1.DFSTraverse(0);	
  int j;
  for(j=0;j<10;j++)
    visited[j]=0;
  cout<<"\nbfs输出图结果为：\n";
  Gobj1.BFSTraverse(0); 
  return 0;	
}
/*图中边的依附关系如下:6个顶点依次是：0-5*/
/*01 04 05 12 23 24 34 35 45将次9条边输入即可*/ 
