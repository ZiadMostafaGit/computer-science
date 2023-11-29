#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
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
        cout << current->data << " ";
    }

    Node *getroot()
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

    // int getHeight(Node *current)
    // {
    //     if (current == nullptr)
    //     {
    //         return 0;
    //     }
    //
    //     return std::max(getHeight(current->left), getHeight(current->right)) + 1;
    // }

    int getHeight(Node *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int leftHeight = getHeight(root->left);
            int rightHeight = getHeight(root->right);

            return max(leftHeight, rightHeight) + 1;
        }
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

    int Get_Diametar(Node *current)
    {

        int diametar = 0;
        Get_Hight_for_diametar(current, diametar);
        return diametar;
    }

    int Get_Hight_for_diametar(Node *current, int &diametar)
    {

        if (!current)
        {
            return 0;
        }

        int h1 = Get_Hight_for_diametar(current->left, diametar);
        int h2 = Get_Hight_for_diametar(current->right, diametar);

        diametar = max(diametar, (h1 + h2));
        return 1 + max(h1, h2);
    }

    void Level_by_Level_iterative()
    {
        int level = 0;
        queue<Node *> qu;
        qu.push(getroot());

        while (!qu.empty())
        {

            cout << "Level " << level << ": ";
            int sz = qu.size();
            while (sz--)
            {
                Node *current = qu.front();
                qu.pop();

                cout << current->data << " ";
                if (current->left)
                    qu.push(current->left);
                if (current->right)
                    qu.push(current->right);
            }
            level++;
            cout << endl;
        }
    }

    void print_level(Node *cur, int level)
    {

        if (level == 0)
        {
            cout << cur->data << " ";
        }
        else if (level > 0)
        {
            if (cur->left)
            {
                print_level(cur->left, level - 1);
            }
            if (cur->right)
            {
                print_level(cur->right, level - 1);
            }
        }
    }

    void Level_by_Level_recursive(Node *current)
    {
        int th = getHeight(current);
        for (int i = 0; i < th; i++)
        {
            print_level(current, i);
        }
        cout << endl;
    }
};
