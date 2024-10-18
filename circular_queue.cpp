#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:

    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    
    int enqueue(int element) {
       
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size))) {
            cout << "Queue is full" << endl;
            return -1;
        }
        else if (front == -1) { 
            front = rear = 0;
            arr[rear] = element;
        }
        else if (rear == size - 1 && front != 0) { 
            rear = 0;
            arr[rear] = element;
        }
        else { 
            rear++;
            arr[rear] = element;
        }
        return 0;
    }

   
    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int data = arr[front];
        arr[front] = -1; 

        if (front == rear) { 
            front = rear = -1;
        }
        else if (front == size - 1) { 
            front = 0;
        }
        else {
            front++;
        }
        return data;
    }

   
    bool is_empty() const {
        return (front == -1);
    }

    
    bool is_full() const {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size));
    }

   
    void display() const {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } 
        else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
