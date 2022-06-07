/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Linear Search implementation for distinct elements of an array
*/

#include<iostream>
using namespace std;

template <typename T>
int linearSearch(T x, T *a, int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==x)
            return i;
    }
    return -1;
}

template <typename T>
void inputArray(T *ar, int n)
{
    cout<<"Now enter the elements of array: ";
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
}
int main()
{
    int N;
    int index;
    int x,*ar;
    cout<<"Enter the size of array: ";
    cin>>N;
    ar= new int[N];
    inputArray(ar,N);
    cout<<"Enter the element you want to search in the entered array: ";
    cin>>x;
    index=linearSearch(x, ar, N);
    if(index==-1)
    { 
        cout<<"Element not found.\n" ;
    }
    else 
    { 
        cout<<"The required element "<<ar[index]<<" is present at index "<<index+1<<endl;
    }
    return 0;
}