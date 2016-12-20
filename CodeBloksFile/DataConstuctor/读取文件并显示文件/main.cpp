#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;
struct Student1
{
    char num[20];       //学号
    char name[20];      //姓名
    int english;        //英语
    int math;           //数学
    int c;              //C++
    int xinli;          //心里健康
};
class Student2
{
private:
    Student1 T[64];
public:
    Student2();
    void print();
};
Student2::Student2()
{
    ifstream infile("d:\\SF.txt",ios::binary);
    if(!infile)
    {
        cerr<<"打开错误"<<endl;
        abort();
    }
    int i;
    for(i = 0; i < 64; i++)
    {
        infile>>T[i].num>>T[i].name>>T[i].english
        >>T[i].math>>T[i].c>>T[i].xinli;
    }
    infile.close();
}
void Student2::print()
{
    cout<<"成绩"<<endl;
    cout<<setw(15)<<"学号"<<setw(7)<<"姓名"<<setw(6)<<"英语"
    <<setw(6)<<"数学"<<setw(6)<<"C++"<<setw(6)<<"心里"<<endl;
    int i;
    for(i = 0; i < 64; i++)
    {
        cout<<setw(15)<<T[i].num<<setw(8)<<T[i].name<<setw(5)<<T[i].english
        <<setw(5)<<T[i].math<<setw(5)<<T[i].c<<setw(5)<<T[i].xinli<<endl;
    }
}
int main()
{
    Student2 Soft;
    Soft.print();
    return 0;
}
