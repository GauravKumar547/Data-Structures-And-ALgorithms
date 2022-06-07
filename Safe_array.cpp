#include<iostream>
using namespace std;

template <class T>
class ArrayD
{
    public:
    T *elem;
    int size,l,u;
    ArrayD(int a=0, int b=0)
    {
        l=a;
        u=b;
        size= b-a+1;
        elem= new T[size];
    }
    T& operator[](int i)
    {
        if(i<l|| i>=u)
		throw i;
        return elem[i-l];
    }
   template <class U>
   friend ostream & operator << ( ostream &os, const ArrayD<U> &a2) ;
   template <class U>
   friend istream & operator >> ( istream &in, const ArrayD<U> &a3) ;
   ArrayD<T> operator + ( const ArrayD<T> &a1)
   {	ArrayD temp;
   		temp.size=size;
   		if(this->size==a1.size )
   			for(int i=0;i<a1.size;i++)
    			temp.elem[i]=elem[i]+a1.elem[i];
    	else
    	throw "addition";
    	return temp;
   }
   ArrayD<T> operator - ( const ArrayD<T> &a1)
   {	ArrayD<T> temp;
  		temp.size=size;
   		if(this->size==a1.size )
   			for(int i=0;i<a1.size;i++)
    			temp.elem[i]=elem[i]-a1.elem[i];
    	else
    	throw "subtraction";
    	return temp;
   }
   ArrayD<T> operator * ( const ArrayD<T> &a1)
   {	ArrayD<T> temp;
   		temp.size=size;
   		if(this->size==a1.size )
   			for(int i=0;i<a1.size;i++)
    			temp.elem[i]=elem[i]*a1.elem[i];
    	else
    	throw "multiplication";
    	return temp;
   }
   ArrayD<T> operator / ( const ArrayD<T> &a1)
   {	ArrayD<T> temp;
   		temp.size=size;
   		if(this->size==a1.size )
   		{
   			for(int i=0;i<a1.size;i++)
   			{
   		
			   
   				if(a1.elem[i]!=0)
   					temp.elem[i]=elem[i] / a1.elem[i];
   				else
   					cout<<"Divide by zero exception";
   			
   			}
   		}
   		else 
   			throw "division";
    	return temp;
   }
   ~ArrayD()
   {
   		delete []elem;
   }
  
};

template<class U>
istream & operator >> ( istream &in, const ArrayD<U> &a3) 
{
	for(int i=0;i<a3.size;i++)
    	in>>a3.elem[i];
    return in;
}

template<class U>
ostream & operator << ( ostream &os, const ArrayD<U> &a2)  
{
	for(int i=0;i<a2.size;i++)
   		os<<a2.elem[i]<<" ";
    return os;
}

template <class T>
void typeselection(T t)
{
    int up,ch, lo,ind,l,u;
    T x;
    char choice;
    cout<<" Enter the lower bound of the array : ";
    cin>>lo;
    cout<<" Enter the upper bound of the array : ";
    cin>>up;
    ArrayD<T> a(lo,up);
    
    cout<<"\nNow enter the elments of array:";
    cin>>a;
    
    cout<<"\nThe array is: ";
    cout<<a;
    do{

    try{
    	cout<<"\nSelect from the following:    ";
    	cout<<"\n1.Extracting an element of array from given index ";
    	cout<<"\n2.Adding two arrays together";
    	cout<<"\n3.Subtraction one array from other";
    	cout<<"\n4.Multiplication of elements of array";
    	cout<<"\n5.Division of elements of array\n";
    	cout<<"The choice is: ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1: 
    			{
    				cout<<"\nWhich element do you want to access enter its index:";
    				cin>>ind;
    				x=a[ind];
    				cout<<"\nThe required element is "<<x;
    				break;
				}
			case 2:
				{
					 cout<<" Enter the lower bound of the second array : ";
   					 cin>>l;
    				 cout<<" Enter the upper bound of the second array : ";
   					 cin>>u;
  					 ArrayD<T> A1(l,u);
    
  					 cout<<"\nNow enter the elments of array:";
   					 cin>>A1;
    
 					 cout<<"\nThe array is: ";
   					 cout<<A1;
   					 ArrayD<T> A2=a+A1;
   					 cout<<"\nThe resultant array after addition is: ";
   					 cout<<A2;
   					 break;
				}
			case 3:
				{
					 cout<<" Enter the lower bound of the second array : ";
   					 cin>>l;
    				 cout<<" Enter the upper bound of the second array : ";
   					 cin>>u;
  					 ArrayD<T> A1(l,u);
    
  					 cout<<"\nNow enter the elments of array:";
   					 cin>>A1;
    
 					 cout<<"\nThe array is: ";
   					 cout<<A1;
   					 ArrayD<T> A2=a-A1;
   					 cout<<"\nThe resultant array after subtraction is: ";
   					 cout<<A2;
   					 break;
				}
			case 4:
				{
					 cout<<" Enter the lower bound of the second array : ";
   					 cin>>l;
    				 cout<<" Enter the upper bound of the second array : ";
   					 cin>>u;
  					 ArrayD<T> A1(l,u);
    
  					 cout<<"\nNow enter the elments of array:";
   					 cin>>A1;
    
 					 cout<<"\nThe array is: ";
   					 cout<<A1;
   					 ArrayD<T> A2=a*A1;
   					 cout<<"\nThe resultant array after multiplication is: ";
   					 cout<<A2;
   					 break;
				}
			case 5:
				{
					 cout<<" Enter the lower bound of the second array : ";
   					 cin>>l;
    				 cout<<" Enter the upper bound of the second array : ";
   					 cin>>u;
  					 ArrayD<T> A1(l,u);
    
  					 cout<<"\nNow enter the elments of array:";
   					 cin>>A1;
    
 					 cout<<"\nThe array is: ";
   					 cout<<A1;
   					 ArrayD<T> A2=a/A1;
   					 cout<<"\nThe resultant array after division is: ";
   					 cout<<A2;
   					 break;
				}
				default:
					{
						cout<<"Your choice is invalid............";
					}
		}
    
	}
	catch(char const *str)
	{
		cout<<"\nThe array size mismatched cannot perform the "<<str;
	}
    catch( int s)
    {
    	cout<<"\nThe index is out of bound";
	}
	cout<<"\nDo you want to continue: ";
	cin>>choice;
	}while(choice=='y'||choice=='Y');
}


int main()
{
	int c;
	double d;
	float f;
	cout<<"\nOn which data type you want to operate on Please selct from the follow: ";
	cout<<"\n 1. float \n 2. int \n 3.double \n Your choice: ";
	cin>>c;
	switch(c)
	{
		case 1:
			typeselection(f);
			break;
		case 2:
			typeselection(c);
			break;		
		case 3:
			typeselection(d);
			break;
		default:
			cout<<"Wrong choice.......";
	}
	return 0;
	
}


template class ArrayD<int>;
template class ArrayD<float>;
template class ArrayD<double>;


