#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    Node *right;
    Node *left;
    int val;

    Node(int val = -1)
    {
        this->val = val;
        right = nullptr;
        left = nullptr;
    }

    Node *getRight()
    {
        return right;
    }

    Node *getLeft()
    {
        return left;
    }

    void printVal()
    {
        cout << val << " ";
    }
};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = nullptr;
    }

    Node *getRoot()
    {
        return root;
    }

    void insert(int value, Node *p, char pos)
    {
        Node *temp = new Node(value);
        if (p == nullptr)
        {
            p = temp;
            root = temp;
        }
        else
        {
            if (pos == 'L')
            {
                if (p->getLeft() == nullptr)
                {
                    p->left = temp;
                }
                else
                {
                    cout << "Left Child already exists\n";
                }
            }
            else if (pos == 'R')
            {
                if (p->getRight() == nullptr)
                {
                    p->right = temp;
                }
                else
                {
                    cout << "Right Child already exists\n";
                }
            }
        }
    }

    // Function to find a node with a given value
    Node* findNode(Node *r, int value)
    {
        if (r == nullptr)
        {
            return nullptr; // Base case: node not found
        }
        if (r->val == value)
        {
            return r; // Node found
        }
        // Search in left and right subtrees
        Node* leftSearch = findNode(r->left, value);
        if (leftSearch != nullptr)
        {
            return leftSearch; // Node found in left subtree
        }
        return findNode(r->right, value); // Search in right subtree
    }

    // Function to print tree structure using level-order traversal
    void print(Node *r)
    {
        if (r == nullptr)
        {
            cout << "Tree is empty\n";
            return;
        }
        queue<Node *> que;
        que.push(r);
        while (!que.empty())
        {
            Node *temp = que.front();
            que.pop();
            cout << temp->val << " ";
            if (temp->left != nullptr)
            {
                que.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                que.push(temp->right);
            }
        }
        cout << endl;
    }

    // In-order traversal
    void InorderTraversal(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        InorderTraversal(r->left);
        cout << r->val << " ";
        InorderTraversal(r->right);
    }
};

#endif
