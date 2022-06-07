/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Implementation of Stack using array
*/

#include<iostream>
using namespace std;
#define SIZE 100
class Stack 
{
    int tos;
    int arr[SIZE];
    public:
    Stack();
    void push(int x);
    int pop();
    int top();
    bool empty();
};
Stack :: Stack()
{
    tos=-1;
}

bool Stack::empty()
{
    return (tos<0);
}

void Stack ::push(int x)
{
    if(tos>=(SIZE-1))
    {
        cout<<"Stack overflow!!";
    }
    else
    {
        arr[++tos]=x;
        cout<< x <<" pushed on to the stack.\n";
    }
    
}

int Stack::pop()
{
    if(empty())
    {
        cout<<"Stack underflow!!";
        return 0;
    }
    else
    {
        int x = arr[tos--];
        return x;
    }
    
}
int Stack::top()
{
    if(empty())
    {
        cout<<"Stack is empty!!";
        return 0;
    }
    else
    {
        int x= arr[tos];
        return x;
    }
    
}
int main()
{
    Stack Stk;
    Stk.push(4);
    Stk.push(5);
    Stk.push(6);
    cout<<Stk.pop()<<" is popped from the stack\n";
    Stk.push(8);
    cout<<"The topmost element in stack is: "<<Stk.top()<<endl;
    Stk.pop();
    cout<<Stk.pop()<<" is popped from the stack\n";

    return 0;
}