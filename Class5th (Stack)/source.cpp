#include <iostream>

using namespace std;

template<typename T>
class Stack
{
	T* container;
	int capacity;
	int highset;

public:
	Stack()
	{
		container = nullptr;
		capacity = 0;
		highset = -1;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < highset + 1; i++)
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
		else if (capacity <= highset + 1)
		{
			resize(capacity * 2);
		}

		container[++highset] = data;
	}

	void pop()
	{
		if (highset <= -1)
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			container[highset--] = NULL;
		}
	}

	const bool& empty()
	{
		return highset <= -1;
	}

	const T& top()
	{
		return container[highset];
	}

	const int& size()
	{
		return highset + 1;
	}

	~Stack()
	{
		delete[] container;
	}
};

int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	cout << stack.top() << endl;

	cout << stack.size() << endl;

	stack.pop();
	stack.pop();
	stack.pop();

	return 0;
}

