#include <iostream>

using namespace std;

template<typename T>
class Vector
{
	T* pointer;
	int count;
	int capacity;

public:
	Vector()
	{
		pointer = nullptr;
		count = 0;
		capacity = 0;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < count; i++)
		{
			temporary[i] = pointer[i];
		}

		delete[] pointer;

		pointer = temporary;
	}

	void push_back(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (capacity <= count)
		{
			resize(2 * capacity);
		}

		pointer[count++] = data;
	}

	const T& operator [] (const int& i)
	{
		return pointer[i];
	}

	const int& size()
	{
		return count;
	}

	void pop_back()
	{
		if (count <= 0)
		{
			cout << "Vector is empty" << endl;
			return;
		}

		pointer[--count] = NULL;
	}

	~Vector()
	{
		delete[] pointer;
	}
};

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	vector.pop_back();

	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}

	return 0;
}

