#include <iostream>

using namespace std;

template <typename T>
class Set
{
    struct Node
    {
        T data;

        Node* left = nullptr;
        Node* right = nullptr;

        Node(T data)
        {
            this->data = data;
        }
    };

    Node* root;
public:
    Set()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            Node* currentNode = root;

            while (true)
            {
                if (data < currentNode->data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = new Node(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else if (data > currentNode->data)
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = new Node(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    void erase(T data)
    {
        Node* currentNode = root;
        Node* parentNode = nullptr;

        while (currentNode->data != data && currentNode != nullptr)
        {
            parentNode = currentNode;

            if (currentNode->data < data)
            {
                currentNode = currentNode->right;
            }
            else
            {
                currentNode = currentNode->left;
            }
        }

        if (currentNode == nullptr)
        {
            cout << "the data does not exist" << endl;
            return;
        }
        else if (currentNode->left == nullptr && currentNode->right == nullptr)
        {
            if (parentNode != nullptr)
            {
                if (currentNode == parentNode->right)
                {
                    parentNode->right = nullptr;
                }
                else
                {
                    parentNode->left = nullptr;
                }  
            }
            else
            {
                root = nullptr;
            }

            delete currentNode;
        }
        else if(currentNode->left != nullptr || currentNode->right != nullptr)
        {
            if (currentNode == root)
            {
                if (currentNode->right != nullptr)
                {
                    root = currentNode->right;
                }
                else
                {
                    root = currentNode->left;
                }
            }
            else
            {
                Node* childNode = nullptr;

                if (currentNode->right != nullptr)
                {
                    childNode = currentNode->right;
                }
                else
                {
                    childNode = currentNode->left;
                }

                if (currentNode == parentNode->right)
                {
                    parentNode->right = childNode;
                }
                else
                {
                    parentNode->left = childNode;
                }
            }
            delete currentNode;
        }
    }
};

int main()
{
    Set<int> set;

    set.insert(10);
    set.insert(15);
    set.insert(6);
    set.insert(7);
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(12);

    set.erase(2);
    set.erase(1);
    set.erase(4);

    return 0;
}

