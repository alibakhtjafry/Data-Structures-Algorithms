// BCSF22M044_ALI BAKHT JAFRY
// NAMING CONVENTION FIRSTWORD SMALL ,SECOND WORD FIRST ALPHABET CAPITAL LETTER
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int v = 0)
    {
        val = v;
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
    int count = 0;

public:
    Queue()
    {
        front = NULL;
        rare = NULL;
    }
    void enqueue(int value)
    {
        if (rare == NULL)
        {
            front = rare = new Node(value);
        }
        else
        {
            Node *n = new Node(value);
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
            if (temp != NULL) // checking for it there is only one element in the queue
            {
                front = temp;
            }
            else
            {
                front = rare = NULL;
            }
            return x;
        }
        count--;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void addFront(int item)
    {
        if (isEmpty())
        {
            front = rare = new Node(item);
        }
        else
        {
            Node *n = new Node(item);
            n->next = front;
            front = n;
        }
        count++;
    }
    // Removing & return an item form the rare end (insertion end)
    int removeRare()
    {
        if (isEmpty())
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
        else if (front == rare) // check for the one element in the list or queue
        {
            int x = rare->val;
            delete rare;
            front = rare = NULL;
            count--;
            return x;
        }
        else
        {
            Node *prev = front;
            // Loop to get the address of the element hust before the rare one
            // Single linked list (counld no go back :(
            while (prev->next != rare)
            {
                prev = prev->next;
            }
            int x = rare->val;
            delete rare;
            rare = prev;
            rare->next = NULL;
            count--;
            return x;
        }
    }

    int peekFront()
    {
        if (!isEmpty())
        {
            return front->val;
        }
        else
        {
            cout << "Queue Is Empty\n";
            return 0;
        }
    }

    int peekRare()
    {
        if (rare != NULL)
        {
            return (rare->val);
        }
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
        Node *temp;
        temp = front;
        while (temp != NULL)
        {
            temp->printVal();
            temp = temp->next;
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
        cout << "9. Is Empty?\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
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
            break;
        case 8:
            cout << "Queue size: " << q.getSize() << endl;
            break;
        case 9:
            if (q.isEmpty())
            {
                cout << "Queue Is Empty\n";
            }
            else
            {
                cout << "Queue Is Not Empty\n";
            }
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
