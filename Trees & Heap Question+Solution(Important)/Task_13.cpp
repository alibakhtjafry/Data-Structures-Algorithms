#include <iostream>
#include "Tree.h"
#include <queue>
using namespace std;
// Iterative solution to find the height of the
int evaluateHeight(Node *root)
{
    queue<Node *> que;
    Node *temp = NULL;
    que.push(root);
    int count = 0;
    while (!que.empty())
    {
        int size = que.size(); // level size
        count++;
        for (int i = 1; i <= size; i++)
        { // processing that level
            temp = que.front();
            que.pop();
            if (temp->left != NULL)
                que.push(temp->left);
            if (temp->right != NULL)
                que.push(temp->right);
        }
    }

    return count;
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

    cout << "Height of the Tree will be : " << evaluateHeight(t.getRoot());

    return 0;
}