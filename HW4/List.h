#ifndef List_h
#define List_h
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class List : public Node<T>
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
    int setElement(unsigned int, T);
    T getElement(unsigned int);
    List &operator=(const List &);
    bool operator==(const List &);
    template <class U>
    friend ostream &operator<<(ostream &out, List<U> list);
    template <class V>
    friend istream &operator>>(istream &in, List<V> &list);
};
#endif
