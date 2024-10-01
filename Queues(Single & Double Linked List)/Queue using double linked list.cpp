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
    int count = 0; // handled in every function that may insert or delete the element form queue

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
        }
        else
        {
            Node *n = new Node(item);
            n->prev = rare;
            rare->next = n;
            rare = n;
        }
        count++;
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
            Node *temp = front->next;
            int x = front->val;
            delete front;
            if (temp == NULL) // condition in case if there is only one element in queue
            {
                rare = NULL;
            }
            else
            {
                front = temp;
                front->prev = NULL;
            }
            count--;
            return x;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    int removeRare()
    {
        if (rare == NULL)
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
        else if (front == rare) // handle if the queue have only one element front=rare
        {
            int x = rare->val;
            delete rare;
            rare = front = NULL;
            count--;
            return x;
        }
        else
        {
            int x = rare->val;
            Node *temp = rare->prev; // benefit of double linked list
            delete rare;
            rare = temp;
            rare->next = NULL;
            count--;
            return x;
        }
    }
    void addFront(int item)
    {
        if (front == NULL)
        {
            front = rare = new Node(item);
        }
        else
        {
            Node *n = new Node(item);
            n->next = front;
            front->prev = n;
            front = n;
        }
        count++;
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
    int peekRare()
    {
        if (rare != NULL)
            return rare->val;
        else
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
    }
    int getSize()
    {
        return count;
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
            while (temp != NULL)
            {
                temp->printVal();
                temp = temp->next;
            }
        }
    }

    ~Queue()
    {
        delete front;
        delete rare;
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
        cout << "3. Add Front\n";
        cout << "4. Remove Rare\n";
        cout << "5. Peek Front\n";
        cout << "6. Peek Rare\n";
        cout << "7. Print Queue\n";
        cout << "8. Get Size\n";
        cout << "9. Exit\n";
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
            cout << "Enter value to add to front: ";
            cin >> value;
            q.addFront(value);
            break;
        case 4:
            cout << "Removed rare value: " << q.removeRare() << endl;
            break;
        case 5:
            cout << "Front value: " << q.peekFront() << endl;
            break;
        case 6:
            cout << "Rare value: " << q.peekRare() << endl;
            break;
        case 7:
            cout << "Queue: ";
            q.printQueue();
            cout << endl;
            break;
        case 8:
            cout << "Queue size: " << q.getSize() << endl;
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
