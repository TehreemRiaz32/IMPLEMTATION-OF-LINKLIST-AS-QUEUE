#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    int getFront() {
        if (!isEmpty()) {
            return front->data;
        }
        else {
            cout << "Queue is empty. No front element." << endl;
            return -1; 
        }
    }

    void display() {
        Node* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue elements: ";
    queue.display();

    int frontValue = queue.getFront();
    cout << "Front of the queue: " << frontValue << endl;

    queue.dequeue();
    cout << "After dequeue: ";
    queue.display();

    return 0;
}
