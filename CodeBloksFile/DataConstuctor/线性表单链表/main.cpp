#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkList
{
public:
    LinkList();             //�޲ι��캯��������ֻ��ͷ���Ŀ�����
    LinkList(int a[], int n);   //
    ~LinkList();
    int Length();
    int Get(int i);
    int Locate(int x);
    void Insert(int i, int x);
    int Delete(int i);
    void PrintList();
private:
    Node *first;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
