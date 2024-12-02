#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "List.cpp"
#include "Node.h"
#include "Node.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    ifstream in_d, in_s;
    ofstream out;
    string filename_d = argv[1];
    string filename_s = argv[2];
    if (argc != 3)
    {
        cout << "Error!! too mant input file" << endl;
        return 0;
    }

    in_d.open(filename_d);
    if (!in_d.is_open())
    {
        cout << "cannot open input file " << filename_d << endl;
    }
    in_s.open(filename_s);
    if (!in_s.is_open())
    {
        cout << "cannot open input file " << filename_s << endl;
    }
    out.open("RESULT");
    if (!out.is_open())
    {
        cout << "cannot open coutput file " << endl;
    }
    cout << boolalpha;
    cout << boolalpha;

    cout << "=====================" << endl;
    cout << "==== double test ====" << endl;
    cout << "=====================" << "\n\n";
 




    List<double> *list_d1 = new List<double>();
    cout << "Instantiate list_d1\nlist_d1 : " << *list_d1 << "\n\n";
    in_d >> *list_d1;
    cout << "Read list_d1 from input\nlist_d1 : " << *list_d1 << "\n\n";

    List<double> *list_d2 = new List<double>(*list_d1);
    cout << "Instantiate list_d2 by copy list_d1\nlist_d2 : " << *list_d2 << "\n\n";

    List<double> *list_d3 = new List<double>();
    cout << "Instantiate list_d3\nlist_d3 : " << *list_d3 << "\n\n";
    list_d3->setLength(4);
    list_d3->setElement(0, 5.1);
    list_d3->setElement(1, -52.3);
    list_d3->setElement(2, 12.13);
    list_d3->setElement(3, 0.002);
    cout << "Assign some element to list_d3\nlist_d3 : " << *list_d3 << "\n\n";

    List<double> *list_d4 = new List<double>();
    list_d4->setLength(3);
    list_d4->setElement(0, list_d3->getElement(0));
    list_d4->setElement(1, list_d3->getElement(1));
    list_d4->setElement(2, list_d3->getElement(2));
    cout << "Make a list_d4 similar to list_d3\nlist_d4 : " << *list_d4 << "\n\n";

    cout << "Result" << endl;
    cout << "list_d1 : " << *list_d1 << endl;
    cout << "list_d2 : " << *list_d2 << endl;
    cout << "list_d3 : " << *list_d3 << endl;
    cout << "list_d4 : " << *list_d4 << endl;
    cout << "Is list_d1 == list_d2 : " << (*list_d1 == *list_d2) << endl;
    cout << "Is list_d1 == list_d3 : " << (*list_d1 == *list_d3) << endl;
    cout << "Is list_d1 == list_d4 : " << (*list_d1 == *list_d4) << endl;
    cout << "Is list_d2 == list_d3 : " << (*list_d2 == *list_d3) << endl;
    cout << "Is list_d2 == list_d4 : " << (*list_d2 == *list_d4) << endl;
    cout << "Is list_d3 == list_d4 : " << (*list_d3 == *list_d4) << "\n\n";

    cout << "=====================" << endl;
    cout << "==== string test ====" << endl;
    cout << "=====================" << "\n\n";
    List<string> *list_s1 = new List<string>();
    cout << "Instantiate list_s1\nlist_s1 : " << *list_s1 << "\n\n";
    in_s >> *list_s1;
    cout << "Read list_s1 from input\nlist_s1 : " << *list_s1 << "\n\n";

    List<string> *list_s2 = new List<string>();
    cout << "Instantiate list_s2\nlist_s2 : " << *list_s2 << "\n\n";
    *list_s2 = *list_s1;
    cout << "Assign list_s1 to list_s2\nlist_s2 : " << *list_s2 << "\n\n";

    List<string> *list_s3 = new List<string>();
    cout << "Instantiate list_s3\nlist_s3 : " << *list_s3 << "\n\n";
    list_s3->setLength(4);
    list_s3->setElement(0, "SystemC");
    list_s3->setElement(1, "is");
    list_s3->setElement(2, "not");
    list_s3->setElement(3, "fun");
    cout << "Assign some element to list_s3\nlist_s3 : " << *list_s3 << "\n\n";

    cout << "Result" << endl;
    cout << "list_s1 : " << *list_s1 << endl;
    cout << "list_s2 : " << *list_s2 << endl;
    cout << "list_s3 : " << *list_s3 << endl;
    cout << "Is list_s1 == list_s2 : " << (*list_s1 == *list_s2) << endl;
    cout << "Is list_s1 == list_s3 : " << (*list_s1 == *list_s3) << endl;
    cout << "Is list_s2 == list_s3 : " << (*list_s2 == *list_s3) << "\n\n";

    cout << "=====================" << endl;
    cout << "===== func test =====" << endl;
    cout << "=====================" << "\n\n";

    List<int> *list_i = new List<int>();
    cout << "set length test" << endl;
    list_i->setLength(6);
    cout << "get length test" << endl;
    cout << "list_i length = " << list_i->getLength() << "\n\n";

    cout << "Set element test" << endl;
    list_i->setElement(0, 100);
    list_i->setElement(1, 0);
    list_i->setElement(2, -100);
    list_i->setElement(3, 10);
    list_i->setElement(4, 22);
    list_i->setElement(5, 69);
    // list_i->setElement(6, -123); // no change
    cout << "list_i   : " << *list_i << "\n\n";

    cout << "get element test\n";
    cout << "list_i   : ";
    for (unsigned int i = 0; i < list_i->getLength(); i++)
    {
        cout << list_i->getElement(i) << " ";
    }
    cout << endl;

    cout << "=====================" << endl;
    cout << "===== type test =====" << endl;
    cout << "=====================" << "\n\n";

    List<float> *list_f = new List<float>();
    list_f->setLength(3);
    list_f->setElement(0, 0);
    list_f->setElement(1, 1.1);
    list_f->setElement(2, -2223.5);
    cout << "float: " << *list_f << "\n\n";
    List<char> *list_c = new List<char>();
    list_c->setLength(3);
    list_c->setElement(0, 'A');
    list_c->setElement(1, 'B');
    list_c->setElement(2, 'C');
    cout << "char: " << *list_c << "\n\n";

    out << "output test" << endl;
    out << "All verification are show in terminal" << endl;
    
    return 0;
}