#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

class Node
{
    string data;
    int height;
    Node* right;
    Node* left;
    public:
    Node()
    {
        right = NULL;
        left = NULL;
        height = 1;
    }
    friend class avlTree;
};

class avlTree
{
    Node* root;
    public:
    avlTree();

    int maxFind(int, int);
    int heightFind(Node*);
    int getBalance(Node*);

    Node* leftRotate(Node*);
    Node* rightRotate(Node*);

    void insert(string);
    Node* insertNode(Node*, string);
    
    void deleteNode(string);
    Node* deleteNode2(Node*, string);

    Node* inOrderSuccessor(Node*);
    void display();
    void inOrder(Node*);
};

avlTree::avlTree()
{
    root=NULL;
}

void avlTree::insert(string val)
{
    root = insertNode(root, val);
}

void avlTree::display()
{
    if(root == NULL)
    {
        cout<<"Empty Tree!!";
    }
    else
    {
        inOrder(root);
    }
    cout<<endl;
}
void avlTree::inOrder(Node* r)
{
    if(r == NULL)
    {
        return;
    }
    inOrder(r->left);
    cout<< r->data<<endl;
    inOrder(r->right);
}

int avlTree::maxFind(int a, int b)
{
    return ((a > b) ? a : b);
}

int avlTree::heightFind(Node* r)
{
    if(r==NULL)
        return 0;
    return r->height;
}

int avlTree::getBalance(Node* r)
{
    if(r == NULL)
    {
        return 0;
    }
    return (heightFind(r->left)-heightFind(r->right));
}

Node* avlTree::leftRotate(Node* r)
{
    Node* temp = r->right;
    Node* temp2 = temp->left;

    temp->left = r;
    r-> right = temp2;

    temp->height = 1 + maxFind(heightFind(temp->left), heightFind(temp->right));
    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    return temp;
}

Node* avlTree::rightRotate(Node* r)
{
    Node* temp = r->left;
    Node* temp2 = temp->right;

    temp->right = r;
    r-> left = temp2;

    temp->height = 1 + maxFind(heightFind(temp->left), heightFind(temp->right));
    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    return temp;
}

Node* avlTree::insertNode(Node* r, string val)
{
    if(r == NULL)
    {
        Node* temp = new Node;
        temp->data = val;
        return temp;
    }
    if(val < r->data)
    {
        r->left = insertNode(r->left, val);
    }
    else if(val > r->data)
    {
        r->right = insertNode(r->right, val);
    }
    else
    {
        return r;
    }
    
    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    int balance = getBalance(r);

    if(balance > 1 && val < r->left->data)
    {
        // ll
        return rightRotate(r);
    }

    if(balance > 1 && val > r->left->data)
    {
        // lr
        r->left  = leftRotate(r->left);
        return rightRotate(r);
    }

    if(balance < -1 && val > r->right->data)
    {
        // rr
        return leftRotate(r);
    }

    if(balance < -1 && val < r->right->data)
    {
        // rl
        r->right  = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

void avlTree:: deleteNode(string val)
{
    root = deleteNode2(root, val);
}

Node* avlTree::inOrderSuccessor(Node* r)
{
    Node* demo = r;
    while(demo->left != NULL)
    {
        demo = demo->left;
    }
    return demo;
}
Node* avlTree::deleteNode2(Node* r, string val)
{
    if(r == NULL)
    {
        return r;
    }
    if(val < r->data)
    {
        r->left = deleteNode2(r->left, val);
    }
    else if(val > r->data)
    {
        r->right = deleteNode2(r->right, val);
    }
    else
    {
        if((r->left == NULL || r->right == NULL) && (r->data == val) )
        {
            Node* temp = (r->left != NULL) ? r->left : r->right;
            if(temp == NULL)
            {
                temp = r;
                r = NULL;
            }
            else
            {
                *r = *temp;
            }
            delete temp;
        }
        else
        {
            Node* temp = inOrderSuccessor(r->right);
            r->data = temp->data;
            r->right = deleteNode2(r->right, temp->data);

        }
        
    }
    if(r == NULL)
    {
        return r;
    }

    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    int balance = getBalance(r);

    if(balance > 1 && val < r->left->data)
    {
        // ll
        return rightRotate(r);
    }

    if(balance > 1 && val > r->left->data)
    {
        // lr
        r->left  = leftRotate(r->left);
        return rightRotate(r);
    }

    if(balance < -1 && val > r->right->data)
    {
        // rr
        return leftRotate(r);
    }

    if(balance < -1 && val < r->right->data)
    {
        // rl
        r->right  = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

string main()
{
    return 0;
}
