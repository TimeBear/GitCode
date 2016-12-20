#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;
struct Student1
{
    char name[20];
};
class Student2
{
private:
    Student1 T[100];
    int cou;               //班级人数
    int s;                  //要删去的人的牌号
public:
    Student2();
    void add(char *a, int k);       //a是要增加的人名，k是要插入的位置
    void del(char *b);              //要删除人的名单
    void print();
};
Student2::Student2()
{
    cou = 64;
    ifstream infile("d:\\Name.txt",ios::binary);
    if(!infile)
    {
        cerr<<"打开错误"<<endl;
        abort();
    }
    int i;
    for(i = 0; i < 64; i++)
    {
        infile>>T[i].name;
    }
    infile.close();
}
void Student2::add(char *a, int k)
{
    int  i;
    for(i = cou - 1; i < k - 1; i--)
    {
        strcpy(T[i + 1].name, T[i].name);
    }
    strcpy(T[k - 1].name, a);
}
void Student2::del(char *b)
{
    int i;
    for(i = 0; i < cou; i++)
    {
        if(strcmp(T[i].name, b) == 0)
        {
            s = i;
            break;
        }
    }
    int m ;
    for(m = s; m < cou; m++)
        strcpy(T[m].name, T[m + 1].name);
    //strcpy(T[cou + 1].name, "      ") ;
}
void Student2::print()
{
    cout<<"名单:"<<endl;
    int i;
    for(i = 0; i < cou; i++)
        cout<<T[i].name<<endl;
}
int main()
{
    char a[20];
    int k;
    Student2 Soft;
    cout<<"请输入插入人员的名字和编号"<<endl;
    cin>>a>>k;
    Soft.add(a, k);
    Soft.print();
    cout<<"请输入删除人员的名单"<<endl;
    char b[20];
    cin>>b;
    Soft.del(b);
    Soft.print();
    return 0;
}
