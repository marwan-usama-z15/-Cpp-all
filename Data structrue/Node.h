#ifndef NODE_H
#define NODE_H
template<class T>

class Node
{
    T info;
    Node* next;
public:
    Node(){}
    Node(T i, Node* n=0)
    {
        info=i;
        next=n;
    }
    Node* getNext()
    {
        return next;
    }
    void setNext(Node* n )
    {
        next=n;
    }
    T getInfo ()
    {
        return info;
    }
    void setInfo (T i)
    {
        info=i;
    }
};


#endif // NODE_H
