#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

class Node
{
    string data;
    int height;
    int freqCount;
    Node *right;
    Node *left;

public:
    Node()
    {
        right = NULL;
        left = NULL;
        height = 1;
        freqCount = 1;
    }
    friend class avlTree;
};

class avlTree
{
    Node *root;

public:
    avlTree();

    int maxFind(int, int);
    int heightFind(Node *);
    int getBalance(Node *);

    Node *leftRotate(Node *);
    Node *rightRotate(Node *);

    void search(string);

    void insert(string);
    Node *insertNode(Node *, string);

    void display();
    void inOrder(Node *);
};

avlTree::avlTree()
{
    root = NULL;
}

void avlTree::insert(string val)
{
    root = insertNode(root, val);
}

void avlTree::display()
{
    if (root == NULL)
    {
        cout << "Empty Tree!!\n";
    }
    else
    {
        cout << endl
             << setw(15) << left << "Words"
             << ": Frequency\n";
        inOrder(root);
    }
}
void avlTree::inOrder(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    inOrder(r->left);
    cout << setw(15) << left << r->data << ":   " << r->freqCount << endl;
    inOrder(r->right);
}

int avlTree::maxFind(int a, int b)
{
    return ((a > b) ? a : b);
}

int avlTree::heightFind(Node *r)
{
    if (r == NULL)
        return 0;
    return r->height;
}

int avlTree::getBalance(Node *r)
{
    if (r == NULL)
    {
        return 0;
    }
    return (heightFind(r->left) - heightFind(r->right));
}

Node *avlTree::leftRotate(Node *r)
{
    Node *temp = r->right;
    Node *temp2 = temp->left;

    temp->left = r;
    r->right = temp2;

    temp->height = 1 + maxFind(heightFind(temp->left), heightFind(temp->right));
    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    return temp;
}

Node *avlTree::rightRotate(Node *r)
{
    Node *temp = r->left;
    Node *temp2 = temp->right;

    temp->right = r;
    r->left = temp2;

    temp->height = 1 + maxFind(heightFind(temp->left), heightFind(temp->right));
    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    return temp;
}

Node *avlTree::insertNode(Node *r, string val)
{
    if (r == NULL)
    {
        Node *temp = new Node;
        temp->data = val;
        return temp;
    }
    if (val < r->data)
    {
        r->left = insertNode(r->left, val);
    }
    else if (val > r->data)
    {
        r->right = insertNode(r->right, val);
    }
    else
    {
        return r;
    }

    r->height = 1 + maxFind(heightFind(r->left), heightFind(r->right));

    int balance = getBalance(r);

    if (balance > 1 && val < r->left->data)
    {
        // ll
        return rightRotate(r);
    }

    if (balance > 1 && val > r->left->data)
    {
        // lr
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    if (balance < -1 && val > r->right->data)
    {
        // rr
        return leftRotate(r);
    }

    if (balance < -1 && val < r->right->data)
    {
        // rl
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

void avlTree::search(string val)
{
    Node *temp = root;
    transform(val.begin(), val.end(), val.begin(), ::tolower);
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            temp->freqCount++;
            return;
        }
        else if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    insert(val);
}

int main()
{
    avlTree A;
    string word = "";
    char ch;
    string fileName;
    cout << "\nEnter the file to read from: ";
    getline(cin, fileName);
    fstream fin;
    fin.open(fileName);
    while (fin.get(ch))
    {

        while (isalpha(ch))
        {
            word += ch;
            ch = fin.get();
        }
        if (word != "")
        {
            A.search(word);
        }
        word = "";
    }
    cout << "\nThe frequency of words is given below:";
    A.display();
    return 0;
}
