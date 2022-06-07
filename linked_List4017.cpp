/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Singly linked list implementation with head and tail
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    string elem;
    Node *next;
    Node()
    {
        next=NULL;
    }

    friend class linkedList;
};

class linkedList
{
    Node* head;
    Node* tail;
    public:
    linkedList();
    ~linkedList();
    void removeNode(int pos) ;
    void removeFront();
    void removeTailNode();

    void addTailNode(const string & e);
    void addNode(const string & e, int pos);
    
    friend ostream& operator << (ostream & out, linkedList l1);
    
    void reverseList();
    Node* searchElem(string s);
    void concatenate(linkedList& l2);
};

linkedList::linkedList()
{
    head=NULL;
    tail=NULL;
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

void linkedList::addTailNode(const string & e)
{
    Node* a = new Node;
    a->elem = e;
    if(head==NULL||tail==NULL)
    {
        head=a;
        tail=a;
    }
    else
    {
        tail->next = a;
        tail = a;
        a=NULL;
    }
     
}
void linkedList::addNode(const string& e, int pos)
{
    int count=1;
    Node *pt = head;
    Node *a= new Node;
    a->elem = e;

    if(pos==1)
    {
        a->next=head;
        head= a;
        return;
    }

    while(count<pos-1 && pt!=NULL)
    {
        count++;
        pt = pt-> next;
    }

    a-> next = pt-> next;
    pt-> next = a;
    if(a->next==NULL)
    {
        tail=a;
        a=NULL;
    }
    
}

void linkedList :: removeTailNode()
{
    Node* pt = head;
    Node* rem =tail;
    while(pt->next!=tail)
    {
        pt = pt->next;
    }
    tail=pt;
    pt->next=NULL;
    delete rem;
}

void linkedList ::removeFront()
{
    Node* rem= head;
    head= rem->next;
    delete rem;
}

void linkedList :: removeNode(int pos)
{
    int count=1;
    Node *ptr= head;
    while(count<pos-1 && ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    Node* rem=ptr->next;
    ptr->next=rem->next;
    delete rem;
    if(ptr->next==NULL)
    {
        tail=ptr;
    }
}


ostream& operator << (ostream & out, linkedList l1)
{
    int count=0;
    if(l1.head==NULL) 
    {
        out<<"Empty list";
    }  
    else
    {
        Node* pt=l1.head;
        while(pt!=NULL)
        {
            out<<pt->elem<<" ";
            pt=pt->next;
            count++;
        }
    }
    out<<"\nThe total number of nodes are: "<<count<<"\n\n";
    l1.head = l1.tail = NULL;
    return out;

}

void linkedList ::concatenate(linkedList& l2)
{
    Node* ptr = tail;
    ptr->next = l2.head;
    tail=l2.tail;
    l2.head = l2.tail = NULL;
}
Node* linkedList :: searchElem(string s)
{
    int count=1;
    Node* pt = head;
    while(pt!=NULL)
    {
        if(pt->elem == s)
        {
            cout<<"The required element "<<s<<" is present at position: "<<count;
            return pt;
        }
        pt=pt->next;
        count++;
    }
    return NULL;
}

void linkedList :: reverseList()
{
    if(head==NULL)
        return;
    Node* ptr = head;
    Node* pt = head->next;
    if(pt==NULL)
        return;
    while (pt!=NULL)
    {
        Node* p= pt->next;
        pt->next=ptr;
        ptr=pt;
        pt=p;
    }
    head->next =NULL;
    tail=head;
    head=ptr;
    
}

void takeInput(linkedList& l,string second="")
{
    string s;
    cout<<"Enter the the values in the "<<second<<" list(to stop enter '.'): ";
    cin>>s;
    while(s!=".")
    {
        l.addTailNode(s);
        cin>>s;
    }
    cout<<"Your entered list: ";
    cout<<l;
}


int main()
{
    int choice;
    char cont;
    string str;
    do
    {
        cout<<"\nChoose what you want to perform: \n";
        cout<<"1. Insert element in the beginning of linked list\n";
        cout<<"2. Insert an element at the end of the linked list\n";
        cout<<"3. Insert an element at given position of linked list\n";
        cout<<"4. Remove an element from beginning of the linked list\n";
        cout<<"5. Remove an element from the tail of the linked list\n";
        cout<<"6. Remove an element from given position of linked list\n";
        cout<<"7. Search an element in the linked list\n";
        cout<<"8. Concatenate two linked list\n";
        cout<<"9. Reversing the linked list\n";
        cout<<"Your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                string x;
                linkedList ls;
                takeInput(ls);
                cout<<"Enter the element to insert in beginning: ";
                cin>>x;
                ls.addNode(x,1);
                cout<<"The linked list after insertion: ";
                cout<<ls;
                break;
            }
            case 2:
            {
                string x;
                linkedList ls;
                takeInput(ls);
                cout<<"Enter the element to insert in end: ";
                cin>>x;
                ls.addTailNode(x);
                cout<<"The linked list after insertion: ";
                cout<<ls;
                break;
            }
            case 3:
            {  
                string x;
                int j; 
                linkedList ls;
                takeInput(ls);
                cout<<"Enter the position on which you want to insert: ";
                cin>>j;
                cout<<"Enter the element to insert: ";
                cin>>x;
                ls.addNode(x,j);
                cout<<"The linked list after insertion: ";
                cout<<ls;
                break;
            }
            case 4:
            {
                linkedList ls;
                takeInput(ls);
                cout<<"The linked list after removal of first element: ";
                ls.removeFront();
                cout<<ls;
                break;
            }
            case 5:
            {
                linkedList ls;
                takeInput(ls);
                cout<<"The linked list after removal of element from the tail: ";
                ls.removeTailNode();
                cout<<ls;
                break;
            }
            case 6:
            {
                int j;
                linkedList ls;
                takeInput(ls);
                cout<<"Enter the position from which you want to remove the element: ";
                cin>>j;
                cout<<"The linked list after removal of "<<j<<"th element: ";
                ls.removeNode(j);
                cout<<ls;
                break;
            }
            case 7:
            {
                linkedList ls;
                Node *p;
                takeInput(ls);
                cout<<"Enter the element to search: ";
                cin>>str;
                p = ls.searchElem(str);
                if(p!=NULL)
                cout<<" and at the node with address: "<<p<<endl;
                else
                {
                    cout<<"Not found\n";
                }
                
                break;
            }
            case 8:
            {
                linkedList ls;
                takeInput(ls, "first");
                linkedList ls1;
                takeInput(ls1,"second");
                ls.concatenate(ls1);
                cout<<"The list after concatenation is: ";
                cout<<ls;
                break;
            }
            case 9:
            {
                linkedList ls;
                takeInput(ls);
                ls.reverseList();
                cout<<"The list after reversing: ";
                cout<<ls;
                break;
            }
            default:
                cout<<"Invalid choice!!!";
        }
        cout<<"Do you want to continue(Y/N):";
        cin>>cont;
    }while(cont=='Y'||cont=='y');
    
    return 0;
}