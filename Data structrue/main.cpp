#include "SLL.h"
#include "QueueSLL.h"
#include "StackSLL.h"
#include <iostream>
#include<string >
#include<cstring>
#include <sstream>
#include <cstdlib>
#include<iomanip>

using namespace std;


bool pairr(char left,char right)
{
    if(left=='('&&right==')')
    {
        return true;
    }
    else if(left=='<'&&right=='>')
    {
        return true;
    }
    else if(left=='['&&right==']')
    {
        return true;
    }
    else if(left=='{'&&right=='}')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool chkBalanced(string & bracket)
{
    StackSLL<char> x;
  for (int i=0;i<bracket.length();i++)
{
    if(bracket[i]=='('||bracket[i]=='{'||bracket[i]=='['||bracket[i]=='<')
        {
         x.push(bracket[i]);
        }
    else if(bracket[i]==')'||bracket[i]=='}'||bracket[i]==']'||bracket[i]=='>')
    {
        if (x.isempty()|| ! pairr(x.top(),bracket[i]))
        {
            return false;
        }
        else
        {
            x.pop();
        }

    }

}
if (x.isempty())
{
    return true;
}
}
string convertToBinary(int num)
{
   StackSLL<int> x;
   while(num > 0) {
      int remainder = num % 2;
      num = num / 2;
      x.push(remainder);
   }
  string item;
   while(!x.isempty()) {
      item +=to_string ( x.top());
      x.pop();
   }
return item;

}
bool IsOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' )
        {
            return true;
        }
    return false;
}
bool IsOperand(char x)
{
    if( (x >= 'A' && x <= 'Z')||(x >= 'a' && x <= 'z')||(x >= '0' && x <= '9') )
       {
           return true;
       }
    return false;
}
int priority(char x)
{
    if(x == '+' || x == '-')
        {return 1;}
    if (x == '*' ||x == '/')
        {return 2;}
    if( x == '^')
       {return 3;}
return 0;
}
bool checkeq (char x, char y)
    {
        int w1= priority(x);
        int w2 = priority(y);
        if (w1 == w2)
        {
            if (x == '^' )

                {
                    return false;
                }

            return true;
        }
        if(w1>w2)
        {
            return true;
        }
        else
            {
                return false;
            }

    }
string convertInfixToPostfix(string exp)
    {
        StackSLL<char> x;
        string result=" " ;
       for (int i=0;i<exp.length();i++)
        {
            if(exp[i] == ' ')
                {continue;}
            else if(exp[i]== '(')
                x.push(exp[i]);
            else if(IsOperand(exp[i]))
                {result += exp[i];
              result +=" ";

                }
            else if(IsOperator(exp[i]))
            {
                while(!x.isempty() &&  checkeq (x.top(), exp[i]))
                {
                    result +=  x.pop() ;
                     result +=" ";

                }
                x.push(exp[i]);
            }
            else if(exp[i]== ')')
            {
                while(!x.isempty() && x.top() != '(')
                {
                   result += x.pop();;
                   result +=" ";

                }
                x.pop();
            }
            i++;
        }
        	while (!x.isempty()) {
		result+= x.pop();
		result +=" ";


	}

        return result;
    }
int performOperation(int op1, int op2, char op)
{
    int ans;
    if (op =='+')
    {
        ans = op2 + op1;
    }
    else if (op =='-')
    {
        ans = op2 - op1;
    }

    else if (op ==	 '*')
    {
        ans = op2 * op1;
    }

    else if (op =='/')
    {
        ans = op2 / op1;
    }
    return ans;
}
int evaluatePostfix(string exp)
    {
        StackSLL<int>s;
        int op1, op2 ,j, x;
        j = 0;
        char buffer[100];
for (int i = 0; i < exp.length(); i++)
        {
		if (isdigit(exp[i]))
        {
			buffer[j++] = exp[i];
		}
		else if (exp[i] == ' ')
		{
			if (j > 0) {
				buffer[j] = '\0';
				x = atoi(buffer);
				s.push(x);
				j = 0;
			}
		}

		else if (IsOperator(exp[i]))
        {
			op1 = s.pop();
			op2 = s.pop();
			s.push(performOperation(op1, op2, exp[i]));
		}
	}
return s.pop();
    }
