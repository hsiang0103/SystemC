#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
Node<T>::Node() : _Node(nullptr) {}

template <class T>
Node<T>::Node(unsigned int _length)
{
    _Node = new T[_length];
}

template <class T>
Node<T>::~Node()
{
    delete[] _Node;
}

template <class T>
T *Node<T>::reCreate(unsigned int _length)
{
    delete[] _Node;
    _Node = new T[_length];
    return _Node;
}
