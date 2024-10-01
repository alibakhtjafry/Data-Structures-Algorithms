#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data = 0, Node *p = NULL, Node *n = NULL)
    {
        this->data = data;
        prev = p;
        next = n;
    }
    void printData()
    {
        cout << data << " ";
    }
};
class STACK
{
    Node *top;
    int count = 0;

public:
    STACK()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }

    void PUSH(int x)
    {
        if (top == NULL)
        {
            Node *n = new Node(x);
            top = n;
        }
        else
        {
            Node *n = new Node(x);
            n->prev = NULL;
            n->next = top;
            top->prev = n;
            top = n;
        }
        count++;
    }
    int POP()
    {
        int value = 0;
        if (!isEmpty())
        {
            value = top->data;
            Node *next = top;
            top = top->next;
            delete next;
        }
        else
        {
            cout << "Stack is Empty\n";
        }
        count--;
        return value;
    }
    int getTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            return top->data;
        }
    }

    int getSize()
    {
        return count;
    }
    void printList()
    {
        Node *temp = top->next;
        top->printData();
        cout << "   <- TOP\n";

        while (temp != NULL)
        {
            temp->printData();
            cout << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    STACK stack;
    int choice, value;

    do
    {
        cout << "\nStack Operations Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Stack\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Get Top Element\n";
        cout << "6. Get Stack Size\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.PUSH(value);
            break;
        case 2:
            value = stack.POP();
            if (value != 0)
            {
                cout << "Popped element: " << value << endl;
            }
            break;
        case 3:
            cout << "Stack contents:\n";
            stack.printList();
            break;
        case 4:
            if (stack.isEmpty())
            {
                cout << "Stack is EMPTY\n";
            }
            else
            {
                cout << "Stack is NOT EMPTY\n";
            }
            break;
        case 5:
            value = stack.getTop();
            if (value != 0)
            {
                cout << "Top element: " << value << endl;
            }
            break;
        case 6:
            cout << "Stack size: " << stack.getSize() << endl;
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}