#include <iostream>  
using namespace std;  

class Node {  
public:  
  int data;  
  Node *next;  
  
  Node(int data) {  
    this->data = data;  
    this->next = nullptr;  
  }  
};  

class LinkedList {  
private:  
  Node *head;  
  
public:  
  LinkedList() {  
    this->head = nullptr;  
  }  
  
  void insertAtBeginning(int data) {  
    Node *newNode = new Node(data);  
    newNode->next = head;  
    head = newNode;  
  }  
  
  void insertAtEnd(int data) {  
    Node *newNode = new Node(data);  
    if (head == nullptr) {  
      head = newNode;  
      return;  
    }  
    Node *temp = head;  
    while (temp->next != nullptr) {  
      temp = temp->next;  
    }  
    temp->next = newNode;  
  }  
  
  void deleteAtBeginning() {  
    if (head == nullptr) {  
      return;  
    }  
    Node *temp = head;  
    head = head->next;  
    delete temp;  
  }  
  
  void deleteAtEnd() {  
  if (head == nullptr) {  
    return;  
  }  
  if (head->next == nullptr) {  
    delete head;  
    head = nullptr;  
    return;  
  }  
  Node *temp = head;  
  while (temp->next->next != nullptr) {  
    temp = temp->next;  
  }  
  delete temp->next;  
  temp->next = nullptr;  
}  
  
void printList() {  
  Node *temp = head;  
  while (temp != nullptr) {  
    cout << temp->data << " ";  
    temp = temp->next;  
  }  
  cout << endl;  
}  
};  
  
int main() {  
LinkedList List;  

List.insertAtBeginning(3);  
List.insertAtBeginning(2);  
List.insertAtBeginning(1);  

List.insertAtEnd(4);  
List.insertAtEnd(5);  
List.insertAtEnd(6);  

cout << "Original list: ";  
List.printList();  

List.deleteAtBeginning();  

cout << "List after deleting a node at the beginning: ";  
List.printList();  

List.deleteAtEnd();  

cout << "List after deleting a node at the end: ";  
List.printList();  
  
return 0;  
}