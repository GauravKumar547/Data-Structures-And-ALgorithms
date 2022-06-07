#include<iostream>
using namespace std;

// Node class for one node of the list
class Node
{
    public:
    int elem;
    Node *next;
    Node()
    {
        next=NULL;
    }
    friend class sortedList;
};

// sortedList class for implementation of sorted list 
class sortedList
{
    Node* head;
    Node* tail;
    public:
    sortedList();
    ~sortedList();
    bool isEmpty();

    void insert(int x);
    void Delete(int x);
    void display();
    void recurDisplay(Node*);
};

// constructor 
sortedList::sortedList()
{
    head=NULL;
    tail=NULL;
}

// destructor for deletiing the list
sortedList ::~sortedList()
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

// function to check whether the list is empty or not
bool sortedList::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}

// function to insert data in the list so that it remain sorted
void sortedList:: insert(int x)
{
    Node *pt = head;
    Node* a= new Node;
    a->elem = x;
    // inserting new node in list if it is empty
    if (head == NULL || head->elem >= x) 
    { 
        a->next = head; 
        head = a; 
    } 
    else 
    { 
        // inserting new node where x is greater than its previous element and smaller than the next
        while (pt->next != NULL && pt->next->elem < x) 
        { 
            pt = pt->next; 
        } 
        a->next = pt->next; 
        pt->next = a; 
    } 
    // if the inserted node is at the end then making it as tail
    if(a->next==NULL)
    {
        tail=a;
        a=NULL;
    }
}
// delete function for deleting passed element node
void sortedList :: Delete(int x)
{
    // returning if the list is empty
    if(isEmpty())
    {
        return;
    }
    Node *ptr= head;
    // traversing the list till the previou element of x
    while(ptr->next!=NULL && ptr->next->elem != x)
    {
        ptr = ptr->next;
    }
    // throwing exception if element not found
    if(ptr == tail)
    {
        throw x;
    }
    // deleting the element x if it is present
    Node* rem=ptr->next;
    ptr->next=rem->next;
    delete rem;
    // if the deleted element is tail then shifting the tail to its previous element
    if(ptr->next==NULL)
    {
        tail=ptr;
    }

}

// display function to call recursive display functin
void sortedList::display()
{
    if(isEmpty())
    {
        cout<<"Empty list!!!\n";
        return;
    }
    cout<<"List: ";
    recurDisplay(head);
    cout<<endl;
}

// recursive function to print the list recursively
void sortedList::recurDisplay(Node* ptr)
{
    cout<<ptr->elem <<" ";
    if(ptr == tail)
    {
        return ;
    }
    recurDisplay(ptr->next);
}

// driver code for demonstrating each function and its working
int main()
{
    sortedList l;
    int x;
    cout<<"Inserting data into the list:\n";
    l.insert(5);
    l.insert(10);
    l.insert(2);
    l.insert(15);
    l.insert(3);
    l.insert(7);
    l.display();
    cout<<"Enter the value to insert in the list: ";
    cin>>x;
    l.insert(x);
    l.display();
    
    try
    {
        cout<<"Enter the element to delete: ";
        cin>>x;
        l.Delete(x);
    }
    catch(int e)
    {
        cout<<"\tElement "<<e<<" don't exist.\n";
    }
    l.display();
    try
    {
        cout<<"Enter a non-existing element to delete: ";
        cin>>x;
        l.Delete(x);
    }
    catch(int e)
    {
        cout<<"\tElement "<<e<<" don't exist.\n";
    }
    l.display();
    return 0;
}
