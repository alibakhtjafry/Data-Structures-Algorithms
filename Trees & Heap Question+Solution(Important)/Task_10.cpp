#include <bits\stdc++.h>
#include "BST.h"
using namespace std;
Node *successor(Node *node)
{

    Node *temp = node->right;
    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *DeleteFromRange(Node *root, int min, int max)
{
    if (root == NULL)
        return root;

    root->left = DeleteFromRange(root->left, min, max);
    root->right = DeleteFromRange(root->right, min, max);

    if (root->val < min || root->val > max)
    {
        if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        Node *temp = successor(root);
        root->val = temp->val;
        root->right = DeleteFromRange(root->right, temp->val, temp->val);
    }

    return root;
}
int main()
{
    BST bst;
    int n, value;

    // Input number of nodes to insert
    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    // Insert nodes
    cout << "Enter " << n << " values to insert into the BST:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        bst.insert(value);
    }

    cout << "In-order traversal of the BST before deletion: ";
    bst.inOrder(bst.root);
    cout << endl;

    int minRange, maxRange;
    cout << "Enter the minimum value of the range: ";
    cin >> minRange;
    cout << "Enter the maximum value of the range: ";
    cin >> maxRange;

    DeleteFromRange(bst.root, minRange, maxRange);

    cout << "In-order traversal of the BST after deletion: ";
    bst.inOrder(bst.root);
    cout << endl;

    return 0;
}