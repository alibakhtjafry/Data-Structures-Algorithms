#include <bits\stdc++.h>
#include "BST.h"
using namespace std;

// Kth largest
void helpingLargest(Node *root, int k, int &count, int &val)
{
    if (root == NULL)
    {
        return;
    }
    helpingLargest(root->right, k, count, val);
    count++;
    if (count == k)
    {
        val = root->val;
        return;
    }
    helpingLargest(root->left, k, count, val);
}
int findKthLargest(Node *root, int k)
{
    int result = 0;
    int count = 0;
    helpingLargest(root, k, count, result);
    return result;
}
// Kth smallest
void helpingSmallest(Node *root, int k, int &count, int &val)
{
    if (root == NULL)
    {
        return;
    }
    helpingSmallest(root->right, k, count, val);
    count++;
    if (count == k)
    {
        val = root->val;
        return;
    }
    helpingSmallest(root->left, k, count, val);
}
int findKthSmallest(Node *root, int k)
{
    int result = 0;
    int count = 0;
    helpingSmallest(root, k, count, result);
    return result;
}
int main()
{
    BST obj;
    int n, val, k;

    cout << "Enter the number of nodes in the BST: ";
    cin >> n;
    Node *root = nullptr;
    cout << "Enter the elements of the BST:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = obj.insert(root, val);
    }

    cout << "Enter the value of k for k-th largest: ";
    cin >> k;
    cout << "The " << k << "-th largest element is: " << findKthLargest(root, k) << endl;

    cout << "Enter the value of k for k-th smallest: ";
    cin >> k;
    cout << "The " << k << "-th smallest element is: " << findKthSmallest(root, k) << endl;

    return 0;
}