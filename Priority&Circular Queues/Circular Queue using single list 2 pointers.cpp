#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val = 0)
    {
        this->val = val;
        next = NULL;
    }
    void printVal()
    {
        cout << val << " ";
    }
};

class Queue
{
    Node *front;
    Node *rare;

public:
    Queue()
    {
        front = rare = NULL;
    }

    void eQueue(int item)
    {
        if (rare == NULL)
        {
            front = rare = new Node(item);
            rare->next = front;
        }
        else
        {
            Node *n = new Node(item);
            rare->next = n;
            rare = n;
            rare->next = front;
        }
    }

    int deQueue()
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
            }
            delete temp;

            return val;
        }
    }

    int peekFront()
    {
        if (front == NULL)
        {
            cout << "Queue Is Empty\n";
            return 0;
        }

        return front->val;
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
        if (front == NULL)
        {
            cout << "Queue Is Empty\n";
            return;
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
};

int main()
{
    Queue obj;
    int choice, value;

    do
    {
        cout << "1. Insert element\n2. Remove front element\n3. Display queue\n4. Display front element\n5. Display size of queue\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            obj.eQueue(value);
            break;
        case 2:
            cout << "Removed element: " << obj.deQueue() << endl;
            break;
        case 3:
            obj.printQueue();
            cout << endl;
            break;
        case 4:
            cout << "Front element: " << obj.peekFront() << endl;
            break;
        case 5:
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
