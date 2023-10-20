#include <iostream>

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int capacity) : capacity(capacity), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Function to enqueue an element into the circular queue
    bool enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue is full. Enqueue operation failed." << std::endl;
            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
        return true;
    }

    // Function to dequeue an element from the circular queue
    bool dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Dequeue operation failed." << std::endl;
            return false;
        }

        front = (front + 1) % capacity;
        size--;
        return true;
    }

    // Function to get the front element of the circular queue
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Peek operation failed." << std::endl;
            return -1;
        }

        return arr[front];
    }

    // Function to check if the circular queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the circular queue is full
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    std::cout << "Front element: " << cq.peek() << std::endl;

    cq.dequeue();
    cq.enqueue(50);

    std::cout << "Front element after dequeuing and enqueuing: " << cq.peek() << std::endl;

    return 0;
}
