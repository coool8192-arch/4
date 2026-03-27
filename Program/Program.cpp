#include <iostream>
using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{

	};
	int capacity;
	int size;

public:
	HashTable()
	{
		size = 0;
		capacity = 0;


	}

template<typename T>
unsigned int hash_fuction(KEY key)
{
	return (unsigned int)key % capacity;
}

};

int main()
{

return 0;
}

