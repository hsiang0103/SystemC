#include <iostream>
#include <assert.h>
#include "List.h"
using namespace std;

template <class T>
List<T>::List() : Node<T>(), length(0) {}

template <class T>
List<T>::List(unsigned int _length) : Node<T>(_length), length(_length) {}

template <class T>
List<T>::List(const List<T> &other) : Node<T>()
{
    length = other.length;
    if (length > 0)
    {
        this->_Node = new T[length];
        for (unsigned int i = 0; i < length; i++)
        {
            this->_Node[i] = other._Node[i];
        }
    }
    else
    {
        this->_Node = NULL;
    }
}

template <class T>
List<T>::~List()
{
    if (length != 0)
    {
        length = 0;
    }
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other)
{
    if (this != &other)
    {
        delete[] this->_Node;
        length = other.length;
        if (length > 0)
        {
            this->_Node = new T[length];
            for (unsigned int i = 0; i < length; i++)
            {
                this->_Node[i] = other._Node[i];
            }
        }
    }
    else
    {
        this->_Node = nullptr;
    }
    return *this;
}

template <class T>
bool List<T>::operator==(const List<T> &other)
{
    if(this->length != other.length)
    {
        return false;
    }
    else
    {
        for (unsigned int i = 0; i < this->length; i++)
        {
            if(this->_Node[i] != other._Node[i])
            {
                return false;
            }
        }
    }
    return true;
}

template <class T>
int List<T>::setLength(unsigned int new_length)
{
    if (length == 0)
    {
        length = new_length;
        this->_Node = this->reCreate(length);
        return 1;
    }
    else
    {
        cout << "Error!! length != 0" << endl;
        return 0;
    }
}

template <class T>
unsigned int List<T>::getLength()
{
    return length;
}

template <class T>
int List<T>::setElement(unsigned int pos, T val)
{
    if (pos < length)
    {
        this->_Node[pos] = val;
        return 1;
    }
    else
    {
        cout << "Error!! Position larger than length" << endl;
        return 0;
    }
}

template <class T>
T List<T>::getElement(unsigned int pos)
{
    assert(pos < this->length && "Error! position out of range");
    return this->_Node[pos];
}


