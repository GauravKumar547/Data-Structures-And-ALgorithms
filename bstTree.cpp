#include<iostream>
using namespace std;

// creating a node class using templates
template <class T>
class Node
{
    private: 
    T data;
    Node<T>* right;
    Node<T>* left;

    public:
    // constructor for Node to set the left and right as null
    Node<T>()
    {
        right = NULL;
        left = NULL;
    }
    // making bstTree class as friend of node so that 
    // it can access private members of node class
    template <class U>
    friend class bstTree;
};

// bstTree class of template type 
template <class T>
class bstTree
{
    Node<T>* root;
    public:
    bstTree<T>();
    ~bstTree<T>();
    void destructorRecur(Node<T>*);

    void insert(T);
    Node<T>* insertNode(Node<T>*, T);
    
    void Delete(T);
    Node<T>* inOrderSuccessor(Node<T>*);
    Node<T>* deleteNode(Node<T>*, T);

    void display();
    void preOrder(Node<T>*);
};

// constructor of bstTree
template <class T>
bstTree<T>::bstTree()
{
    root=NULL;
}

// destructor calling recursive function destructorRecur to delete the tree
template <class T>
bstTree<T>::~bstTree()
{
    destructorRecur(root);
    cout<<"\nDestructor called\n";
}

// recursive function to delete the tree
template <class T>
void bstTree<T>::destructorRecur(Node<T>* r)
{
    // if r node exist as leaf then delete else call the function
    // for its left and right nodes
    if(r) 
    {
		if( (r->left == NULL) && (r->right == NULL) )
        {
			delete r;
			r = NULL;
		}
        else 
        {
			destructorRecur(r->left);
			destructorRecur(r->right);
		} 
	} 
    return;
}

// insert function to call the recursive insertNode function
template <class T>
void bstTree<T>::insert(T val)
{
    root = insertNode(root, val);
}

// recursive function to insert nodes into the tree
template <class T>
Node<T>* bstTree<T>::insertNode(Node<T>* r, T val)
{
    // if passed node is NULL then adding the node with value val
    if(r == NULL)
    {
        Node<T>* temp = new Node<T>;
        temp->data = val;
        return temp;
    }
    // if val is less than the value of data in the passed node's data 
    // then calling the insertNode function for left node
    if(val < r->data)
    {
        r->left = insertNode(r->left, val);
    }
    // if val is greater than the value of data in the passed node's data 
    // then calling the insertNode function for right node
    else if(val > r->data)
    {
        r->right = insertNode(r->right, val);
    }
    else
    {
        // if the value for insertion pre-exists then throw exception
        throw val;
    }
    return r;
}

// function to call the deleteNode function to delete the node
template <class T>
void bstTree<T>::Delete(T val)
{
    
    if(root == NULL)
        return;
    else
        root = deleteNode(root, val);
}

// function to find the inorder successor for delete function
template <class T>
Node<T>* bstTree<T>::inOrderSuccessor(Node<T>* r)
{
    Node<T>* temp = r;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// recursive deleteNode function to delete the node recursively
template <class T>
Node<T>* bstTree<T>::deleteNode(Node<T>* r, T val)
{
    // throwing the exception if required value is not found
    if (r == NULL)
        throw val;
    // if val is less than the value of data in the passed node's data 
    // then calling the deleteNode function for left node
    if (val < r->data)
        r->left = deleteNode(r->left, val);
    // if val is greater than the value of data in the passed node's data 
    // then calling the deleteNode function for right node
    else if (val > r->data)
        r->right = deleteNode(r->right, val);
    else {
        // for deleting if the node has one right child
        if (r->left == NULL) 
        {
            Node<T>* temp = r->right;
            delete(r);
            return temp;
        }
        // for deleting if the node has one left child
        else if (r->right == NULL ) 
        {
            Node<T>* temp = r->left;
            delete(r);
            return temp;
        }
        // for node having 2 childs calling the inorderSuccessor function and 
        // deleteNode for performing deletion of required node
        Node<T>* temp = inOrderSuccessor(r->right);
        r->data = temp->data;
        r->right = deleteNode(r->right, temp->data);
    }
    return r;
}

// display function to display the contents of tree in preorder traversal
template <class T>
void bstTree<T>::display()
{
    if(root == NULL)
    {
        cout<<"Empty Tree!!\n";
    }
    else
    {
        preOrder(root);
    }
    cout<<endl;
}

// recursing function for preorder traversal
template <class T>
void bstTree<T>::preOrder(Node<T>* r)
{
    if(r == NULL)
    {
        return ;
    }
    cout<< r->data<<" ";
    preOrder(r->left);
    preOrder(r->right);
}

// driver code for demonstrating each function and its working
int main()
{
    bstTree<int> B;
    int x;
    cout<<"Inserting data into the tree:\n";
    B.insert(10);
    B.insert(2);
    B.insert(3);
    B.insert(9);
    B.insert(5);
    B.display();
    // try/catch for handling the exceptions thrown by the insert() function
    try
    {
        cout<<"Enter an element to insert: ";
        cin>>x;
        B.insert(x);
    }
    catch(int e)
    {
        cout<<"Element with value "<<e<< " already exists\n";
    }
    B.display();
    try
    {
        cout<<"Enter a pre-existing element to insert: ";
        cin>>x;
        B.insert(x);
    }
    catch(int e)
    {
        cout<<"Element with value "<<e<< " already exists\n";
    }
    B.display();

    // try/catch for handling the exceptions thrown by the delete() function
    try
    {
        
        cout<<"Enter the element to delete: ";
        cin>>x;
        B.Delete(x);
    }
    catch(int e)
    {
        cout<<"Element with value "<<e<< " don't exist\n";
    }
    
    B.display();

    // try/catch for handling the exceptions thrown by the delete() function 
    try
    {
        cout<<"Enter a non-existing element to delete: ";
        cin>>x;
        B.Delete(x);
    }
    catch(int e)
    {
        cout<<"Element with value "<<e<< " don't exist\n";
    }
    B.display();
    return 0;
}