#include <iostream>
using namespace std;

class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x)
    {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0 && rear != size - 1) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty()) {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return ans;
    }

    int popRear()
    {
        if (isEmpty()) {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1));
    }
};

int main() {
    Deque dq(5);

    cout << "Push 10 to rear: " << dq.pushRear(10) << endl;
    cout << "Push 20 to rear: " << dq.pushRear(20) << endl;
    cout << "Push 5 to front: " << dq.pushFront(5) << endl;
    cout << "Push 1 to front: " << dq.pushFront(1) << endl;

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    cout << "Popped from front: " << dq.popFront() << endl;
    cout << "Popped from rear: " << dq.popRear() << endl;

    cout << "Push 30 to rear: " << dq.pushRear(30) << endl;
    cout << "Push 15 to front: " << dq.pushFront(15) << endl;

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    return 0;
}
