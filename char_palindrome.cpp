#include<iostream>
#include<string>
using namespace std;

class Queue {
	int front, rear;
	char* arr;
	int maxSize;
public:
	Queue(int size) {
		front = rear = -1;
		maxSize = size;
		arr = new char[size];
	}
	bool isEmpty() 
	{
		return (front == -1);
	}

	bool isFull() 
	{
		return ((rear + 1) % maxSize == front); 
	}
	void insert(char newvalue) {
		if (isFull())
		{
			cout << "Queue is full";
			return;
		}
		if (front == -1 ) {
			front =rear = 0;
		}
		else {
			rear = (rear+1) % maxSize;
		}
		arr[rear] = newvalue;
		cout << newvalue << " is inserted in the Queue " << endl;;
	}

	void remove() {
		if (isEmpty())
		{
			cout << "Queue is Empty";
			return;
		}
		cout << arr[front] << " is removed from the queue" << endl;;
		if (front == rear) {
			front = rear = -1;
		}
		else {
			front = (front + 1) % maxSize;
		}
	}

	void display() {
		int i = front;
		cout << "Queue : " << endl;
		while (true)
		{
			cout << arr[i] << endl;
			if (i == rear) {
				break;
			}
			i = (i + 1) % maxSize;
		}
		cout << endl;
	}

	bool isPalindrome() {
		if (isEmpty()) return true; // Empty queue is considered a palindrome

		int i = front, j = rear;
		while (i != j && (i + 1) % maxSize != j)
		{
			if (arr[i] != arr[j])
			{
				return false;
			}
			i = (i + 1) % maxSize;
			j = (j - 1 + maxSize) % maxSize;
		}
		return true;
	}
};

int main() {
	Queue q(4);
	q.insert('t');
	q.insert('a');
	q.insert('a');
	q.insert('t');
	q.display();
	if (q.isPalindrome()) {
		cout << "Queue is a palindrome!" << endl;
	}
	else {
		cout << "Queue is NOT a palindrome!" << endl;
	}
}
