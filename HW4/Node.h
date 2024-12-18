#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;

template <class T>
class Node
{
protected:
    T *_Node;

public:
    Node();
    Node(unsigned int);
    ~Node();
    T *reCreate(unsigned int);
    T getNode(unsigned int i);
    void setNode(unsigned int i, T value);
};

#endif