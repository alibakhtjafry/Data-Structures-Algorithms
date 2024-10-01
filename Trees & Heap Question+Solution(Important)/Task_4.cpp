#include <bits\stdc++.h>
#include "BST.h"
using namespace std;

void leftNodes(Node *root)
{
    while (root->left != NULL)
    {
        cout << root->val << " ";
        root = root->left;
    }
}
void leafNodes(Node *root)
{
    if (root == NULL)
        return;
    leafNodes(root->left);
    leafNodes(root->right);
    if (root->left == NULL && root->right == NULL)
        cout << root->val << " ";
}
void rightNodes(Node *root)
{
    while (root->right != NULL)
    {
        cout << root->val << " ";
        root = root->right;
    }
}
void printAnti(Node *root)
{
    leftNodes(root);
    leafNodes(root);
    rightNodes(root->right);
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

    cout << "Nodes in anti-clockwise order: ";
    printAnti(bst.root);
    cout << endl;

    return 0;
}