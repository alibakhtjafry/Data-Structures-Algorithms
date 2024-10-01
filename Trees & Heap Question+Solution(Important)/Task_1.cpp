#include <bits\stdc++.h>
#include "BST.h"
using namespace std;
void BST ::lazyDeletion(Node *root, int x)
{
    if (root == nullptr)
        return;
    if (x == root->val)
        root->isDel = true;
    else if (x < root->val)
        lazyDeletion(root->left, x);
    else
        lazyDeletion(root->right, x);
}
int main()
{
    BST bst;
    int n, value, deleteValue;

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

    // Input value for lazy deletion
    cout << "Enter a value to mark for lazy deletion: ";
    cin >> deleteValue;

    // Perform lazy deletion
    bst.lazyDeletion(bst.root, deleteValue);

    // Print the tree after lazy deletion
    cout << "Tree after lazy deletion (excluding deleted nodes): ";
    bst.inOrder(bst.root);
    cout << endl;

    return 0;
}