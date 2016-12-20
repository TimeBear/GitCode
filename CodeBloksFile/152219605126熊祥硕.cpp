
//Ӧ���ڽӱ�ʵ������ͼ�Ĵ洢��Ӧ��bfs��dfsʵ��ͼ�ı���
#include <iostream>
using namespace std;
const int n=5;
bool visited[n]={0};
struct  VNode           //������� 
{
	char name;             //�����򣬴�Ŷ�����Ϣ 
	//int index;          //��Ŷ�������Ϣ 
	struct ENode *firstedge;      //ָ��߱��� 
}; 
struct ENode            //�߱��� 
{
	int v;             //��Ŷ�����ڽӵ���Ϣ
	//int weight;          //������Ȩֵ��ʹ��
	struct ENode *next;      //ָ��߱����һ�����     
}; 
class ALGraph
{
	private:
		struct VNode ALlist[n];      //��Ŷ���������
		int vertexnum,arcnum;        //ͼ�Ķ�����Ŀ�ͱߵ���Ŀ 
	    int front,rear;              //��Ϊbfs�Ĵ洢�ṹ 
	    int Q[5];
	public:
	    ALGraph(VNode a[],int v,int e);      //����n������,e���ߵ�ͼ
		~ALGraph();                 //�������ͷ��ڽӱ��и��߱���Ĵ洢�ռ�
		void dfs(int index);        //���ű���
		void bfs(int index);        //���ű��� 
}; 
ALGraph::ALGraph(VNode a[],int v,int e)
{
	vertexnum=v;arcnum=e;          
	int i;
	for(i=0;i<vertexnum;i++)            //���붥����Ϣ������ʼ���� 
	{
	    ALlist[i]=a[i];
		ALlist[i].firstedge=NULL;	
	}     
	int k,j;
	for(k=0;k<arcnum;k++)        //��������ÿһ���� 
	{
		cout<<"�밴��ԭ�����·���ʾ����������������������ţ�\n";
		cin>>i>>j;            //����������������������� 
		struct ENode *s=new struct ENode;       //���ɱ߱���s 
		s->v=j;
		s->next=ALlist[i].firstedge;         //�����s���뵽��i���߱�ı�ͷ
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
	p=ALlist[index].firstedge;       //����ָ��pָ�򶥵�index�ı߱�
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
	Q[++rear]=index;     //�����ʶ������
	while(front!=rear)
	{
	  index=Q[++front];
	  struct ENode *p;
	  p=ALlist[index].firstedge;       //����ָ��pָ�򶥵�index�ı߱�
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
//	test1.bfs(0);  //���ù��ţ��������в��ر�����һ�� 
	return 0;
}
/*ͼ�Ľṹ������ʾ��01 12 03 34,*/ 
