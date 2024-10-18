#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class MyQueue {
    int size;
    int front;
    int rear;
    int *arr;

public:
    MyQueue() {
        size = 5000;
        arr = new int[size];
        front = rear = 0;
    }

    ~MyQueue() {
        delete[] arr;
    }

    void enqueue(int element) {
        if (rear == size) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        arr[rear] = element;
        rear++;
    }

    int dequeue() {
        if (front == rear) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; 
        } 
        int ans = arr[front];
        arr[front] = -1;
        front++;
        if (front == rear) {
            front = rear = 0;
        }
        return ans;
    }

    int qfront() {
        if (front == rear) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isempty() {
        return front == rear;
    }
};

int main() {
   
    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front of the queue: " << q.qfront() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front of the queue after dequeue: " << q.qfront() << endl;
    return 0;
}
