#include <cassert>
#include<iostream>
using namespace std;
// #include "list.h"

class list{
private:
   class node{
       public:
       int data;
       node* next;
       node* prev;
       node(int);
   };
   node* head;
   node* tail;
   int count;
public:
class iterator{
   private:
   node* pos;
   const list* container;
public:
   iterator();
   int operator*()const;
   int get() const;
   void next();
   void operator++();
   void prev();
   void operator--();
   bool equals( list::iterator) const;
   bool operator ==(list::iterator) const;
   bool operator !=(list::iterator) const;
   friend class list;
};

list();
~list();
int size () const;
int front() const;
int back() const;
void push_front(int);
void push_back(int);
void pop_front();
void pop_back();
iterator begin() const;
iterator end() const;
void insert(iterator&,int);
void erase(iterator&);
void findLargestAndSmallest();
};

// using namespace std;

// #include "list.h"

list::list(): head(nullptr), tail(nullptr), count(0)
{ }

list::~list(){
   while (count>0)pop_front();
}

list::node::node(int d): data(d), next(nullptr), prev(nullptr)
{ }

list::iterator::iterator(): pos(nullptr), container(nullptr)
{ }

// **** start == list::iterator member function

int list::iterator::get() const{
   assert( pos!=nullptr);
   return pos->data;
}

int list::iterator::operator*() const{
   return list::iterator::get();
}

void list::iterator::next(){
   if (pos==nullptr){
       pos = container->head;
   }else {
       pos= pos->next;
   }
}

void list::iterator::operator++(){
   return list::iterator::next();
}

void list::iterator::prev(){
   if (pos== nullptr){
       pos= container->tail;
   } else {
       pos =pos->prev;
   }
}

void list::iterator::operator--(){
   return list::iterator::prev();
}

bool list::iterator::equals(list::iterator iter) const{
   return container == iter.container && pos == iter.pos;
}

bool list::iterator::operator==(list::iterator iter) const{
   return list::iterator::equals(iter);
}

bool list::iterator::operator!=(list::iterator iter) const{
   return !list::iterator::equals(iter);
}

//**** end === list:: iterator member function

int list::size() const{
   return count;
}

int list::front() const {
   assert(count >0);
   return head->data;
}

int list::back() const{
   assert (count >0);
   return tail->data;
}

void list::push_front(int data){
   node*p= new node(data);
   if (count ==0){
       head=tail =p;
   } else {
       p->next=head;
       head->prev=p;
       head=p;
   }
   ++count;
}

void list::push_back( int data) {
   node* p = new node(data);
   if (count ==0){
       head=tail =p;
   } else {
       tail->next=p;
       p->prev=tail;
       tail=p;
   }
   ++count;
}

void list::pop_front(){
   assert(count>0);
   if (count==1){
       delete head;
       head = head->next;
   }else {
       node*discard = head;
       head=head->next;
       head->prev= nullptr;
       delete discard;
   }
   --count;
}

void list::pop_back(){
   assert( count >0);
   if (count==1){
       delete head;
       head = tail=nullptr;
   } else {
       node* discard = tail;
       tail =tail->prev;
       tail->next=nullptr;
       delete discard;
   }
   --count;
}

list::iterator list:: begin() const{
   iterator it;
   it.pos=head;
   it.container=this;
   return it;
}

list::iterator list:: end() const {
   iterator it;
   it.pos = nullptr;
   it.container = this;
   return it;
}

void list::insert(iterator& it , int data){
   if (it.pos == nullptr){
       // empty or append at the tail
       push_back(data);
       it.pos=tail;
   } else if (it.pos==head){
       push_front(data);
       it.pos=head;
   } else{
       node* p = new node(data);
       node* left = it.pos->prev;
       node* right = it.pos;

       left->next =p;
       p->prev=left;
       p->next=right;
       right->prev=p;
       it.pos=p;
       ++count;
   }
}

void list::erase(iterator& it){
   assert(it.pos!= nullptr);
   if (count==1){
       delete head;
       head = tail = nullptr;
       it.pos=nullptr;
   } else if (it.pos == head){
       node* discard = head;
       head=head->next;
       head->prev=nullptr;
       delete discard;
       it.pos=head;
   } else if (it.pos == tail){
       node* discard = tail;
       tail = tail->prev;
       tail->next = nullptr;
       delete discard;
       it .pos = nullptr;
   } else {
       node* discard = it.pos;
       node* left = it.pos->prev;
       node* right = it.pos->next;
       left-> next = right;
       right->prev = left;
       delete discard;
       it.pos =right;
   }
   --count;
}

void list::findLargestAndSmallest()
{
   assert(count>1);
   int max = head->data;
   int min = head->data;
   node* temp = head;
   while(temp != nullptr)
   {
      if(temp->data > max)
      {
         max = temp->data;
      }
      if(temp->data < min)
      {
         min = temp->data;
      }
      temp = temp->next;
   }
   cout<<"The largest number is "<<max<<" and the smallest number is "<<min<<".\n";
}
int main(){
   list m;
   m.push_front(10);
   m.push_front(20);//20 10
   m.push_back(30);//20 10 30
   m.push_back(40);//20 10 30
   m.pop_front();// 10 30 40
   m.pop_front();// 30 40
   m.pop_back();
   m.pop_back();
   list a;
   a.push_back(10);
   a.push_back(20);
   a.push_back(30);
   list::iterator it =a.begin();
   it.next();
  
   it.next();
   it.next();// nullptr
   it.next();// begin from the head
   list::iterator it2 = a.end();
   it2.prev();
   it2.prev();
   it2.prev();
   it2.prev();
   it2.next();
   list test;
   list::iterator it3 = test.begin();
   test.insert(it3, 11);
   it3.next();
   test.insert(it3, 12);
   it3=test.begin();
   test.insert(it3, 33);
   it3.next();
   test.insert(it3, 44);
   it3=test.begin();
   it3.next();
   it3.next();
   it3.next();
   it3=test.begin();//33 44 11 12
   test.erase(it3);//44 11 12
   it3=test.end();
   it3.prev();
   test.erase(it3);//44 11
   it3.prev();
   test.push_back(33);
   test.push_back(55);// 44 11 33 55
   it3=test.begin();
   it3.next();
   it3.next();
   test.erase(it3);// 44 11 55
   test.pop_front();//11 55
   test.pop_front();//55
   it3=test.begin();
   test.erase(it3);
   test.push_back(99);
   it3=test.begin();
   test.insert(it3, 100);// 100 99
   test.push_back(20);
   test.push_back(30);
   test.push_back(40);
   list::iterator n= test.begin();
   list::iterator n2 = test.begin();
   n2.next();
   cout<<"n2: "<< n2.get()<< endl;
   while (n!=test.end()){
       //cout<< n.get()<< " ";
       cout<< *n<< " ";// *n ===> n.operator()
       //n.next();
       ++n;
   }
   cout<< endl;
   n2.next();
   cout<< "n2: "<<n2.get()<< endl;

   for (list::iterator it = test.begin(); it != test.end(); ++ it){
       cout<< *it << " ";
   }
   cout<< endl;
   test.findLargestAndSmallest();
}