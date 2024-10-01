// BCSF22M044_ALI BAKHT JAFRY
// NAMING CONVENTION FIRSTWORD SMALL ,SECOND WORD FIRST ALPHABET CAPITAL LETTER
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    int priority;
    Node *next;

    Node(int v, int p)
    {
        val = v;
        priority = p;
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
    void enqueue(int value, int p)
    {
        if (rare == NULL)
        {
            front = rare = new Node(value, p);
        }
        else
        {
            Node *n = new Node(value, p);
            rare->next = n;
            rare = n;
        }
    }
    // Currently this is ascending order insertion changing the loop condition to (>=) will change it in descending order
    void sortedInsertion(int item, int pri)
    {
        if (rare == NULL)
        {
            rare = new Node(item, pri);
            front = rare;
        }
        else
        {
            Node *temp = front;
            Node *p = NULL;
            Node *n = new Node(item, pri);

            while (temp != NULL && temp->priority <= n->priority)
            {
                p = temp;
                temp = temp->next;
            }

            if (temp == front)
            {
                n->next = front;
                front = n;
            }
            // Insert at the end
            else if (temp == rare)
            {
                rare->next = n;
                rare = n;
            }
            // Insert in the middle
            else
            {
                n->next = temp;
                p->next = n;
            }
        }
    }
    // Simple Dequeue
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
                front = rare = nullptr;
            }

            return x;
        }
    }
    // when there is random insertion not sorted takes priority and delete element of that priority
    int priorityDequeue(int p)
    {
        if (front->priority == p)
        {
            Node *temp = front->next;
            int val = front->val;
            delete front;
            if (temp == NULL)
            {
                rare = front = nullptr;
                return val;
            }
            else
            {
                front = temp;
            }

            return val;
        }
        else if (rare->priority == p)
        {
            if (front == rare)
            {
                int val = front->val;
                delete front;
                front = rare = nullptr;
                return val;
            }
            else
            {
                Node *p = NULL;
                Node *temp = front;
                while (temp->next != NULL)
                {
                    p = temp;
                    temp = temp->next;
                }
                int val = rare->val;
                delete temp;
                p->next = NULL;
                rare = p;

                return val;
            }
        }
        else
        {
            Node *temp = front;
            Node *pr = NULL;
            while (temp->priority != p)
            {
                pr = temp;
                temp = temp->next;
            }
            pr->next = temp->next;
            int val = temp->val;
            delete temp;

            return val;
        }
    }

    int peekFront()
    {
        if (front != NULL)
        {
            return front->val;
        }
        else
        {
            cout << "\nQueue Is Empty\n";
            return 0;
        }
    }

    int getSize()
    {
        if (front == NULL)
        {
            cout << "Queue IS Empty\n";
            return 0;
        }
        Node *temp = front;
        int size = 0;
        do
        {
            size++;
            temp = temp->next;

        } while (temp != NULL);
        return size;
    }

    void printQueue()
    {
        if (front == NULL)
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
        while (front != NULL)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rare = NULL;
    }
};
int main()
{
    Queue obj;
    int choice, value, priority;

    do
    {
        cout << "1. Insert element\n2. Remove element by priority\n3. Remove front element\n4. Display queue\n5. Display front element\n6. Display size of queue\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value and priority: ";
            cin >> value >> priority;
            obj.sortedInsertion(value, priority);
            break;
        case 2:
            cout << "Enter priority to remove: ";
            cin >> priority;
            cout << "Removed element: " << obj.priorityDequeue(priority) << endl;
            break;
        case 3:
            cout << "Removed element: " << obj.dequeue() << endl;
            break;
        case 4:
            obj.printQueue();
            cout << endl;
            break;
        case 5:
            cout << "Front element: " << obj.peekFront() << endl;
            break;
        case 6:
            cout << "Size of queue: " << obj.getSize() << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
