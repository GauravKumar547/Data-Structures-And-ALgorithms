#include <iostream>
using namespace std;

template <class T>
class TriDiagonal 
{
	int n;
	T *t;
	public :
		TriDiagonal(int size=0)
		{
			n=size;
			if(n!=0)
			{
				t= new T[n];
			}
			else
			{
				t=0;
			}
		}
		
		~TriDiagonal()
		{
			delete[] t;
		}
		
		TriDiagonal<T>& store(const T& x, int i, int j);
		T retrieve(int i, int j) const;
		template <class U>
		friend ostream& operator << (ostream& out, TriDiagonal<U> t2);
};

template <class T>
T TriDiagonal<T>::retrieve(int i, int j) const
{
	int k=0;
	if(i<1 || j<1 || i>n || j>n) throw "Out of Bounds";
	if(i==j || i-j==1 || j-i==1) 
    {
        k=2+3*(i-2)+j-i+1;
        return t[k];
    }
	else 
		return 0;
}

template <class T>
TriDiagonal<T>& TriDiagonal<T>::store(const T& x, int i, int j)
{
    int k=0;
	if(i<1 || i>n) throw "out of bounds";
	if((i-j>1 || j-i>1) && x!=0) throw "must be zero";
	if(i-j==1 || j-i==1)
	{
		k=2+3*(i-2)+j-i+1;
        t[k]=x;
	}
	return(*this);
}


template <class T>
ostream& operator << (ostream& out, TriDiagonal<T> t2)
{
    int k;
	for(int i=1; i <=t2.n;i++)
	{
		for (int j = 1; j <= t2.n; j++)
		{
			out<<t2.retrieve(i,j)<<" ";
		}	
		cout<<endl;
	}
	return out;
}

// 
// template <class T>
// void choiceFunction(T f)
// {
	// int o,r,c;
	// cout<<"Enter the order of matrix: ";
	// cin>>o;
	// cout<<"Enter the elements of the matrix:\n";
	// try
	// {
				// TriDiagonal<T> d(o);
				// for(int i=1;i<=o;i++)
				// {
					// for(int j=1; j<=o; j++)
					// {
						// cin>>f;
						// d.store(f,i,j);
					// }
				// }
				// cout << "Matrix is\n";
				// cout << d;
				// cout<<"Enter the row and coloumn number of element you want to extract: ";
				// cin>>r>>c;
				// cout << "The required element is: " << d.retrieve(r,c)<<endl;
	// }
	// catch(char const *str)
	// {
		// cout << "exception ocured" << str;
	// }
	// 
// }
// 
// int main()
// {
	// int n;
	// char c;
	// float f;
	// cout<<"Enter the choice on which data type you want to operate on: \n";
	// cout<<"1. int \n2. char \n3. float\nYour choice: ";
	// cin>>n;
	// switch(n)
	// {
		// case 1:
			// choiceFunction(n);
			// break;
		// case 2:
			// choiceFunction(c);
			// break;
		// case 3:
			// choiceFunction(f);
			// break;
		// default:
			// cout<<"Your choice is invalid......";
	// }
	// return 0;
// }
// template class TriDiagonal<int>;
// template class TriDiagonal<char>;
// template class TriDiagonal<float>;
// 