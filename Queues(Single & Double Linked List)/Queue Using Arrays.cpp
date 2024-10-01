#include <iostream>
using namespace std;
class Queue
{
public:
    int *que;
    int front;
    int rare;
    int size;
    int noOfelements = 0; // using for helping member and making implementation easier(keep track of elements)
    Queue(int size)
    {
        this->size = size;
        front = rare = -1;
        que = new int[size];
    }
    ~Queue()
    {
        delete que;
        que = nullptr;
    }
    bool isFul()
    {
        if (noOfelements == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (noOfelements == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void equeue(int val)
    {
        if (isFul())
        {
            cout << "Queue is full\n";
        }
        else
        {
            // this line also change the rare to its appropriate index
            rare = ((rare + 1) % size); // to adjust it againa at the start if there is any space in the front side of the queue
            que[rare] = val;
            noOfelements++;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            front = rare = -1;
            cout << "queue is empty\n";
            return -1;
        }
        else
        {
            front = (front + 1) % size; // before value taking becz at start the front==-1 so set it to start index
            int value = que[front];
            noOfelements--;
            return value;
        }
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return 0;
        }
        else
        {
            return que[front + 1];
        }
    }
    int getRare()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return 0;
        }
        else
        {
            return que[rare];
        }
    }
    int getSize()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        else
        {
            return noOfelements;
        }
    }
    // if after dequeue there is equeue then it will start from the front and print appropriately with new one at the end
    void printQueue()
    {
        if (isEmpty())
            cout << "Empty Queue" << endl;
        int count = noOfelements;
        int i = (front + 1) % size;
        while (count > 0)
        {
            cout << que[i] << " ";
            i = (i + 1) % size;
            count--;
        }
        cout << endl;
    }
};
int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue element\n";
        cout << "2. Dequeue element\n";
        cout << "3. Get front element\n";
        cout << "4. Get rear element\n";
        cout << "5. Display queue\n";
        cout << "6. Check if queue is empty\n";
        cout << "7. Check if queue is full\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int element;
            cout << "Enter element to enqueue: ";
            cin >> element;
            q.equeue(element);
            break;
        }
        case 2:
        {
            int dequeuedElement = q.dequeue();
            if (dequeuedElement != -1)
            {
                cout << "Dequeued element: " << dequeuedElement << endl;
            }
            break;
        }
        case 3:
        {
            int frontElement = q.getFront();
            if (frontElement != 0)
            {
                cout << "Front element: " << frontElement << endl;
            }
            break;
        }
        case 4:
        {
            int rearElement = q.getRare();
            if (rearElement != 0)
            {
                cout << "Rear element: " << rearElement << endl;
            }
            break;
        }
        case 5:
            q.printQueue();
            break;
        case 6:
            if (q.isEmpty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;
        case 7:
            if (q.isFul())
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                cout << "Queue is not full." << endl;
            }
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}