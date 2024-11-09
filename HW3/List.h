#include <iostream>
#include "Node.h"
using namespace std;

class List : public Node
{
protected:
    unsigned int length;

public:
    List();
    List(unsigned int);
    List(const List &);
    ~List();
    int setLength(unsigned int);
    unsigned int getLength();
    int setElement(unsigned int, long);
    long getElement(unsigned int);
    friend ostream &operator<<(ostream &, List);
    friend istream &operator>>(istream &, List &);
    List &operator=(const List &);  // copy 1 list to another
    List operator+(const List &);   // 2 lists elementwise adda
    List operator++();              // predix  elementwise + 1
    List operator++(int);           // postfix elementwise + 1
    List &operator+=(const List &); // merge 2 lists to 1 list
    List operator--();              // predix  elementwise - 1
    List operator--(int);           // postfix elementwise - 1
};