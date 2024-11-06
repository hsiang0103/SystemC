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
    List &operator=(const List &);
    List operator+(const List &);
    int setLength(unsigned int);
    unsigned int getLength();
    int setElement(unsigned int , long );
    long getElement(unsigned int );
    friend ostream& operator<<(ostream &, List);
};