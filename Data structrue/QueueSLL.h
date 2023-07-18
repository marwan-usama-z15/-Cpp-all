#ifndef QUEUESLL_H
#define QUEUESLL_H
#include "SLL.h"
template<class T>

class QueueSLL
{private :
    SLL<T> obj;
public:
    QueueSLL()
    {
    }
    void enqueue(T value)
   {
       obj.addtoTail(value);
   }
   T dequeue()
    {
        return obj.removeFromHead();
    }
    T front()
    {
       return obj.getValueAtHead();
    }
   bool isempty()
   {

     if (obj.isEmpty())
     {
         return true;

     }
     else
     {
         return false;
     }
   }

   void clear2()
   {
    obj.clear();
   }
};

#endif // QUEUESLL_H
