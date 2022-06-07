
#include<bits/stdc++.h>
using namespace std;

class Node
{
    int elem;
    int row;
    int col;
    Node *next;
    public:

    Node()
    {
        next=NULL;
    }
    friend class linkedList;
};

class linkedList
{
    Node* head;
    public:
    linkedList();
    ~linkedList();
    void addTailNode(int e, int r, int c);
    void input(int r, int c);
    void display(int r, int c);
};

linkedList::linkedList()
{
    head=NULL;
}

linkedList ::~linkedList()
{
    if(head!=NULL)
    {
        Node* temp = head;
        while(temp!= NULL)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
}
void linkedList::addTailNode(int e, int r, int c)
{
    Node* a = new Node;
    a->elem = e;
    a->row = r;
    a->col = c;
    if(head==NULL)
    {
        head=a;
    }
    else
    {
        Node* pt = head;
        while (pt->next!=NULL)
        {
            pt = pt->next;
        }

        pt->next = a;
        a=NULL;
    }     
}
void linkedList::display(int r, int c)
{
    Node* pt = head;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(i==pt->row && j == pt->col)
            {
                cout<<pt->elem<<" ";
                pt = pt->next;
            }
            else
            {
                cout<<0<<" ";
            }
            
        }
        cout<<endl;
    }

}

void linkedList::input(int r, int c)
{
    int value;
    for(int i = 0; i < r; i++ )
    {
        for(int j = 0; j < c; j++ )
        {
            cin>>value;
            if(value != 0)
            {
                addTailNode(value,i,j);
            }
        }
    }
}

int main()
{
    linkedList M;
    int numRows,numCols;
    cout<<"Enter the number of rows of the matrix: ";
    cin>>numRows;
    cout<<"Enter the number of columns of the matrix: ";
    cin>>numCols;
    cout<<"Enter the elements of the matrix:\n";
    M.input(numRows,numCols);
    M.display(numRows, numCols);
    return 0;
}