#include <bits\stdc++.h>
#include "Tree.h"
using namespace std;
bool isCompleteTree(Node *root)
{
    queue<Node *> que;
    Node *temp = NULL;
    que.push(root);
    bool flag = false;
    while (!que.empty())
    {
        temp = que.front();
        que.pop();

        if (temp->left != NULL)
        {
            if (flag == true)
            {
                return false;
            }

            que.push(temp->left);
        }
        else
        {
            flag = true;
        }
        if (temp->right != NULL)
        {
            if (flag == true)
            {
                return false;
            }

            que.push(temp->right);
        }
        else
        {
            flag = true;
        }
    }
    return true;
}
int main()
{
    Tree t;
    int value, parentValue;
    char pos;
    char choice;

    cout << "Enter the root node value: ";
    cin >> value;
    t.insert(value, nullptr, 'L'); // Insert the root node

    do
    {
        cout << "Enter the parent node value: ";
        cin >> parentValue;

        Node *parentNode = t.findNode(t.getRoot(), parentValue); // Find the parent node

        if (parentNode == nullptr)
        {
            cout << "Parent node not found!" << endl;
            continue;
        }

        cout << "Enter the value to insert: ";
        cin >> value;

        cout << "Enter position (L for left, R for right): ";
        cin >> pos;

        t.insert(value, parentNode, pos);

        cout << "Do you want to insert another node? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Print the tree structure
    cout << "Tree structure (level-order):" << endl;
    t.print(t.getRoot());

    // Check if the tree is a complete binary tree
    if (isCompleteTree(t.getRoot()))
    {
        cout << "The tree is a Complete Binary Tree." << endl;
    }
    else
    {
        cout << "The tree is not a Complete Binary Tree." << endl;
    }

    return 0; // Exit the program
}
