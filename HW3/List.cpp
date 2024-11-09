#include <iostream>
#include "List.h"
using namespace std;

List::List() : Node(), length(0) {}

List::List(unsigned int _length) : Node(_length), length(_length) {}

List::List(const List &other) : Node()
{
    length = other.length;
    if (length > 0)
    {
        _Node = new long[length];
        for (unsigned int i = 0; i < length; i++)
        {
            _Node[i] = other._Node[i];
        }
    }
    else
    {
        _Node = NULL;
    }
}

List::~List()
{
    if (length != 0)
    {
        length = 0;
    }
}

List &List::operator=(const List &other)
{
    if (this != &other)
    {
        delete[] _Node;
        length = other.length;
        if (length > 0)
        {
            _Node = new long[length];
            for (unsigned int i = 0; i < length; i++)
            {
                _Node[i] = other._Node[i];
            }
        }
    }
    else
    {
        _Node = nullptr;
    }
    return *this;
}

List List::operator+(const List &other)
{
    unsigned int loop_length = (length < other.length) ? other.length : length;
    List temp(loop_length);
    for (unsigned int i = 0; i < loop_length; i++)
    {
        if ((i >= length) && (i < loop_length))
        {
            temp._Node[i] = other._Node[i];
            continue;
        }
        if ((i >= other.length) && (i < loop_length))
        {
            temp._Node[i] = _Node[i];
            continue;
        }
        temp._Node[i] = _Node[i] + other._Node[i];
    }
    return temp;
}

List &List::operator+=(const List &other)
{
    unsigned int new_length = length + other.length;
    List temp(new_length);
    unsigned int i;
    for (i = 0; i < length; i++)
    {
        temp._Node[i] = this->_Node[i];
    }
    for (; i < new_length; i++)
    {
        temp._Node[i] = other._Node[i - length];
    }
    *this = temp;
    return *this;
}

List List::operator++()
{
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]++;
    }
    return *this;
}

List List::operator++(int)
{
    List temp(*this);
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]++;
    }
    return temp;
}

List List::operator--()
{
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]--;
    }
    return *this;
}

List List::operator--(int)
{
    List temp(*this);
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]--;
    }
    return temp;
}

int List::setLength(unsigned int new_length)
{
    if (length == 0)
    {
        length = new_length;
        _Node = reCreate(length);
        return 1;
    }
    else
    {
        cout << "Error!! length != 0" << endl;
        return 0;
    }
}

unsigned int List::getLength()
{
    return length;
}

int List::setElement(unsigned int pos, long val)
{
    if (pos < length)
    {
        _Node[pos] = val;
        return 1;
    }
    else
    {
        cout << "Error!! Position larger than length" << endl;
        return 0;
    }
}

long List::getElement(unsigned int pos)
{
    if (pos < length)
    {
        return _Node[pos];
    }
    else
    {
        cout << "Error!! Position larger than length" << endl;
        return -99999;
    }
}

ostream &operator<<(ostream &out, List list)
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

istream &operator>>(istream &in, List &list)
{
    unsigned int new_length;
    in >> new_length;
    if (list.length == 0)
    {
        list.setLength(new_length);
    }
    for (unsigned int i = 0; i < list.length; i++)
    {
        long value;
        in >> value;
        list.setElement(i, value);
    }
    return in;
}
