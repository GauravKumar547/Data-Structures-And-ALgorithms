/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Addition of two polynomials using Linked Lists 
*/
#include<iostream> 
using namespace std; 

class Node
{ 
	int coeff; 
	int pow; 
	Node *next; 
    public: 
    Node()
    {
        next=NULL;
    }

    friend class Polynomial;
}; 

class Polynomial
{
    Node* head;
    public:
    Polynomial();
   
    void input();
    void addNode(int exp, int coeff);
    Polynomial addPoly( const Polynomial & p2) ;
    void display();
};

Polynomial::Polynomial():head(NULL){}

void Polynomial :: addNode(int exp, int coeff)
{ 
	Node* pt = head; 
    Node* a = new Node;
    a->coeff = coeff;
    a->pow = exp;
    if(head==NULL)
    {
        a->next=head;
        head= a;
        return;
    }
	while(pt->next!=NULL)
    {
        pt = pt->next;
    }
    a->next = pt->next;
    pt->next = a;
} 


Polynomial Polynomial:: addPoly( const Polynomial& p1)
{ 
    Polynomial p2;
    if(head==NULL)
       p2=p1;
    else if(p1.head == NULL)
        p2=*this;
    else
    {
        Node* pt = head;
        Node* pt1 = p1.head;
        while(pt!= NULL && pt1!= NULL)
        {
            if(pt->pow > pt1->pow)
            {
                p2.addNode(pt->pow,pt->coeff);
                pt = pt->next;
            }
            else if(pt1->pow > pt->pow)
            {
                p2.addNode(pt1->pow,pt1->coeff);
                pt1 = pt1->next;
            }
            else
            {
                p2.addNode(pt->pow,pt->coeff+pt1->coeff);
                pt = pt->next;
                pt1 = pt1->next;
            }
        }
        while(pt!=NULL)
        {
            p2.addNode(pt->pow,pt->coeff);
            pt = pt->next;
        }
         while(pt1!=NULL)
        {
            p2.addNode(pt1->pow,pt1->coeff);
            pt1 = pt1->next;
        }
       
    }
    return p2;
} 

void Polynomial :: input()
{
    int co, ex;
    cout<<"Enter the Coefficient: ";
    cin>>co;
    cout<<"Enter the exponent: ";
    cin>>ex;
    addNode(ex,co);
}
void Polynomial :: display() 
{ 
    Node* pt =head;
    while(pt != NULL) 
	{ 
        if(pt->pow!=0)
        {
            cout<< pt->coeff<<"x^"<< pt->pow; 
        }
	    else
        {
            cout<<pt->coeff;
        }
        
        pt = pt->next;
	    if(pt!= NULL) 
        {
            if(pt->coeff!=0)
                cout<<" + ";  
            else{
                pt = pt->next;
            }
        }
		    
	} 
    cout<<endl;
} 


int main() 
{ 
    int n1, n2;
	Polynomial P1, P2, P3;
    
	cout<<"Enter the number of terms in first Polynomial: ";
    cin>>n1;
    for(int i=0; i<n1; i++)
    {
        P1.input();
    }

    cout<<"1st Polynomial: "; 
	P1.display(); 

	cout<<"Enter the number of terms in second Polynomial: ";
    cin>>n2;
    for(int i=0; i<n2; i++)
    {
        P2.input();
    }
	
	cout<<"2nd Polynomial: "; 
	P2.display(); 
	
    P3 = P1.addPoly(P2); 
	  
	cout<<"Polynomial after addition: "; 
	P3.display(); 

return 0; 
} 
