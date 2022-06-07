#include<iostream>
using namespace std;
template <typename T>
int binarySearch(T x, T *a, int first, int last)
{
    while(first<=last)
    {
        int mid=first+(last-1)/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]<x)
            first = mid+1;
        else
            last =mid-1;
    }
    return -1;
}

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
void choiceFunc(T t)
{
    int choice,size;
    int ind;
    T x,*ar;
    cout<<"Enter the size of array: ";
    cin>>size;
    ar= new T[size];
    cout<<"Now enter the elements of array: ";
    for(int i=0; i<size; i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter the element you want to search in the entered array: ";
    cin>>x;
    cout<<"Enter the method by which you want to search an element: \n";
    cout<<"1. Linear Search\n2.Binary Search\nYour choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            ind=linearSearch(x, ar, size);
            (ind==-1)? cout<<"Element not found.\n" : 
            cout<<"The require element is: "<<ar[ind]<<" present at index "<<ind+1<<endl;
            break;
        case 2:
            ind=binarySearch(x, ar,0, size-1);
            (ind==-1)? cout<<"Element not found.\n" :
            cout<<"The require element is: "<<ar[ind]<<" present at index "<<ind+1<<endl;
            break;
        default:
        {
            cout<<" invalid";
            exit(0);
        }
            
    }
}
int main()
{
    int n;
	char c;
	float f;
	cout<<"Enter the choice on which data type you want to operate on: \n";
	cout<<"1. int \n2. char \n3. float\nYour choice: ";
	cin>>n;
	switch(n)
	{
		case 1:
			choiceFunc(n);
			break;
		case 2:
			choiceFunc(c);
			break;
		case 3:
			choiceFunc(f);
			break;
		default:
			cout<<"Your choice is invalid......";
	}

    return 0;
}
