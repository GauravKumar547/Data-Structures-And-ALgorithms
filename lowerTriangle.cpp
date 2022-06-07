#include <iostream>
using namespace std;

template <class T>
class lowerTrianlge 
{
	int n;
	T *d;
	public :
		lowerTrianlge(int size=0)
		{
			n=size*(size+1)/2;
			if(n!=0)
			{
				d= new T[n];
			}
			else
			{
				d=0;
			}
		}
		
		~lowerTrianlge()
		{
			delete[] d;
		}
		
		lowerTrianlge<T>& store(const T& x, int i, int j);
		T retrieve(int i, int j) const;
		template <class U>
		friend ostream& operator << (ostream& out, lowerTrianlge<U> d2);
};

template <class T>
T lowerTrianlge<T>::retrieve(int i, int j) const
{ 
    int k=(j-1)*j/2 + i-1;
	if(i<1 || j<1 || i>n || j>n) throw "Out of Bounds";
	if(j<=i) 
		return d[k];
	else 
		return 0;
}

template <class T>
lowerTrianlge<T>& lowerTrianlge<T>::store(const T& x, int i, int j)
{
    int k=(j-1)*j/2 + i-1;
	if(i<1 || i>n) throw "out of bounds";
	if(i<j && x!=0) throw "must be zero";
	if(j<=i)
	{
		d[k]=x;
	}
	return(*this);
}


template <class T>
ostream& operator << (ostream& out, lowerTrianlge<T> d2)
{
	for(int i=1; i <= d2.n;i++)
	{
		for (int j = 1; j <= d2.n; j++)
		{
			if(j<=i)
			{
				out<<d2.retrieve(i,j)<<" ";
			}
			else
			{
				out<<0<<" ";
			}
		}	
		cout<<endl;
	}
	return out;
}

template <class T>
void choiceFunction(T f)
{
	int o,r,c;
	cout<<"Enter the order of matrix: ";
	cin>>o;
	cout<<"Enter the elements of the matrix:\n";
	try
	{
				lowerTrianlge<T> d(o);
				for(int i=1;i<=o;i++)
				{
					for(int j=1; j<=o; j++)
					{
						cin>>f;
						d.store(f,i,j);
					}
				}
				cout << "Matrix is\n";
				cout << d;
				cout<<"Enter the row and coloumn number of element you want to extract: ";
				cin>>r>>c;
				cout << "The required element is: " << d.retrieve(r,c)<<endl;
	}
	catch(char const *str)
	{
		cout << "exception ocured" << str;
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
			choiceFunction(n);
			break;
		case 2:
			choiceFunction(c);
			break;
		case 3:
			choiceFunction(f);
			break;
		default:
			cout<<"Your choice is invalid......";
	}
	return 0;
}
template class lowerTrianlge<int>;
template class lowerTrianlge<char>;
template class lowerTrianlge<float>;
