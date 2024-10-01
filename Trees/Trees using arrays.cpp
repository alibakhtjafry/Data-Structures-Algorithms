#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Tree
{
public:
    int *tree;
    int size;
    int count;

    Tree(int levels)
    {
        this->size = pow(2, levels) - 1; // as size does not effect by 1-index so....
        // levels are 2^power
        this->count = 1;
        tree = new int[size + 1]; // as tree starts from zero index
        for (int i = 1; i <= size; i++)
        {
            tree[i] = -1; // making as all nulls
        }
    }

    ~Tree()
    {
        delete[] tree;
        tree = nullptr;
    }

    bool isFull()
    {
        if (count == size + 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (count == 1)
            return true;
        return false;
    }

    void insert(int element)
    {
        if (isFull())
        {
            cout << "Tree is Full\n";
            return;
        }
        tree[count++] = element; // in array there is level order insertion
    }
    // this function will delete the sub tree of that particular element
    // going left then right and making all to null(-1)
    void deleteSubTree(int index)
    {
        if (index >= count || tree[index] == -1)
            return;

        tree[index] = -1;
        deleteSubTree(2 * index);
        deleteSubTree(2 * index + 1);
    }
    void deleteElement(int index)
    {
        if (index >= size || tree[index] == -1)
        {
            cout << "Invalid index or element is already null!" << endl;
            return;
        }
        cout << "Deleted Successfully\n";
        deleteSubTree(index);
    }

    // 2 ways passing directly the vector or arrays as reference or making new fucntion that will return vector as see below
    void inOrderTraversal(int index, vector<int> &result)
    {
        if (index >= size || tree[index] == -1)
        {
            return;
        }
        inOrderTraversal(2 * index, result);     // L
        result.push_back(tree[index]);           // N
        inOrderTraversal(2 * index + 1, result); // R
    }

    vector<int> inOrderTraversal()
    {
        vector<int> result;
        inOrderTraversal(1, result);
        return result;
    }

    void preOrderTraversal(int index, vector<int> &result)
    {
        if (index >= count || tree[index] == -1)
        {
            return;
        }
        result.push_back(tree[index]);            // N
        preOrderTraversal(2 * index, result);     // L
        preOrderTraversal(2 * index + 1, result); // R
    }

    void postOrderTraversal(int index, vector<int> &result)
    {
        if (index >= count || tree[index] == -1)
        {
            return;
        }
        postOrderTraversal(2 * index, result);     // L
        postOrderTraversal(2 * index + 1, result); // R
        result.push_back(tree[index]);             // N
    }

    int *levelOrderTraversal()
    {
        if (count == 1)
        {
            cout << "Tree is Empty\n";
            return nullptr;
        }
        queue<int> stk;
        int *result = new int[count - 1]; // result stating form 0 index
        stk.push(1);
        int i = 0;
        result[i++] = tree[stk.front()];
        // pusing element in the queue then poping it and check the next level
        while (!stk.empty())
        {
            int index = stk.front();
            stk.pop();
            if (2 * index < count && tree[2 * index] != -1) // LEFT CHECK
            {
                result[i++] = tree[2 * index];
                stk.push(2 * index);
            }
            if (2 * index + 1 < count && tree[2 * index + 1] != -1) // RIGHT CHECK
            {
                result[i++] = tree[2 * index + 1];
                stk.push(2 * index + 1);
            }
        }
        return result;
    }
    int getSize()
    {
        return count;
    }
    void printTree()
    {
        int k = 0;
        for (int i = 1; i <= size; i++)
        {
            if (i == pow(2, k)) // as it will print levels (level=2^pow)
            {
                k++;
                cout << endl;
            }
            cout << " " << tree[i];
        }
        cout << endl;
    }
};

int main()
{
    int levels;
    cout << "Enter the number of levels: ";
    cin >> levels;

    Tree obj(levels);

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Print tree\n";
        cout << "4. In-Order Traversal\n";
        cout << "5. Pre-Order Traversal\n";
        cout << "6. Level-Order Traversal\n";
        cout << "7. Post-Order Traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int element;
            cout << "Enter element to insert: ";
            cin >> element;
            obj.insert(element);
            break;
        }
        case 2:
        {
            int element;
            cout << "Enter element to delete: ";
            cin >> element;
            obj.deleteElement(element);
            break;
        }
        case 3:
            obj.printTree();
            break;
        case 4:
        {
            vector<int> result = obj.inOrderTraversal();
            cout << "In-Order Traversal: ";
            for (int val : result)
            {
                cout << val << " ";
            }
            cout << endl;
            break;
        }
        case 5:
        {
            vector<int> result;
            obj.preOrderTraversal(1, result);
            cout << "Pre-Order Traversal: ";
            for (int val : result)
            {
                cout << val << " ";
            }
            cout << endl;
            break;
        }
        case 6:
        {
            int *result = obj.levelOrderTraversal();
            if (result != nullptr)
            {
                cout << "Level-Order Traversal: ";
                for (int i = 0; i < obj.count - 1; i++)
                {
                    cout << result[i] << " ";
                }
                cout << endl;
            }
            delete[] result;
            break;
        }
        case 7:
        {
            vector<int> result;
            obj.postOrderTraversal(1, result);
            cout << "Post-Order Traversal: ";
            for (int val : result)
            {
                cout << val << " ";
            }
            cout << endl;
            break;
        }
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}
