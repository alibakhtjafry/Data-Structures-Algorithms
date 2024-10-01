#include <iostream>
#include "Tree.h"
using namespace std;
// this will calculate sum return the appropriate sum
// if leaf then return the root->val if(val equals) return root->val along with left & right val else return 0
int calculateSum(Node *root)
{
    if (root == NULL)
        return 0;
    int leftValue = calculateSum(root->left);
    int rightValue = calculateSum(root->right);
    // if there is leaf node simply return the value of that node donot do anything
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    // return the combined value to the node above
    if (root->val == (leftValue + rightValue))
    {
        return root->val + leftValue + rightValue;
    }
    else
    {
        return 0; // using as the tester if this returns means there will be no sum tree (if any one not satisfied)
    }
}
bool isSumTree(Node *root)
{
    if (calculateSum(root) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree tree;
    int value;
    char pos;
    Node *root = nullptr;
    Node *currentNode = nullptr;

    // Insert the root node
    cout << "Enter the root node value: ";
    cin >> value;
    tree.insert(value, root, 'L'); // The first node becomes the root
    root = tree.getRoot();

    while (true)
    {
        cout << "Enter the value to insert (-1 to stop): ";
        cin >> value;

        if (value == -1)
        {
            break;
        }

        cout << "Current Node Value: " << root->val << endl;
        cout << "Insert to the Left (L) or Right (R) of the current node? ";
        cin >> pos;

        if (pos == 'L')
        {
            currentNode = root->left;
        }
        else if (pos == 'R')
        {
            currentNode = root->right;
        }
        else
        {
            cout << "Invalid position! Please enter 'L' or 'R'." << endl;
            continue;
        }

        if (currentNode == nullptr)
        {
            tree.insert(value, root, pos);
        }
        else
        {
            cout << "Current node already has a " << (pos == 'L' ? "left" : "right") << " child.\n";
            cout << "Enter the value to insert under this node: ";
            cin >> value;
            cout << "Insert to the Left (L) or Right (R) of this node? ";
            cin >> pos;
            tree.insert(value, currentNode, pos);
        }

        cout << "Inserted " << value << " at the " << (pos == 'L' ? "left" : "right") << " of node with value " << root->val << endl;
    }

    cout << "\nInorder Traversal of the Tree: ";
    tree.InorderTraversal(root);
    cout << endl;

    if (isSumTree(root))
    {
        cout << "The tree is a Sum Tree.\n";
    }
    else
    {
        cout << "The tree is not a Sum Tree.\n";
    }

    return 0;
}
