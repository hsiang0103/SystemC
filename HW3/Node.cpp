#include <iostream>
#include "Node.h"
using namespace std;

Node::Node()
{
    _Node = nullptr;
}

Node::Node(unsigned int _length)
{
    _Node = new long[_length];
}

Node::~Node()
{
    delete[] _Node;
}

long *Node::reCreate(unsigned int _length)
{
    delete[] _Node;
    _Node = new long[_length];
    return _Node;
}

long *Node::getNode()
{
    return _Node;
}