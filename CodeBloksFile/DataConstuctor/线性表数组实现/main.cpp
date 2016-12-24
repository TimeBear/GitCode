#include <iostream>

using namespace std;

const int MaxSize = 100;

class SeqList
{
public:
    SeqList(){length = 0;}
    //无参构造函数，建立一个空的顺序表；

    SeqList(int a[], int n);
    //有参构造函数，建立一个长度为n的顺序表

    ~SeqList(){ }
    //析构函数为空

    int Length(){return length;};
    //求线性表的长度

    int Get(int i);
    //按位查找，在线性表中查找第i个元素

    int Locate(int x);
    //按值查找，在线性表中查找值为x的元素序号

    void Insert(int i, int x);
    //插入操作，在线性表中第i个位置插入值为x的元素

    int Delete(int i);
    //删除操作，删除线性表的第i个元素

    void PrintList();
    //便利操作，按序号依次输出各元素
private:
    int data[MaxSize];
    //存放数组元素的数组

    int length;
    //线性表的长度
};

SeqList::SeqList(int a[], int n)    //顺序表有参构造函数
{
    if (n > MaxSize) throw "参数非法";
    int i = 0;
    for (i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}

int SeqList::Get(int i)     //顺序表按位查找
{
    if (i < 1 && i > length) throw "查找位置非法";
    //此时认为所需查找的数据的起始序号是从一开始的
    else
        return data[i - 1];
}

int SeqList::Locate(int x)   //顺序表按值查找
{
    int i = 0;
    for (i = 0; i <length; i++)
        if(data[i] == x)
            return i + 1;       //返回的是数据是从1开始计数的，不是数组的下标
    return 0;
}

void SeqList::Insert(int i, int x)          //顺序表插入算法
{
    if(length >= MaxSize) throw "上溢";
    if(i < 1 || i > length + 1) throw "位置";     //此处的i不是数组的下标，而是一组数的排列顺序号
    int j = 0;
    for(j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    length++;
}

int SeqList::Delete(int i)                  //顺序表删除算法
{
    if(length == 0) throw "下溢";
    if(i < 1 || i > length) throw "位置";
    int x = 0;
    x = data[i - 1];            //取出位置i的元素
    int j = 0;
    for(j = i; j < length; j++)
        data[j -1] = data[j];       //此处的j已经为元素所在的数组的下标
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
    int a[10];      //存入表中的数组
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    int n = 10;     //建立长度为n的顺序表
    SeqList test(a, n);
    test.PrintList();
    cout<< "查找第5个元素:"<< test.Get(5)<<endl;
    cout<< "查找元素值为5的序号："<<test.Locate(5)<<endl;
    cout<<endl;
    cout<< "在第一个位置插入数据10"<<endl;
    test.Insert(1, 10);
    test.PrintList();
    cout<< "删除线性表第1个元素"<<endl;
    test.Delete(1);
    test.PrintList();
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
