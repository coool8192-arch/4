#include <iostream>
using namespace std;

#define size 4

template <typename T>
class Queue
{
	T container[size];
	int rear;
	int front;

public:
	Queue()
	{
		rear = size - 1;
		front = size - 1;
		for (int i = 0; i < size; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (front == (rear + 1) % size) // 원형 queue는 한 칸을 비워두기 때문에 이렇게 해야한다.
		{
			cout << "Circle queue overflow" << endl;
		}
		else
		{
			rear = (rear + 1) % size;

			container[rear] = data;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "Circle queue is empty" << endl;
		}
		else
		{
			front = (front + 1) % size;

			container[front] = NULL;
		}
	}

	const bool& empty()
	{
		return front == rear;
	}

	const T& peek()
	{
		return container[(front + 1) % size];
	}
};

int main()
{
	Queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	while (!q.empty())
	{
		cout << q.peek() << endl;
		q.pop();
	}

	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	while (!q.empty())
	{
		cout << q.peek() << endl;
		q.pop();
	}

	return 0;
}

