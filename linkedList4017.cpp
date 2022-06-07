/*
    NAME = GAURAV KUMAR
    COURSE = BSC(H) COMPUTER SCIENCE (IIIrd SEM)
    ROLL NO. = 19HCS4017
    SUBJECT = DATA STRUCTURES
    PROGRAM = Singly linked list implementation
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
    string elem;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }

    friend class linkedList;
};

class linkedList
{
    Node *head;

public:
    linkedList();
    ~linkedList();
    void removeNode(int pos);
    void removeFront();

    void addNode(const string &e, int pos);
    void display();

    Node *searchElem(string s);
    void concatenate(linkedList &l2);
};

linkedList::linkedList() : head(NULL) {}

linkedList ::~linkedList()
{
    if (head != NULL)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *del = temp;
            temp = temp->next;
            delete del;
        }
    }
}
void linkedList::addNode(const string &e, int pos)
{
    int count = 1;
    Node *pt = head;
    Node *a = new Node;
    a->elem = e;

    if (pos == 1)
    {
        a->next = head;
        head = a;
        return;
    }

    while (count < pos - 1 && pt != NULL)
    {
        count++;
        pt = pt->next;
    }

    a->next = pt->next;
    pt->next = a;
}

void linkedList ::removeFront()
{
    Node *rem = head;
    head = rem->next;
    delete rem;
}

void linkedList ::removeNode(int pos)
{
    int count = 1;
    Node *ptr = head;
    while (count < pos - 1 && ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    Node *rem = ptr->next;
    ptr->next = rem->next;
    delete rem;
}

void linkedList::display()
{
    if (head == NULL)
        cout << "Empty list";
    else
    {
        Node *pt = head;
        while (pt != NULL)
        {
            cout << pt->elem << " ";
            pt = pt->next;
        }
    }
    cout << endl
         << endl;
}

void linkedList ::concatenate(linkedList &l2)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = l2.head;
    l2.head = NULL;
}
Node *linkedList ::searchElem(string s)
{
    int count = 1;
    Node *pt = head;
    while (pt != NULL)
    {
        if (pt->elem == s)
        {
            cout << "The required element " << s << " is present at position: " << count;
            return pt;
        }
        pt = pt->next;
        count++;
    }
    return NULL;
}

void takeInput(linkedList &l, string second = "")
{
    string s;
    int i = 1;
    cout << "Enter the the values in the " << second << " list(to stop enter '.'): ";
    cin >> s;
    while (s != ".")
    {
        l.addNode(s, i);
        cin >> s;
        i++;
    }
    cout << "Your entered list: ";
    l.display();
}

int main()
{
    int choice;
    char cont;
    string str;
    do
    {
        cout << "\nChoose what you want to perform: \n";
        cout << "1. Insert element in the beginning of linked list\n";
        cout << "2. Insert an element at given position of linked list\n";
        cout << "3. Remove an element from beginning of the linked list\n";
        cout << "4. Remove an element from given position of linked list\n";
        cout << "5. Search an element in the linked list\n";
        cout << "6. Concatenate two linked list\n";
        cout << "Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string x;
            linkedList ls;
            takeInput(ls);
            cout << "Enter the element to insert in beginning: ";
            cin >> x;
            ls.addNode(x, 1);
            cout << "The linked list after insertion: ";
            ls.display();
            break;
        }
        case 2:
        {
            string x;
            int j;
            linkedList ls;
            takeInput(ls);
            cout << "Enter the position on which you want to insert: ";
            cin >> j;
            cout << "Enter the element to insert: ";
            cin >> x;
            ls.addNode(x, j);
            cout << "The linked list after insertion: ";
            ls.display();
            break;
        }
        case 3:
        {
            linkedList ls;
            takeInput(ls);
            cout << "The linked list after removal of first element: ";
            ls.removeFront();
            ls.display();
            break;
        }
        case 4:
        {
            int j;
            linkedList ls;
            takeInput(ls);
            cout << "Enter the position from which you want to remove the element: ";
            cin >> j;
            cout << "The linked list after removal of " << j << "th element: ";
            ls.removeNode(j);
            ls.display();
            break;
        }
        case 5:
        {
            linkedList ls;
            Node *p;
            takeInput(ls);
            cout << "Enter the element to search: ";
            cin >> str;
            p = ls.searchElem(str);
            if (p != NULL)
                cout << " and at the node with address: " << p << endl;
            else
            {
                cout << "Not found\n";
            }

            break;
        }
        case 6:
        {
            linkedList ls;
            takeInput(ls, "first");
            linkedList ls1;
            takeInput(ls1, "second");
            ls.concatenate(ls1);
            cout << "The list after concatenation is: ";
            ls.display();
            break;
        }
        default:
            cout << "Invalid choice!!!";
        }
        cout << "Do you want to continue(Y/N):";
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');

    return 0;
}