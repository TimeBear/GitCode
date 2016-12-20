
//应用邻接表实现无向图的存储，应用bfs、dfs实现图的遍历
#include <iostream>
using namespace std;
const int n=5;
bool visited[n]={0};
struct  VNode           //顶点表结点 
{
	char name;             //数据域，存放顶点信息 
	//int index;          //存放定点编号信息 
	struct ENode *firstedge;      //指向边表结点 
}; 
struct ENode            //边表结点 
{
	int v;             //存放顶点的邻接点信息
	//int weight;          //留作带权值边使用
	struct ENode *next;      //指向边表的下一个结点     
}; 
class ALGraph
{
	private:
		struct VNode ALlist[n];      //存放顶点表的数组
		int vertexnum,arcnum;        //图的顶点数目和边的数目 
	    int front,rear;              //作为bfs的存储结构 
	    int Q[5];
	public:
	    ALGraph(VNode a[],int v,int e);      //建立n个顶点,e条边的图
		~ALGraph();                 //析构，释放邻接表中各边表结点的存储空间
		void dfs(int index);        //深优遍历
		void bfs(int index);        //广优遍历 
}; 
ALGraph::ALGraph(VNode a[],int v,int e)
{
	vertexnum=v;arcnum=e;          
	int i;
	for(i=0;i<vertexnum;i++)            //传入顶点信息，并初始化表 
	{
	    ALlist[i]=a[i];
		ALlist[i].firstedge=NULL;	
	}     
	int k,j;
	for(k=0;k<arcnum;k++)        //依次输入每一条边 
	{
		cout<<"请按照原码最下方提示输入边所依附的两个顶点编号：\n";
		cin>>i>>j;            //输入边所依附的两个顶点编号 
		struct ENode *s=new struct ENode;       //生成边表结点s 
		s->v=j;
		s->next=ALlist[i].firstedge;         //将结点s插入到第i个边表的表头
		ALlist[i].firstedge=s; 
	}
} 
ALGraph::~ALGraph()
{
	for(int i=0;i<vertexnum;i++)
	{
		struct ENode *p;
		p=ALlist[i].firstedge;
		while(p!=NULL)
		{
			ALlist[i].firstedge=p->next;
			delete p;
			p=ALlist[i].firstedge;
		} 
	}
} 
void ALGraph::dfs(int index)
{
	cout<<ALlist[index].name<<'\t';
	visited[index]=1;
	struct ENode *p;
	p=ALlist[index].firstedge;       //工作指针p指向顶点index的边表
	while(p!=NULL)
	{
		int j;
		j=p->v;
		if(visited[j]==0) dfs(j);
		p=p->next;
	} 
}
void ALGraph::bfs(int index)
{
	front=rear=-1;
	cout<<ALlist[index].name<<'\t';
	visited[index]=1;
	Q[++rear]=index;     //被访问顶点入队
	while(front!=rear)
	{
	  index=Q[++front];
	  struct ENode *p;
	  p=ALlist[index].firstedge;       //工作指针p指向顶点index的边表
	  while(p!=NULL)
	  {
	    int j;
		j=p->v;
		if(visited[j]==0)
		{
		    cout<<ALlist[j].name<<'\t';
		 	visited[j]=1;
		 	Q[++rear]=j;
		}	
		p=p->next;
	  } 	
	} 
}
int main()
{
	struct VNode a[5]; 
	a[0].name='A';a[1].name='B';a[2].name='C';a[3].name='D';a[4].name='E';
	ALGraph test1(a,5,4);
	test1.dfs(0);
//	test1.bfs(0);  //若用广优，开启此行并关闭上面一行 
	return 0;
}
/*图的结构如下所示：01 12 03 34,*/ 
