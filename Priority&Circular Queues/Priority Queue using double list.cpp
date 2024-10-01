// BCSF22M044_ALI BAKHT JAFRY
// NAMING CONVENTION FIRSTWORD SMALL ,SECOND WORD FIRST ALPHABET CAPITAL LETTER
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    int priority;
    Node *prev;
    Node *next;

    Node(int v, int pri)
    {
        val = v;
        priority = pri;
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
    void equeue(int item, int pri)
    {
        if (rare == NULL)
        {
            front = rare = new Node(item, pri);
        }
        else
        {
            Node *n = new Node(item, pri);
            n->prev = rare;
            rare->next = n;
            rare = n;
        }
    }
    // Currently this is ascending order insertion changing the loop condition to (>=) will change it in descending order
    void sortedEqueue(int item, int p)
    {
        if (rare == NULL)
        {
            rare = new Node(item, p);
            front = rare;
        }
        else
        {
            Node *temp = front;
            Node *pr = NULL;
            Node *n = new Node(item, p);

            // loop to locate the position according to priority
            while (temp != NULL && temp->priority <= n->priority)
            {
                pr = temp;
                temp = temp->next;
            }

            // Insert at the front
            if (temp == front)
            {
                n->next = front;
                front->prev = n;
                front = n;
            }
            // Insert at the end
            else if (temp == NULL)
            {
                rare->next = n;
                n->prev = rare;
                rare = n;
            }
            // Insert in the middle
            else
            {
                n->prev = pr;
                n->next = temp;
                pr->next = n;
                temp->prev = n;
            }
        }
    }
    int PriorityDequeue(int p)
    {
        if (front->priority == p)
        {
            return dequeue();
        }
        else if (rare->priority == p)
        {
            if (rare == front)
            {
                int val = front->val;
                delete front;
                front = rare = nullptr;

                return val;
            }
            else
            {
                Node *temp = rare->prev;
                int val = rare->val;
                delete rare;

                if (temp == NULL)
                {
                    rare = front = nullptr;
                }
                else
                {
                    rare = temp;
                    rare->next = nullptr;
                }

                return val;
            }
        }
        else
        {
            Node *temp = front;
            while (temp->priority != p)
            {
                temp = temp->next;
            }

            int val = temp->val;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;

            return val;
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
            Node *temp = front->next;
            int x = front->val;
            delete front;
            if (temp == NULL) // condition in case if there is only one element in queue
            {
                front = rare = NULL;
            }
            else
            {
                front = temp;
                front->prev = NULL;
            }

            return x;
        }
    }
    // Only return the value without deleteing it
    int peekFront()
    {
        if (front != NULL)
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

        } while (temp != NULL);
        return size;
    }

    void printQueue()
    {
        if (front == NULL)
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
    Queue obj;
    int choice, value, priority;

    do
    {
        cout << "1. Insert element (sorted)\n2. Insert element (unsorted)\n3. Remove element by priority\n4. Remove front element\n5. Display queue\n6. Display front element\n7. Display size of queue\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value and priority: ";
            cin >> value >> priority;
            obj.sortedEqueue(value, priority);
            break;
        case 2:
            cout << "Enter value and priority: ";
            cin >> value >> priority;
            obj.equeue(value, priority);
            break;
        case 3:
            cout << "Enter priority to remove: ";
            cin >> priority;
            cout << "Removed element: " << obj.PriorityDequeue(priority) << endl;
            break;
        case 4:
            cout << "Removed element: " << obj.dequeue() << endl;
            break;
        case 5:
            obj.printQueue();
            cout << endl;
            break;
        case 6:
            cout << "Front element: " << obj.peekFront() << endl;
            break;
        case 7:
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
