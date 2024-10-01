// BCSF22M044_ALI BAKHT JAFRY
// NAMING CONVENTION FIRSTWORD SMALL ,SECOND WORD FIRST ALPHABET CAPITAL LETTER
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int v = 0)
    {
        val = v;
        prev = NULL;
        next = NULL;
    }

    void printVal()
    {
        cout << val << " ";
    }
};
class Queue
{
private:
    Node *front;
    Node *rare;

public:
    Queue()
    {
        front = NULL;
        rare = NULL;
    }

    void equeue(int item)
    {
        if (rare == NULL)
        {
            front = rare = new Node(item);
            rare->next = front;
            front->prev = rare;
        }
        else
        {
            Node *n = new Node(item);
            n->prev = rare;
            rare->next = n;
            rare = n;
            rare->next = front;
            front->prev = rare;
        }
    }
    int dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
        else
        {
            Node *temp = front;
            int val = front->val;
            if (front == rare)
            {
                front = rare = NULL;
            }
            else
            {
                front = front->next;
                rare->next = front;
                front->prev = rare;
            }
            delete temp;

            return val;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    // Only return the value without deleteing it
    int peekFront()
    {
        if (!isEmpty())
            return front->val;
        else
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
    }
    int getSize()
    {
        if (front == NULL)
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
        Node *temp = front;
        int size = 0;
        do
        {
            size++;
            temp = temp->next;

        } while (temp != front);
        return size;
    }
    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue Is Empty\n";
        }
        else
        {
            Node *temp = front;
            do
            {
                temp->printVal();
                temp = temp->next;

            } while (temp != front);
        }
    }

    ~Queue()
    {
        Node *temp = front;
        Node *after = NULL;
        while (temp != NULL)
        {
            after = temp->next;
            delete temp;
            temp = after;
        }
        front = rare = nullptr;
    }
};
int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek Front\n";
        cout << "4. Print Queue\n";
        cout << "5. Get Size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.equeue(value);
            break;
        case 2:
            cout << "Dequeued value: " << q.dequeue() << endl;
            break;
        case 3:
            cout << "Front value: " << q.peekFront() << endl;
            break;
        case 4:
            cout << "Queue: ";
            q.printQueue();
            cout << endl;
            break;
        case 5:
            cout << "Queue size: " << q.getSize() << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
