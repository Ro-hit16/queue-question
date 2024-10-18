#include <stack>
#include <iostream>
using namespace std;

class Queue {
    stack<int> s1, s2;
    int maxSize;
    
public:
    Queue(int size) {
        maxSize = size;
    }

    bool isFull() {
        return (s1.size() + s2.size()) == maxSize;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        s1.push(val);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    int front() {
        if (!s2.empty()) {
            return s2.top();
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.empty() ? -1 : s2.top();
    }
};

int main() {
    Queue q(3);  

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);  

    cout << q.dequeue() << endl;
    q.enqueue(5);  

    
}
