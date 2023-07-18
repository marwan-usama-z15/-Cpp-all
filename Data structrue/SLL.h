#ifndef SLL_H
#define SLL_H
#include "Node.h"
#include <iostream>
using namespace std;
template<class T>
class SLL
{    private:
    Node<T> *head, *tail;
public:
    SLL()
    {
        head = tail = 0;
    }
    void addtoHead(T value)
    {
        Node<T> *temp=new  Node<T>;
        temp->setInfo(value);
        if(head == NULL)
        {
            temp->setNext(NULL);


        }

        else
        {
            temp->setNext(head);


        }
        if (tail==NULL)
          {tail=head;}
head=temp;
    }
    void addtoTail(T value)
    {


        Node<T> *temp=new  Node<T>;
        temp->setInfo(value);
        temp->setNext(NULL);
        if(tail==0||head==0)
        {

          head=tail=temp;
        }
        else
        {


         tail->setNext(temp);
         tail=temp;
        }
    }
  T removeFromHead()
    {

       if (head == NULL)
       {
       return NULL;
       }

        Node<T> *current=head;

        head=head->getNext();
        T X;
        X=current->getInfo();
       delete current;
        return X ;


    }
    T removeFromTail()
    {
        if (tail == NULL)

            return NULL;

      else {

            Node<T> *removedNode= tail;

            if (head == tail) {

                  head = NULL;

                  tail = NULL;

            } else {

                Node<T> *previousToTail = head;

                  while (previousToTail->getNext() != tail)

                        previousToTail = previousToTail->getNext();

                  tail = previousToTail;

                  tail->setNext(NULL);

            }

             T x= removedNode->getInfo();
            delete removedNode;
            return x;
      }


     }
    T getValueAtHead()
    {
        return head->getInfo();

    }

    bool isEmpty()
    {
        if (head==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void clear() {
        while(head!=NULL)
        {
            removeFromTail();
        }


  }

   friend ostream& operator<<(ostream& os, SLL<T> obj)
{

while (!obj.isEmpty())
{
   os<<obj.getValueAtHead();

   obj.removeFromHead();
}

 return os;
}


};


#endif // SLL_H
