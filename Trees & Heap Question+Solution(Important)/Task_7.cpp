#include <bits\stdc++.h>
#include "Tree.h"
using namespace std;

bool validityCheck(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->val <= min || root->val >= max)
        return false;

    return validityCheck(root->left, min, root->val) && validityCheck(root->right, root->val, max);
}
bool isBST(Node *root)
{

    return validityCheck(root, INT_MIN, INT_MAX);
}
int main()
{
    Tree obj; // Create a Tree object
    int value;

    // Insert the root node
    cout << "Enter the root node value: ";
    cin >> value;
    obj.insert(value, nullptr, 'R'); // Insert the root node into the tree

    while (true)
    {
        cout << "Enter the value to insert (-1 to stop): ";
        cin >> value;

        if (value == -1)
        {
            break;
        }

        char pos;
        Node *parent = obj.getRoot();

        // Find the parent node where the new value should be inserted
        while (true)
        {
            cout << "Enter 'L' to insert left or 'R' to insert right of node with value " << parent->val << ": ";
            cin >> pos;

            if (pos == 'L' || pos == 'R')
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'L' or 'R'." << endl;
            }
        }

        obj.insert(value, parent, pos); // Insert the new value into the tree
        cout << "Inserted " << value << " at the " << (pos == 'L' ? "left" : "right") << " of node with value " << parent->val << endl;
    }

    // Check if the tree is a valid BST
    if (isBST(obj.getRoot()))
    {
        cout << "The tree is a valid Binary Search Tree." << endl;
    }
    else
    {
        cout << "The tree is not a valid Binary Search Tree." << endl;
    }

    return 0;
}