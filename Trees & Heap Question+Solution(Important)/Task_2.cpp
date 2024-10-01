/*Given two Binary Search Trees consisting of unique positive elements, we have to check whether the two
BSTs contain same set or elements or not.
Note: The structure of the two given BSTs can be different. */
#include <bits\stdc++.h>
#include "BST.h"
using namespace std;
// InOrder of BSt will be sorted so using in order
void inOrder(Node *root, vector<int> &tree)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, tree);
    tree.push_back(root->val);
    inOrder(root->right, tree);
}
// if any one element become non identical then return false
bool isIdentical(Node *root1, Node *root2)
{
    vector<int> t1;
    vector<int> t2;
    inOrder(root1, t1);
    inOrder(root2, t2);

    for (size_t i = 0; (i < t1.size()) && (i < t2.size()); i++)
    {
        if (t1[i] != t2[i])
        {
            return false;
        }
    }

    return true;
}
int main()
{
    BST obj;
    int n1, n2, val;

    cout << "Enter the number of nodes in the first BST: ";
    cin >> n1;
    Node *root1 = nullptr;
    cout << "Enter the elements of the first BST:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        root1 = obj.insert(root1, val); // Assuming insert is defined in BST.h
    }

    cout << "Enter the number of nodes in the second BST: ";
    cin >> n2;
    Node *root2 = nullptr;
    cout << "Enter the elements of the second BST:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        root2 = obj.insert(root2, val); // Assuming insert is defined in BST.h
    }

    if (isIdentical(root1, root2))
    {
        cout << "The two BSTs contain the same set of elements.\n";
    }
    else
    {
        cout << "The two BSTs do not contain the same set of elements.\n";
    }

    return 0;
}
