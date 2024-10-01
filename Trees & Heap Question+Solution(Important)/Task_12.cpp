#include<bits\stdc++.h>
#include "Tree.h"
using namespace std;

void reverseLevelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
    else
    {
        queue<Node *> que;
        stack<int> stk;
        que.push(root);
        while (!que.empty())
        {
            Node *temp = que.front();
            que.pop();
            stk.push(temp->val);
            if (temp->right != NULL)
            {
                que.push(temp->right);
            }

            if (temp->left != NULL)
            {
                que.push(temp->left);
            }
        }
        while (!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
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

    reverseLevelOrder(t.getRoot());

    return 0;
}