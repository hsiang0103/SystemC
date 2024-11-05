#include "Node.h"

class List : public Node
{
protected:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    List(const List &other);
    ~List();
    List &operator=(const List &other);
    int setLength(unsigned int);
    unsigned int getLength();
    int setElement(unsigned int pos, long val);
    long getElement(unsigned int pos);
};