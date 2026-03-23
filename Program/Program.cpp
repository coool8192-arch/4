#include <iostream>

using namespace std;

template<typename T>
class Stack
{
	T* data;
	int capacity;
	int highset;

public:
	Stack()
	{
		data = nullptr;
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

		for (int i = 0; i < highset+1; i++)
		{
			temporary[i] = data[i];
		}

		delete[] data;

		data = temporary;

	}
};

int main()
{
	Stack<int> stack;

	return 0;
}

