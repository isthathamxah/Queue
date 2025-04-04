#include <iostream>
#include <string>
using namespace std;

template<class T>
class Queue {
	int front, rear;
	T* arr;
	int maxSize;
	int count;
public:
	Queue(int size) {
		front = rear = -1;
		maxSize = size;
		arr = new T[size];
		count = 0;
	}

	int getPriority(T item) {
		if (item[0] == 'P' || item[0] == 'p') return 3;
		if (item[0] == 'T' || item[0] == 't') return 2;
		else return 1;
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return ((rear + 1) % maxSize == front);
	}

	void insert(T newvalue) {
		if (isFull()) {
			cout << "Queue is full" << endl;
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
			arr[rear] = newvalue;
			cout << newvalue << " is inserted in the Queue." << endl;
			count++;
			return;
		}

		int i;
		for (i = rear; (i != front - 1 + maxSize) % maxSize && getPriority(arr[i]) < getPriority(newvalue); i = (i - 1 + maxSize) % maxSize) {
			arr[(i + 1) % maxSize] = arr[i];
		}

		arr[(i + 1) % maxSize] = newvalue;
		rear = (rear + 1) % maxSize;
		cout << newvalue << " is inserted in the Queue." << endl;
		count++;
	}

	void remove() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		}
		cout << arr[front] << " is removed from the queue" << endl;

		if (front == rear) {
			front = rear = -1;
		}
		else
		{
			front = (front + 1) % maxSize;
		}
		count--;
	}

	void display() 
	{
		if (isEmpty())
		{
			cout << "Queue is empty." << endl;
			return;
		}

		cout << "Queue: " << endl;
		for (int i = front;; i = (i + 1) % maxSize)
		{
			cout << arr[i] << endl;
			if (i == rear) break;
		}
		cout << endl;
	}

	~Queue() {
		delete[] arr;
	}
};

int main() {
	Queue<string>p(5);
	p.insert("Student1");
	p.insert("Student2");
	p.insert("parent");
	p.insert("teacher");

	p.display();

	p.remove();
	p.display();
	return 0;
}
