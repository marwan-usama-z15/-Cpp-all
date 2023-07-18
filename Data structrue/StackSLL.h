#ifndef STACKSLL_H
#define STACKSLL_H
#include "SLL.h"

template<class T>
class StackSLL
{

private:
SLL<T> obj;
public:
    StackSLL()
    {
    }
    void push(T value)
    {
      obj.addtoHead(value);
    }
  T pop()
   {
    return  obj.removeFromHead();
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

   T top()
   {
   return obj.getValueAtHead();
   }
   void clear1()
   {
    obj.clear();
   }
};

#endif // STACKSLL_H
