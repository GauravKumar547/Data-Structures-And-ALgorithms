#include <iostream>
#include "TriDiagonal.cpp"
using namespace std;

template <class T>
class DiagonalMatrix 
{
	int n;
	T *d;
	public :
		DiagonalMatrix(int size=0)
		{
			n=size;
			if(n!=0)
			{
				d= new T[n];
			}
			else
			{
				d=0;
			}
		}
		
		~DiagonalMatrix()
		{
			delete[] d;
		}
		
		DiagonalMatrix<T>& store(const T& x, int i, int j);
		T retrieve(int i, int j) const;
		template <class U>
		friend ostream& operator << (ostream& out, DiagonalMatrix<U> d2);
};

template <class T>
T DiagonalMatrix<T>::retrieve(int i, int j) const
{
	if(i<1 || j<1 || i>n || j>n) throw "Out of Bounds";
	if(i==j) 
		return d[i-1];
	else 
		return 0;
}

template <class T>
DiagonalMatrix<T>& DiagonalMatrix<T>::store(const T& x, int i, int j)
{
	if(i<1 || i>n) throw "out of bounds";
	if(i!=j && x!=0) throw "must be zero";
	if(i==j)
	{
		d[i-1]=x;
	}
	return(*this);
}


template <class T>
ostream& operator << (ostream& out, DiagonalMatrix<T> d2)
{
	for(int i=1; i <= d2.n;i++)
	{
		for (int j = 1; j <= d2.n; j++)
		{
			if(i==j)
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
	int o,r,c,ch;
	cout<<"Enter the choice\n 1.Diagonal\n2.Triadiagonal\n your choice:";
	cin>>ch;
	cout<<"Enter the order of matrix: ";
	cin>>o;
	cout<<"Enter the elements of the matrix:\n";
	try
	{
		switch(ch)
		{
			case 1:
			{
				DiagonalMatrix<T> d(o);
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
			case 2:
			{
				TriDiagonal<T> d(o);
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
		}
			
				
	}
	catch(char const *str)
	{
		cout << "exception ocured" << str;
	}
	try
	{
				
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
template class DiagonalMatrix<int>;
template class DiagonalMatrix<char>;
template class DiagonalMatrix<float>;
