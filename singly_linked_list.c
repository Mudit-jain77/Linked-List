#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
//constructor
    Node (int data)
  {
  this-> data = data;
  this-> next = NULL;
      
  }
//destructor
//  ~Node() {
//         int value = this -> data;
//         //memory free
//         if(this->next != NULL) {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
};
void insertAtHead(Node * &head , int d){
    Node * temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node * &tail , int d){
    Node * temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPositition(Node * &head ,Node* & tail , int position , int d){
    Node * temp = head ; 
    int cnt = 1;
    if(position == 1){
        insertAtHead(head , d);
        return;
    }
    while(cnt < position - 1){
        temp = temp -> next;
        cnt ++ ;
    }
    if(temp -> next == NULL){
        insertAtTail(tail , d);
        return ;
    }
    Node * nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next ;
    temp -> next = nodeToInsert;
}

void deleteNode(int position , Node * &head){
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr -> next == NULL){
            tail = prev;
        }
        
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node *  &head){
    // cout << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main ()
{
  Node *node1 = new Node (10);
//   cout << node1->data << endl;
//   cout << node1->next << endl;
  
  Node*head = node1;
  Node*tail = node1;
  
//   print(head);
//   insertAtHead(head , 12);
  
//   print(head);
  
//   insertAtTail(tail , 15);
//   print(head);

   insertAtTail(tail , 12);
   insertAtTail(tail , 15);
  
//   //print(head);
  
//   insertAtPositition(head ,tail , 4 ,22);
//   print(head);


deleteNode(2 , head);
print(head);
  return 0;
}
