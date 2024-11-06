#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List *a = new List(3);
    a->setElement(0, 2);
    a->setElement(1, 9);
    a->setElement(2, 12);

    List *c = new List(5);
    c->setElement(0, 2);
    c->setElement(1, 9);
    c->setElement(2, 12);
    c->setElement(3, 22);
    c->setElement(4, 48);
    cout << "+ test" << endl;
    List result = *c + *a;
    cout << result << endl;
    cout << result << endl;
    return 0;
}