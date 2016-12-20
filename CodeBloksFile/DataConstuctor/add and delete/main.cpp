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
    int cou;               //�༶����
    int s;                  //Ҫɾȥ���˵��ƺ�
public:
    Student2();
    void add(char *a, int k);       //a��Ҫ���ӵ�������k��Ҫ�����λ��
    void del(char *b);              //Ҫɾ���˵�����
    void print();
};
Student2::Student2()
{
    cou = 64;
    ifstream infile("d:\\Name.txt",ios::binary);
    if(!infile)
    {
        cerr<<"�򿪴���"<<endl;
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
    cout<<"����:"<<endl;
    int i;
    for(i = 0; i < cou; i++)
        cout<<T[i].name<<endl;
}
int main()
{
    char a[20];
    int k;
    Student2 Soft;
    cout<<"�����������Ա�����ֺͱ��"<<endl;
    cin>>a>>k;
    Soft.add(a, k);
    Soft.print();
    cout<<"������ɾ����Ա������"<<endl;
    char b[20];
    cin>>b;
    Soft.del(b);
    Soft.print();
    return 0;
}
