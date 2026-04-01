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
		int count;
		Node* head;
	};

	int capacity;
	int size;
	Bucket* bucket;

public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];

		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}

	template<typename KEY>
	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template<>
	unsigned int hash_function(const char* pointer)
	{
		unsigned int sum = 0;

		for (int i = 0; *pointer != '\0'; i++)
		{
			sum += pointer[i];

			pointer = pointer + 1;
		}

		return sum % capacity;
	}

	void insert(KEY key, VALUE value)
	{
		int hashIndex = hash_function(key);

		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		if (bucket[hashIndex].count == 0)
		{
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}

		bucket[hashIndex].count++;

		size++;
	}

	const int& bucket_count()
	{
		return capacity;
	}

	const float& load_factor()
	{
		return (float)size / capacity;
	}

	void erase(KEY key)
	{
		int hashIndex = hash_function(key);

		Node* currentNode = bucket[hashIndex].head;

		Node* previousNode = nullptr;

		if (currentNode == nullptr)
		{
			cout << "key not found" << endl;
		}
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					if (currentNode == bucket[hashIndex].head)
					{
						bucket[hashIndex].head = currentNode->next;
					}
					else
					{
						previousNode->next = currentNode->next;
					}

					size--;

					bucket[hashIndex].count--;

					delete currentNode;

					return;
				}
				else
				{
					previousNode = currentNode;

					currentNode = currentNode->next;
				}
			}
			cout << "key not found" << endl;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < capacity; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = bucket[i].head;
			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}

		delete[] bucket;
	}
};

int main()
{
	HashTable<const char*, int> hashtable;

	hashtable.insert("Magnesium", 12);
	hashtable.insert("Silicon", 14);
	hashtable.insert("Calcium", 20);

	hashtable.erase("Silicon");
	hashtable.erase("Silicon");

	hashtable.erase("Sodium");


	cout << hashtable.bucket_count() << endl;

	cout << hashtable.load_factor() << endl;
	return 0;
}

