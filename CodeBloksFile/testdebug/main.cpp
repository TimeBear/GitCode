#include <iostream>

using namespace std;

int main()
{
    int  n;
    double a, e;
    e = 1;
    a = n = 1;
    while(1/a >= 1e-10)
    {
        e+=1/a;
        n++;
        a *= n;
    }
    cout<<e<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
