#include <iostream>

using namespace std;

void InsertSort(int r[], int n)
{
    int i = 0;
    int j = 0;
    int temp;
    for(i = 2; i <= n; i++)
    {
        temp = r[i];
        for(j = i - 1; temp < r[j]; j--)
            r[j + 1] = r[j];
        r[j + 1] = temp;
    }
}

int main()
{
    int r[6] = {0, 5, 11, 4, 40, 7};
    int n = 6;
    InsertSort(r, n);
    int i = 0;
    for(i = 1; i < 6; i++)
    {
        cout<<r[i]<< '\t';
    }
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
