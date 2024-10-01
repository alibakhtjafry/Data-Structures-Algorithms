#include <iostream>
#include <queue>
#include <climits>

using namespace std;
class Node
{
public:
    Node *right;
    Node *left;
    int val;
    bool isDel;

public:
    Node(int val = -1)
    {
        this->val = val;
        right = NULL;
        left = NULL;
        isDel=false;
    }
    Node *getRight()
    {
        return right;
    }
    Node *getLeft()
    {
        return left;
    }
    void printVal()
    {
        cout << val << " ";
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    // Recursive insertion
    Node *insert(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }
        if (value < node->val)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }
    }
    // iterative insert Function
    void insert(int value)
    {
        if (root == NULL)
        {
            root = new Node(value);
        }
        else
        {
            Node *prev = NULL;
            Node *temp = root;
            while (temp != NULL)
            {
                prev = temp;
                if (value < temp->val)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            if (value < prev->val)
            {
                prev->left = new Node(value);
            }
            else
            {
                prev->right = new Node(value);
            }
        }
    }
    Node *successor(Node *node)
    {

        Node *temp = node->right;
        while (temp != NULL && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *deleteNode(Node *node, int value)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (value < node->val)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->val)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            // Node with one child or no child
            if (node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // if there is 2 child node (case#3)
            Node *temp = successor(node);
            node->val = temp->val;
            // yahan right ma is liye return krva rahe hna ku kay successor ma ham right most subtree ka left dekhte han to node kay right subtree ma say hi vo successor delete ho ga or is kay right pa hi return ho ga ku kay ham na successor ma ham na right pa hi point kiya tha agr predecessor karen gay to left most subbtree hota ha to node->left ma hi return ho ga
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }
    // Iterative delete
    Node *deleteNode(int value)
    {
        if (root == NULL)
        {
            return nullptr;
        }
        else
        {
            Node *prev = NULL;
            Node *temp = root;
            while (temp != NULL)
            {
                if (value < temp->val)
                {
                    prev = temp;
                    temp = temp->left;
                }
                else if (value > temp->val)
                {
                    prev = temp;
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
            if (temp->left == NULL && temp->right == NULL)
            {
                delete temp;
                if (value < prev->val)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
            }
            else if (temp->left != NULL && temp->right == NULL)
            {
                Node *temp1 = temp->left;
                delete temp;
                if (value < prev->val)
                {
                    prev->left = temp1;
                }
                else
                {
                    prev->right = temp1;
                }
            }
            else if (temp->right != NULL && temp->left == NULL)
            {
                Node *temp1 = temp->right;
                delete temp;
                if (value < prev->val)
                {
                    prev->left = temp1;
                }
                else
                {
                    prev->right = temp1;
                }
            }
            else
            {
                Node *prev1 = NULL;
                Node *temp1 = temp->right;
                while (temp1 != NULL && temp1->left != NULL)
                {
                    prev1 = temp1;
                    temp1 = temp1->left;
                }
                temp->val = temp1->val;
                if (temp1->right != NULL)
                {
                    Node *temp2 = temp1->right;
                    delete temp1;
                    if (temp1->val < prev1->val)
                    {
                        prev1->left = temp2;
                    }
                    else
                    {
                        prev1->right = temp2;
                    }
                }
                else
                {
                    // If the successor has no right child
                    if (prev1 != NULL)
                    {
                        delete temp1;
                        prev1->left = NULL; // Update parent's left pointer to NULL
                    }
                    else
                    {
                        // If prev1 is NULL, temp1 was the right child of temp
                        temp->right = NULL; // Update the right child of the node to be deleted
                        delete temp1;       // Delete the successor
                    }
                }
            }
        }
        return root;
    }

    void levelOrderTraversal(Node *rot)
    {
        if (rot == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }
        else
        {
            queue<Node *> que;
            que.push(root);
            while (!que.empty())
            {
                Node *temp = que.front();
                que.pop();
                cout << temp->val << " ";
                if (temp->left != NULL)
                {
                    que.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    que.push(temp->right);
                }
            }
        }
    }
    void inOrder(Node* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        cout<<root->val<<" ";
        inOrder(root->right);
    }
    friend  Node *cleanUp(Node *n, int min, int max);
    void lazyDeletion(Node *root, int x);
    
    
};