#include <iostream>
#include <cmath>

class BinaryTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;

public:
    BinaryTree(int val)
    {
        root = new Node(val);
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    Node *addRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = addRecursive(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = addRecursive(current->right, value);
        }

        return current;
    }

    void postOrderPrint(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        postOrderPrint(current->left);
        postOrderPrint(current->right);
        std::cout << current->data << " ";
    }

    Node *getRoot()
    {
        return root;
    }

    int getMax(Node *current)
    {
        if (current == nullptr)
        {
            return INT_MIN;
        }

        int max = current->data;
        int leftMax = getMax(current->left);
        int rightMax = getMax(current->right);

        return std::max(max, std::max(leftMax, rightMax));
    }

    int getHeight(Node *current)
    {
        if (current == nullptr)
        {
            return 0;
        }

        return std::max(getHeight(current->left), getHeight(current->right)) + 1;
    }

    int countAllNodes(Node *current)
    {
        if (current == nullptr)
        {
            return 0;
        }

        return countAllNodes(current->left) + countAllNodes(current->right) + 1;
    }

    int countLeafNodes(Node *current)
    {
        if (current == nullptr)
        {
            return 0;
        }

        if (current->left == nullptr && current->right == nullptr)
        {
            return 1;
        }

        return countLeafNodes(current->left) + countLeafNodes(current->right);
    }

    bool searchTree(Node *current, int val)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (current->data == val)
        {
            return true;
        }

        return searchTree(current->left, val) || searchTree(current->right, val);
    }

    bool isPerfect(Node *current)
    {
        int num = countAllNodes(current);
        int height = getHeight(current) - 1;

        return num == std::pow(2, height + 1) - 1;
    }

    void preOrderPrint(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        std::cout << current->data << " ";
        preOrderPrint(current->left);
        preOrderPrint(current->right);
    }

    void inOrderPrint(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        inOrderPrint(current->left);
        std::cout << current->data << " ";
        inOrderPrint(current->right);
    }
};
