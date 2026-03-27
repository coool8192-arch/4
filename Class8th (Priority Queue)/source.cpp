#include <iostream>
using namespace std;

template <typename T>
class Priority_Queue
{
	T* container;
	int capacity;
	int index;

public:
	Priority_Queue()
	{
		capacity = 0;
		index = 0;
		container = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		delete[] container;

		container = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (capacity <= index)
		{
			resize(capacity * 2);
		}

		container[index] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[child] > container[parent])
			{
				swap(container[child], container[parent]);
			}
			child = parent;
			parent = (child - 1) / 2;
		}

		index++;
	}

	void pop()
	{
		if (index <= 0)
		{
			cout << "Priority queue is empty" << endl;
		}
		else
		{
			container[0] = container[--index];

			container[index] = NULL;


			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				if (container[child] < container[child + 1])
				{
					child++;
				}

				if (container[child] < container[parent]) break;

				if (container[parent] < container[child])
				{
					swap(container[parent], container[child]);
				}

				parent = child;
				child = parent * 2 + 1;
			}
		}
	}

	const T& top()
	{
		return container[0];
	}

	const int& size()
	{
		return index;
	}

	const bool& empty()
	{
		return index <= 0;
	}

	~Priority_Queue()
	{
		delete[] container;
	}
};

int main()
{
	Priority_Queue<int> priority_queue;

	priority_queue.push(10);
	priority_queue.push(20);
	priority_queue.push(30);
	priority_queue.push(15);
	priority_queue.push(5);
	priority_queue.push(35);
	priority_queue.push(25);

	for (int i = priority_queue.size(); i > 0; i--)
	{
		cout << priority_queue.top() << endl;

		priority_queue.pop();
	}

	cout << priority_queue.size() << endl;
	cout << priority_queue.empty() << endl;


	return 0;
}

