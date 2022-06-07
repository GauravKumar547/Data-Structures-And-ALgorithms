/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Implementation of Stack using linked list
*/


#include<iostream>
#include<limits.h>
using namespace std;

class Node
{
    int elem;
    Node* next;
    public:
    Node()
    {
        next=NULL;
    }
    friend class StackList;
};

class StackList
{
private:
    Node* tos; 
public:
    StackList();
    ~StackList();
    void push(int x);
    int pop();
    int top();
    bool empty();

};

StackList::StackList()
{
    tos=NULL;
}

StackList::~StackList()
{
    if (!empty())
    {
        Node *temp = tos;
        while (temp != NULL)
        {
            Node *del = temp;
            temp = temp->next;
            delete del;
        }
    }
}

bool StackList::empty()
{
    return (tos==NULL);
}
void StackList::push(int x)
{
    Node* temp = new Node();
    temp->elem = x;
    if(tos==NULL)
    {
        tos=temp;
    }
    else
    {
        temp->next=tos;
        tos=temp;
    }
    cout<<x<<" pushed to the stack\n";
}

int StackList::pop()
{
    if(empty())
    {
        cout<<"UnderFlow!!"<<endl;
        return INT_MIN;
    }
    else
    {
        Node* temp = tos;
        tos = tos->next;
        return temp->elem;
    }
    
  
}

int StackList::top()
{
    return tos->elem;
}

int main()
{
    StackList Stk;
    Stk.push(5);
    Stk.push(10);
    Stk.push(11);
    cout<<Stk.pop()<<" is popped from the stack\n";
    Stk.push(8);
    cout<<"The topmost element of stack is "<<Stk.top()<<endl;
    cout<<Stk.pop()<<" is popped from the stack\n";
    cout<<"The topmost element of stack is "<<Stk.top()<<endl;

    return 0;

}