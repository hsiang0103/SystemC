#include <iostream>
#include <List.h>
using namespace std;

List::List() : Node(), length(0) {}

List::List(unsigned int _length) : Node(_length), length(_length) {}

List::List(const List &other) : Node(), length(other.length)
{
    if (other._Node)
    {
        _Node = new long[length];
        for (int i = 0; i < length; i++)
        {
            _Node[i] = other._Node[i];
        }
    }
    else
    {
        _Node = nullptr;
    }
}

List::~List()
{
    length = 0;
}

List &List::operator=(const List &other)
{
    delete[] _Node;
    length = other.length;
    if (other._Node)
    {
        _Node = new long[length];
        for (int i = 0; i < length; i++)
        {
            _Node[i] = other._Node[i];
        }
    }
    else
    {
        _Node = nullptr;
    }
    return *this;
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
        cout << "error message" << endl;
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
        cout << "error message" << endl;
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
        cout << "error message" << endl;
        return -99999;
    }
}
