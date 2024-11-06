#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List *a = new List(3);
    cout << a->getLength() << endl;
}