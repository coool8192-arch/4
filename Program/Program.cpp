#include <iostream>

using namespace std;

template<typename T>
class List
{
	struct Node
	{
		T data;
		Node* previous;
		Node* next;
	};
	int size;
	Node* head;
	Node* tail;

public:
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = tail = newNode;
			newNode->next = nullptr;
			
		}
		else
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "List No Data" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail)
			{
				head = tail = nullptr;
			}
			else
			{
			head = deleteNode->next;
			deleteNode->next->previous = nullptr;
			delete deleteNode;
			}
		}
		size--;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;

		if (tail == nullptr)
		{
			head = tail = newNode;
			newNode->previous = nullptr;
		}
		else
		{
			newNode->previous = tail;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	const bool& empty()
	{
		return (head == nullptr);
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}

	}
};
int main()
{
	List<int> list;

	list.push_front(7);
	list.push_front(13);
	list.push_back(16);

	list.pop_front();
	list.pop_front();
	list.pop_front();

	cout << list.empty() << endl;

	return 0;
}

