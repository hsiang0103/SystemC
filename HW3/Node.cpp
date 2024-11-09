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

long Node::getNode(unsigned int i)
{
    if (_Node[i])
    {
        return _Node[i];
    }
    else
    {
        cout << "Node doesn't exist" << endl;
        return 0;
    }
}

void Node::setNode(unsigned int i, long value)
{
    if (_Node[i])
    {
        _Node[i] = value;
    }
    else
    {
        cout << "Node doesn't exist" << endl;
    }
}
