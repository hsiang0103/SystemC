
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

List List::operator++()
{
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]++;
    }
    return *this;
}

List List::operator++(int)
{
    List temp(*this);
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]++;
    }
    return temp;
}

List List::operator--()
{
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]--;
    }
    return *this;
}

List List::operator--(int)
{
    List temp(*this);
    for (unsigned int i = 0; i < length; i++)
    {
        _Node[i]--;
    }
    return temp;
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
        for (unsigned int i = 0; i < list.length; i++)
        {
            out << list._Node[i] << " ";
        }
    }
    return out;
}

istream &operator>>(istream &in, List &list)
{
    unsigned int newLength;
    for (unsigned int i = 0; i < list.length; i++)
    {
        long value;
        in >> value;
        list.setElement(i, value);
    }
    return in;
}


List::List(const List &other) : Node()
{
    length = other.length;
    if (length > 0)
    {
        reCreate(length);
        for (unsigned int i = 0; i < length; i++)
        {
            this->setElement(i, other.getElement(i));
        }
    }
    else
    {
        _Node = NULL;
    }
}
