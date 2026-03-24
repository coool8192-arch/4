#include <iostream>
#define size 5

using namespace std;

template <typename T>
class Queue
{
	T container[size];
	int rear;
	int front;

public:
	Queue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < size; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (rear >= size)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			container[rear++] = data;
		}
	}

};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);
	queue.push(60);

	return 0;
}

