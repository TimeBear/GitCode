#include <iostream>

using namespace std;

const int MaxSize = 100;

class SeqList
{
public:
    SeqList(){length = 0;}
    //�޲ι��캯��������һ���յ�˳���

    SeqList(int a[], int n);
    //�вι��캯��������һ������Ϊn��˳���

    ~SeqList(){ }
    //��������Ϊ��

    int Length(){return length;};
    //�����Ա�ĳ���

    int Get(int i);
    //��λ���ң������Ա��в��ҵ�i��Ԫ��

    int Locate(int x);
    //��ֵ���ң������Ա��в���ֵΪx��Ԫ�����

    void Insert(int i, int x);
    //��������������Ա��е�i��λ�ò���ֵΪx��Ԫ��

    int Delete(int i);
    //ɾ��������ɾ�����Ա�ĵ�i��Ԫ��

    void PrintList();
    //������������������������Ԫ��
private:
    int data[MaxSize];
    //�������Ԫ�ص�����

    int length;
    //���Ա�ĳ���
};

SeqList::SeqList(int a[], int n)    //˳����вι��캯��
{
    if (n > MaxSize) throw "�����Ƿ�";
    int i = 0;
    for (i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

int SeqList::Get(int i)     //˳���λ����
{
    if (i < 1 && i > length) throw "����λ�÷Ƿ�";
    //��ʱ��Ϊ������ҵ����ݵ���ʼ����Ǵ�һ��ʼ��
    else
        return data[i - 1];
}

int SeqList::Locate(int x)   //˳���ֵ����
{
    int i = 0;
    for (i = 0; i <length; i++)
        if(data[i] == x)
            return i + 1;       //���ص��������Ǵ�1��ʼ�����ģ�����������±�
    return 0;
}

void SeqList::Insert(int i, int x)          //˳�������㷨
{
    if(length >= MaxSize) throw "����";
    if(i < 1 || i > length + 1) throw "λ��";     //�˴���i����������±꣬����һ����������˳���
    int j = 0;
    for(j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    length++;
}

int SeqList::Delete(int i)                  //˳���ɾ���㷨
{
    if(length == 0) throw "����";
    if(i < 1 || i > length) throw "λ��";
    int x = 0;
    x = data[i - 1];            //ȡ��λ��i��Ԫ��
    int j = 0;
    for(j = i; j < length; j++)
        data[j -1] = data[j];       //�˴���j�Ѿ�ΪԪ�����ڵ�������±�
    length--;
    return x;
}

void SeqList::PrintList()
{
    int i = 0;
    for(i = 0; i < length; i++)
        cout<< data[i]<<endl;
    cout<<endl;
}
int main()
{
    int a[10];      //������е�����
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    int n = 10;     //��������Ϊn��˳���
    SeqList test(a, n);
    test.PrintList();
    cout<< "���ҵ�5��Ԫ��:"<< test.Get(5)<<endl;
    cout<< "����Ԫ��ֵΪ5����ţ�"<<test.Locate(5)<<endl;
    cout<<endl;
    cout<< "�ڵ�һ��λ�ò�������10"<<endl;
    test.Insert(1, 10);
    test.PrintList();
    cout<< "ɾ�����Ա��1��Ԫ��"<<endl;
    test.Delete(1);
    test.PrintList();
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
