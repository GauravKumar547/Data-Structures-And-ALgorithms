// merge_sort.cpp
#include<iostream>
#include<iomanip>
using namespace std;

// function for merging and sorting the left and right arrays 
void merge(int *arr, int left, int mid, int right) 
{
   //size of left and right sub-arrays
    int nLeft = mid-left+1; 
    int nRight = right-mid;
    int leftArray[nLeft], rightArray[nRight];
    //copying data to left and right arrays respectively
    for(int i = 0; i<nLeft; i++)
    {
            leftArray[i] = arr[left+i];
    }
    for(int j = 0; j<nRight; j++)
    {
        rightArray[j] = arr[mid+1+j];

    }
    int i = 0, j = 0, k = left;
    //merge left and right arrays to original array
    while(i < nLeft && j<nRight) 
    {
        if(leftArray[i] <= rightArray[j]) 
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while(i<nLeft) 
    {      
        arr[k] = leftArray[i];
        i++; k++;
    }
    while(j<nRight) 
    {    
        arr[k] = rightArray[j];
        j++; k++;
    }
}
void merge_sort_func(int *arr, int left, int right) 
{
    int mid;
    if(left < right) 
    {
        int mid = left+(right-left)/2;
        // Sort first and second arrays
        merge_sort_func(arr, left, mid);
        merge_sort_func(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// driver function for reading the data and printing in well fromatted right aligned manner
// with spaces in left and width of 8 characters
int main()
{
    int arr[1000];
    int j=0;
    // reading array from file
    while (cin>>arr[j])
    {
        j++;
    }
    // calling the quicksort function
    merge_sort_func(arr, 0, j-1);
    // printing the sorted array in required format
    for(int i = 0; i < j; i++)
    {
        if(i%8 == 0)
        {
            cout<<endl;
            cout<<arr[i];
        }
        else
        {
            cout<<setw(8)<<arr[i];
        }
    }
    cout<<endl;
    return 0;
}