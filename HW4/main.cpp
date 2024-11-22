#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
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
        cout << "cannot open output file " << endl;
    }
    out << boolalpha;
    cout << boolalpha;

    out << "=====================" << endl;
    out << "==== double test ====" << endl;
    out << "=====================" << "\n\n";
    cout << "=====================" << endl;
    cout << "==== double test ====" << endl;
    cout << "=====================" << "\n\n";

    List<double> *list_d1 = new List<double>();
    out << "Instantiate list_d1\nlist_d1 : " << *list_d1 << "\n\n";
    in_d >> *list_d1;
    out << "Read list_d1 from input\nlist_d1 : " << *list_d1 << "\n\n";

    List<double> *list_d2 = new List<double>(*list_d1);
    out << "Instantiate list_d2 by copy list_d1\nlist_d2 : " << *list_d2 << "\n\n";

    List<double> *list_d3 = new List<double>();
    out << "Instantiate list_d3\nlist_d3 : " << *list_d3 << "\n\n";
    list_d3->setLength(4);
    list_d3->setElement(0, 5.1);
    list_d3->setElement(1, -52.3);
    list_d3->setElement(2, 12.13);
    list_d3->setElement(3, 0.002);
    out << "Assign some element to list_d3\nlist_d3 : " << *list_d3 << "\n\n";

    List<double> *list_d4 = new List<double>();
    list_d4->setLength(3);
    list_d4->setElement(0, list_d3->getElement(0));
    list_d4->setElement(1, list_d3->getElement(1));
    list_d4->setElement(2, list_d3->getElement(2));
    out << "Make a list_d4 similar to list_d3\nlist_d4: " << *list_d4 << "\n\n";

    out << "Result" << endl;
    out << "list_d1 : " << *list_d1 << endl;
    out << "list_d2 : " << *list_d2 << endl;
    out << "list_d3 : " << *list_d3 << endl;
    out << "list_d4 : " << *list_d4 << endl;
    out << "Is list_d1 == list_d2 : " << (*list_d1 == *list_d2) << endl;
    out << "Is list_d1 == list_d3 : " << (*list_d1 == *list_d3) << endl;
    out << "Is list_d1 == list_d4 : " << (*list_d1 == *list_d4) << endl;
    out << "Is list_d2 == list_d3 : " << (*list_d2 == *list_d3) << endl;
    out << "Is list_d2 == list_d4 : " << (*list_d2 == *list_d4) << endl;
    out << "Is list_d3 == list_d4 : " << (*list_d3 == *list_d4) << "\n\n";

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

    out << "=====================" << endl;
    out << "==== string test ====" << endl;
    out << "=====================" << "\n\n";
    cout << "=====================" << endl;
    cout << "==== string test ====" << endl;
    cout << "=====================" << "\n\n";
    List<string> *list_s1 = new List<string>();
    out << "Instantiate list_s1\nlist_s1: " << *list_s1 << "\n\n";
    in_s >> *list_s1;
    out << "Read list_s1 from input\nlist_s1: " << *list_s1 << "\n\n";

    List<string> *list_s2 = new List<string>();
    out << "Instantiate list_s2\nlist_s2: " << *list_s2 << "\n\n";
    *list_s2 = *list_s1;
    out << "Assign list_s1 to list_s2\nlist_s2: " << *list_s2 << "\n\n";

    List<string> *list_s3 = new List<string>();
    out << "Instantiate list_s3\nlist_s3 : " << *list_s3 << "\n\n";
    list_s3->setLength(4);
    list_s3->setElement(0, "SystemC");
    list_s3->setElement(1, "is");
    list_s3->setElement(2, "not");
    list_s3->setElement(3, "fun");
    out << "Assign some element to list_s3\nlist_s3 : " << *list_s3 << "\n\n";

    out << "Result" << endl;
    out << "list_s1 : " << *list_s1 << endl;
    out << "list_s2 : " << *list_s2 << endl;
    out << "list_s3 : " << *list_s3 << endl;
    out << "Is list_s1 == list_s2 : " << (*list_s1 == *list_s2) << endl;
    out << "Is list_s1 == list_s3 : " << (*list_s1 == *list_s3) << endl;
    out << "Is list_s2 == list_s3 : " << (*list_s2 == *list_s3) << "\n\n";
    
    cout << "list_s1 : " << *list_s1 << endl;
    cout << "list_s2 : " << *list_s2 << endl;
    cout << "list_s3 : " << *list_s3 << endl;
    cout << "Is list_s1 == list_s2 : " << (*list_s1 == *list_s2) << endl;
    cout << "Is list_s1 == list_s3 : " << (*list_s1 == *list_s3) << endl;
    cout << "Is list_s2 == list_s3 : " << (*list_s2 == *list_s3) << "\n\n";

    return 0;
}