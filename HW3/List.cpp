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
    unsigned int loop_length = (this->length < other.length) ? other.length : this->length;
    List temp(loop_length);
    for (unsigned int i = 0; i < loop_length; i++)
    {
        if ((i >= this->length) && (i < loop_length))
        {
            temp._Node[i] = other._Node[i];
            continue;
        }
        if ((i >= other.length) && (i < loop_length))
        {
            temp._Node[i] = this->_Node[i];
            continue;
        }
        temp._Node[i] = this->_Node[i] + other._Node[i];
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
        out << "List contents: ";
        for (unsigned int i = 0; i < list.length; ++i)
        {
            out << list._Node[i] << " ";
        }
    }
    return out;
}
