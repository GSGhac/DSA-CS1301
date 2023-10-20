#include <iostream>

// Define a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get the top element of the stack
    int peek() {
        if (top) {
            return top->data;
        }
        return -1; // Return -1 for an empty stack
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue an element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (front) {
            Node* temp = front;
            front = front->next;
            if (!front) {
                rear = nullptr; // Queue is empty
            }
            delete temp;
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Get the front element of the queue
    int peek() {
        if (front) {
            return front->data;
        }
        return -1; // Return -1 for an empty queue
    }
};

int main() {
    Stack myStack;
    Queue myQueue;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Stack operations
    std::cout << "Top element of the stack: " << myStack.peek() << std::endl;
    myStack.pop();
    std::cout << "Top element of the stack after popping: " << myStack.peek() << std::endl;

    // Queue operations
    std::cout << "Front element of the queue: " << myQueue.peek() << std::endl;
    myQueue.dequeue();
    std::cout << "Front element of the queue after dequeue: " << myQueue.peek() << std::endl;

    return 0;
}
