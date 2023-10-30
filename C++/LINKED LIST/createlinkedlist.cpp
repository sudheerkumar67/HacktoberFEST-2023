#include<iostream>
using namespace std;

class Node {
    public:

 int val;
 Node* next;

  Node (int data){
    val = data;
    next = NULL;
  }
};
 
 class  linklist{
    public:
    Node  * head;
    linklist(){

   head = NULL;
    }

void insertattail(int value){
    Node* new_node = new Node(value);
    if (head == NULL){
        head = new_node;// head ko hi new node maan liya 
        return;
    }
    Node * temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
 } 
    temp->next= new_node;

    }
void display(){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;

    } cout<< "NULL"<<endl;
}
 };
 int main()
{
 

  linklist ll;
 
   ll.insertattail(1); 
   ll.insertattail(2);
   ll.insertattail(3);
   ll.insertattail(4);
   ll.insertattail(5);
   ll.insertattail(6);
   
   ll.display();

   return 0 ;
}