#include <iostream>
class Node
{
protected:
    long *_Node;

public:
    Node();
    Node(unsigned int);
    ~Node();
    long *reCreate(unsigned int _length);
    long *getNode();
};
