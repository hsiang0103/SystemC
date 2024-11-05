#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &refa = a;
    
    int *aptr;
    aptr = &a;
    (*aptr)++;
    
    refa++;
    cout << a << ", " << refa << endl;
}
