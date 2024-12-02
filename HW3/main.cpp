#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in;
    ofstream out;
    string filename = argv[1];

    in.open(filename);
    if (!in.is_open())
    {
        cout << "cannot open file." << endl;
    }
    out.open("RESULT");
    if (!out.is_open())
    {
        cout << "cannot open file." << endl;
    }

    List *list_1 = new List();
    out << "Instantiate list_1" << endl;
    out << "list_1 :" << *list_1 << "\n";
    in >> *list_1;
    out << "list_1 get the input file" << endl;
    out << "list_1 :" << *list_1 << "\n\n";

    List *list_2 = new List(*list_1);
    out << "Instantiate list_2 copied by copy constructor" << endl;
    out << "list_2 :" << *list_2 << "\n\n";

    List *list_3 = new List();
    out << "Instantiate list_3" << endl;
    out << "list_3 :" << *list_3 << "\n";
    *list_3 = *list_1;
    out << "list_3 copied by operator =" << endl;
    out << "list_3 :" << *list_3 << "\n\n";

    List *list_4 = new List();
    out << "Instantiate list_4" << endl;
    out << "list_4 :" << *list_4 << "\n";
    *list_4 = *list_4 + *list_1;
    out << "list_4 copied by operator +" << endl;
    out << "list_4 :" << *list_4 << "\n\n";

    out << "Add two of the Lists using operator+ " << endl;
    out << "list_1 + list_2 : " << *list_1 + *list_2 << "\n\n";

    out << "Use operator++ to add 1 to a List  " << endl;
    out << "list_1++ : " << (*list_1)++ << "\n";
    out << "list_1   : " << *list_1 << "\n\n";

    out << "Use operator++(int) to add 1 to a List " << endl;
    out << "++list_1 : " << ++(*list_1) << "\n";
    out << "list_1   : " << *list_1 << "\n\n";

    out << "Use operator+= to add another List to a List" << endl;
    out << "define += for concat two List" << endl;
    out << "list_1 += list_2 : " << (*list_1 += *list_2) << "\n\n";

    out << "Use operator-- to subtract 1 from all elements in a List" << endl;
    out << "list_1-- : " << (*list_1)-- << "\n";
    out << "list_1   : " << *list_1 << "\n\n";

    out << "Use operator--(long) to subtract 1 from all elements in a List " << endl;
    out << "--list_1 : " << --(*list_1) << "\n";
    out << "list_1   : " << *list_1 << "\n\n";

    List *list_5 = new List();
    out << "Instantiate list_5" << endl;
    out << "list_5 :" << *list_5 << "\n\n";

    out << "set length test" << endl;
    list_1->setLength(6);
    list_5->setLength(6);
    out << "get length test" << endl;
    out << "list_5 length = " << list_5->getLength() << "\n\n";

    out << "Set element test" << endl;
    list_5->setElement(0, 100);
    list_5->setElement(1, 0);
    list_5->setElement(2, -100);
    list_5->setElement(3, 10);
    list_5->setElement(4, 22);
    list_5->setElement(5, 69);
    list_5->setElement(6, -123); // no change
    out << "list_5   : " << *list_5 << "\n\n";

    out << "get element test\n";
    out << "list_5   : ";
    for (unsigned int i = 0; i <= list_5->getLength(); i++)
    {
        out << list_5->getElement(i) << " ";
    }
    out << "\n-99999 represent position is over list length";

    cout << "\nAll result has written in RESULT" << endl;
    return 0;
}