template<class T>
bool moveNthElem(QueueSLL<T> & x,int n)
{
QueueSLL<T> v;

int i=1;
T z;
bool flag=0;
while (!x.isempty())
{
if(i!=n)
{
v.enqueue(x.dequeue());
i++;
}
else if(i==n)
{
   z=x.dequeue();
   i++;
flag=1;
}
}
x.clear2();
x.enqueue(z);
while(!v.isempty())
{
    x.enqueue(v.dequeue());
}
cout<<"{ ";

while(!x.isempty())
{
  cout<<x.dequeue()<<" ";

}
cout<<"}"<<endl;
if (flag)
{
return true;
}
else
{return false;}
}
template<class T>
void reverseQueue(QueueSLL<T> &Q)
{
   StackSLL<T> S;
   while (! Q.isempty())
     {
         S.push(Q.dequeue());
     }
   while (! S.isempty())
      {
          Q.enqueue(S.pop());
      }
         cout<<"{ ";
         while (!Q.isempty())
     {
       cout<< Q.dequeue()<<" ";
     }
     cout<<"}";
     cout<<endl;
}
int main()
{

    int Userinput;
    do {//the menu that the user choose from
            cout<<endl;
        cout << "1) Check for balanced brackets.\n"
             << "2) Convert to binary.\n"
             << "3) Convert infix to postfix expression and evaluate.\n"
             << "4) Move Nth element to front in a queue of strings.\n"
             << "5) Reverse elements of a queue of doubles.\n"
             << "6) Exit\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> Userinput;
        cout<<endl;

            switch (Userinput) {
                case 1: {
                    string s;
                    cout<<"Enter  the expression: ";
                    cin>>s;
              if (chkBalanced(s))
                {
                    cout<<"expression is balanced"<<endl;

                }
                else
                {
                    cout<<"expression is not balanced"<<endl;
                }
                break;
                }
                case 2:
                {
                    int s;
                    cout<<"Enter the number: ";
                    cin>>s;
            cout<<convertToBinary(s);
                    cout<<endl;
                    break;

                }
                case 3: {
                 cin.ignore();
                 string s;
            cout<<"please  enter expression: ";
             getline(cin,s);
             string z;
            z=convertInfixToPostfix(s);
             cout<<"Postfix expression= "<<z<<endl;
            cout<<"Result of expression= "<<evaluatePostfix(z)<<endl;
                    break;
                }

                case 4: {
                      QueueSLL<string> x;
                       int s,e;
                       string r;
                    cout<<"Enter the size of queue: ";
                    cin>>s;
                    for(int i=0;i<s;i++)
                    {
                          cout<<"Enter the element you want to add to queue: ";
                           cin>>r;
                           x.enqueue(r);

                    }

                       cout<<"Enter the position  number you want to move: ";
                    cin>>e;
              if (moveNthElem(x,e))
              {
                    cout<<"element is swapped"<<endl;

                }
                else
                {
                    cout<<"element is not found"<<endl;
                }


                    break;
                }

              case 5:
                  {


                    QueueSLL<string> x;
                       int s;
                       string r;
                    cout<<"Enter  the size of queue: ";
                    cin>>s;
                    for(int i=0;i<s;i++)
                    {
                          cout<<"Enter the char you want to add to queue: ";
                           cin>>r;
                           x.enqueue(r);

                    }

               reverseQueue(x);


                  break;
                  }
                case 6:
               {
                   exit(0);
                break;
               }
                default:
                    {
                        cout<<"enter valid number..."<<endl;
                    }
            }




    } while (true);

}

