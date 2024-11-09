#include <iostream>
class Node
{
protected:
    long *_Node;

public:
    Node();
    Node(unsigned int);
    ~Node();
    long *reCreate(unsigned int);
    long getNode(unsigned int i);
    void setNode(unsigned int i, long value);
    
};
