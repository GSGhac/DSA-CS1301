// Implementation of doubly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        this->head = nullptr;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (this->head == nullptr) {
            this->head = new_node;
        } else {
            Node* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prev = current;
        }
    }

    void prepend(int data) {
        Node* new_node = new Node(data);
        if (this->head == nullptr) {
            this->head = new_node;
        } else {
            this->head->prev = new_node;
            new_node->next = this->head;
            this->head = new_node;
        }
    }

    void insert_after(int data, int target) {
        Node* new_node = new Node(data);
        while(current!= nullptr) {
            if (current->data == target) {
                new_node->next = current->next;
                new_node->prev = current;
                current->next = new_node;
                if (new_node->next != nullptr) {
                    new_node->next->prev = new_node;
                }
                return;
            }
        }
    }

    void insert_before(int data, int target) {
        Node* new_node = new Node(data);
        if (this->head == nullptr) {
            this->head = new_node;
        } else {
            Node* current = this->head;
            while (current != nullptr) {
                if (current->data == target) {
                    new_node->next = current;
                    new_node->prev = current->prev;
                    if (current->prev != nullptr) {
                        current->prev->next = new_node;
                    } else {
                        this->head = new_node;
                    }
                    current->prev = new_node;
                    return;
                }
                current = current->next;
            }
        }
    }

    void delete_node(int data) {
        if (this->head == nullptr) {
            return;
        }
        Node* current = this->head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current->prev == nullptr) {
                    this->head = current->next;
                    if (this->head != nullptr) {
                        this->head->prev = nullptr;
                    }
                } else {
                    current->prev->next = current->next;
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void print_list() {
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(4);
    dll.append(7);
    dll.append(2);
    dll.prepend(1);
    dll.append(9);
    dll.append(7);
    dll.prepend(6);
    dll.print_list();
    dll.delete_node(2);
    dll.print_list();
    return 0;
}