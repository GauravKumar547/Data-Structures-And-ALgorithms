#pragma once
/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Header file for stack
*/


#include<iostream>
#include<limits.h>
using namespace std;

template <typename U>
class Node
{
    U elem;
    Node<U>* next;
    public:
    Node()
    {
        next=NULL;
    }
    template <typename T>
    friend class StackList;
};

template <typename T>
class StackList
{
private:
    Node<T>* tos; 
public:
    StackList();
    ~StackList();
    void push(T x);
    T pop();
    T top();
    bool empty();

};

template <typename T>
StackList<T>::StackList()
{
    tos=NULL;
}

template <typename T>
StackList<T>::~StackList()
{
    if (!empty())
    {
        Node<T> *temp = tos;
        while (temp != NULL)
        {
            Node<T> *del = temp;
            temp = temp->next;
            delete del;
        }
    }
}

template <typename T>
bool StackList<T>::empty()
{
    return (tos==NULL);
}

template <typename T>
void StackList<T>::push(T x)
{
    Node<T>* temp = new Node<T>();
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
}

template <typename T>
T StackList<T>::pop()
{
    if(empty())
    {
        cout<<"UnderFlow!!"<<endl;
        return INT_MIN;
    }
    else
    {
        Node<T>* temp = tos;
        tos = tos->next;
        return temp->elem;
    }
    
  
}

template <typename T>
T StackList<T>::top()
{
    return tos->elem;
}
