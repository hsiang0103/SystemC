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

template class List<int>;
template class List<double>;
template class List<char>;
template class List<string>;

template <class T>
ostream &operator<<(ostream &out, List<T> list)
{
    if (list.length == 0)
    {
        out << "List is empty.";
    }
    else
    {
        for (unsigned int i = 0; i < list.length; i++)
        {
            out << list._Node[i] << " ";
        }
    }
    return out;
}

template <class T>
istream &operator>>(istream &in, List<T> &list)
{
    unsigned int new_length;
    in >> new_length;
    if (list.length == 0)
    {
        list.setLength(new_length);
    }
    for (unsigned int i = 0; i < list.length; i++)
    {
        T value;
        in >> value;
        list.setElement(i, value);
    }
    return in;
}
#endif
