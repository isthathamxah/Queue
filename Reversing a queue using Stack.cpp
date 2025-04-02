#include<iostream>
#include<string>
using namespace std;

class Stack 
{
	int top;
	int* arr;
	int maxSize;
public:
	Stack(int size) 
	{
		top = -1;
		maxSize = size;
		arr = new int[size];
	}

	bool isEmpty()
	{
		
		return (top == -1);
	}

	bool isFull()
	{
		return (top==maxSize-1);
	}

	void push(int newValue)
	{
		if (isFull())
		{
			cout << "!  Can't push";
		}
		arr[++top] = newValue;
		cout << newValue << " is pushed into Stack" << endl;
	}

	int pop()
	{
		if (isEmpty()) {
			cout << "! Can't pop";
		}
		cout << arr[top] << " is popped from the stack" << endl;
		return arr[top--];
	}

	void display()
	{
		for (int i = top; i >= 0; i--) 
		{
			cout << "Stack Elements : " << endl;
			cout << arr[i] << endl;
		}
	}
};
class Queue {
	int front, rear;
	int* arr;
	int maxSize;
public:
	Queue(int size) {
		front = rear = -1;
		maxSize = size;
		arr = new int[size];
	}
	bool isEmpty() 
	{
		return (front == -1);
	}

	bool isFull() 
	{
		return ((rear + 1) % maxSize == front); 
	}
	void insert(int newvalue) {
		if (isFull())
		{
			cout << "Queue is full : ";
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

	int remove() 
	{
		if (isEmpty())
		{
			cout << "Queue is Empty : ";
			return -1;
		}
		int temp = arr[front];
		cout << temp << " is removed from the queue " << endl;;
		if (front == rear) 
		{
			front = rear = -1;
		}
		else 
		{
			front = (front + 1) % maxSize;
		}
		return temp;
	}

	void display() 
	{
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

	/*bool isPalindrome()
	{
		int i= front, j = rear;
		while (i!=j && (i+1)%maxSize!=j)
		{
			if (arr[i] != arr[j])
			{
				return false;
			}
			i = (i + 1) % maxSize;
			j = (j - 1 + maxSize) % maxSize;
			
		}
		return true;
	}*/

	void reverseQueue() 
	{
		Stack S(maxSize);
		while (!isEmpty()) 
		{
			S.push(remove());
			cout << "\n";
		}

		while (!S.isEmpty())
		{
			insert(S.pop());
			cout << "\n";
		}
	}
};

int main()
{
	Queue q(5);

	q.insert(7);
	q.insert(3);
	q.insert(5);
	q.insert(9);
	q.insert(0);
	cout << "Original ";
	q.display();

	q.reverseQueue();

	cout << "Reversed ";
	q.display();

	return 0;
	
}
