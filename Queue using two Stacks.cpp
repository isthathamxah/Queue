#include <iostream>
#include <string>
using namespace std;

class Stack {
    int top;
    int* arr;
    int maxSize;
public:
    Stack(int size) {
        top = -1;
        maxSize = size;
        arr = new int[size];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == maxSize - 1);
    }

    void push(int newValue) {
        if (isFull()) {
            cout << "! Can't push, stack is full.\n";
            return;
        }
        arr[++top] = newValue;
    }

    int pop() {
        if (isEmpty()) {
            cout << "! Can't pop, stack is empty.\n";
            return -1;  // Indicate error
        }
        return arr[top--];
    }

    void display() {
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Queue {
    Stack s1, s2;
public:
    Queue(int size) : s1(size), s2(size) {}

    void insert(int newValue) {
        s1.push(newValue);
        cout << newValue << " is inserted in the Queue.\n";
    }

    int remove() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        if (s2.isEmpty()) {
            cout << "Queue is Empty! Can't Remove\n";
            return -1;
        }

        int removedValue = s2.pop();
        cout << removedValue << " dequeued from the queue.\n";
        return removedValue;
    }
};

int main() {
    Queue q(5);

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.remove();
    q.remove();
    q.remove();
    q.remove();  // Should print an error

    return 0;
}
