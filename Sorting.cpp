#include<iostream>
using namespace std;

template <typename T>
void display(T *arr, int n)
{
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void insertionSort(T *arr, int n)
{
    T key;
    int j, i;
    while(i<n)
    {
        // key = arr[i];
        j=i;
        while( j>0 && arr[j]>arr[j-1])
        {
            // arr[j+1]=arr[j];
            swap(arr[j], arr[j-1]);
            j=j-1;
        }
        // arr[j+1]=key;
        i++;
        display(arr, n);
    }
}

template <typename T>
void bubbleSort(T *arr, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

template <typename T>
void selectionSort(T *arr, int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
            if(arr[j]<arr[min])
                min=j;
        
        swap(arr[min], arr[i]);
    }
}

template <typename T>
void swap( T *x, T *y)
{
    T temp= *x;
    *x=*y;
    *y=temp;
}



template <typename T>
void choiceFunc(T t)
{
    int choice,size;
    T *ar;
    cout<<"Enter the size of array: ";
    cin>>size;
    ar= new T[size];
    cout<<"Now enter the elements of array: ";
    for(int i=0; i<size; i++)
    {
        cin>>ar[i];
    }

    cout<<"Enter the method by which you want to sort the data:\n";
    cout<<"1. Selection Sort\n2.Bubble Sort\n3.Insertion Sort\n Your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            selectionSort(ar,size);
            display(ar,size);
            break;
        case 2:
            bubbleSort(ar,size);
            display(ar,size);
            break;
        case 3:
            insertionSort(ar,size);
            display(ar,size);
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
