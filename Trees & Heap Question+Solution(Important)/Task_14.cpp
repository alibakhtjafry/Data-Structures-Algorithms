#include <iostream>
#include "Tree.h"
using namespace std;
int evaluateHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = evaluateHeight(root->left);
    int right = evaluateHeight(root->right);
    if (left > right)
    {
        return (left + 1);
    }
    else
    {
        return (right + 1);
    }
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

    cout << "Height of the Tree will be: " << evaluateHeight(t.getRoot());
    return 0;
}