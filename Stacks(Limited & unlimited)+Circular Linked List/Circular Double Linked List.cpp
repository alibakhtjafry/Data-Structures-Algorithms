// CIRCULAR LINKED LIST WITH DOUBLE POINTER
#include <iostream>
using namespace std;
class Node
{
public:
    Node *prev;
    Node *next;
    int val;
    Node(int data = 0, Node *p = NULL, Node *n = NULL)
    {
        val = data;
        prev = p;
        next = n;
    }
    void printData()
    {
        cout << val << " ";
    }
};
class CLL
{
    Node *first;
    Node *last;

public:
    CLL()
    {
        first = NULL;
        last = NULL;
    }
    void insertAtStart(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            last = first;
            first->prev = last;
            last->next = first;
        }
        else
        {
            Node *n = new Node(x);
            n->next = first;
            first->prev = n;
            first = n;
            last->next = first;
        }
    }
    void append(int x)
    {
        if (first == NULL)
        {
            first = new Node(x);
            first = last;
            first->prev = last;
            last->next = first;
        }
        else
        {
            Node *n = new Node(x);
            n->prev = last;
            last->next = n;
            last = n;
            last->next = first;
            first->prev = last;
        }
    }
    void insertBefore(int index, int x)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            Node *n = new Node(x);
            temp = first;
            while (temp->val != index && temp->next != first)
            {
                temp = temp->next;
            }
            if (temp == first)
            {
                insertAtStart(x);
            }
            else
            {
                n->prev = temp->prev;
                n->next = temp;
                temp->prev->next = n;
                temp->prev = n;
            }
        }
    }
    void insertAfter(int index, int x)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            Node *n = new Node(x);
            temp = first;
            while (temp->val != index && temp->next != first)
            {
                temp = temp->next;
            }
            if (temp == last)
            {
                append(x);
            }
            else
            {
                n->prev = temp;
                n->next = temp->next;
                temp->next->prev = n;
                temp->next = n;
            }
        }
    }
    // Ascending order
    void sortedInsertionAscending(int x)
    {
        if (first == NULL)
        {
            insertAtStart(x);
        }
        else
        {
            Node *temp;
            temp = first;
            Node *p = NULL;
            Node *n = new Node(x);

            while (temp->val < x && temp->next != first)
            {
                p = temp;
                temp = temp->next;
            }
            if (temp == first && x < temp->val)
            {
                insertAtStart(x);
            }
            else if (temp == last && x > temp->val)
            {
                append(x);
            }
            else
            {
                n->prev = p;
                n->next = temp;
                p->next = n;
                temp->prev = n;
            }
        }
    }
    // Decending Order insertion
    void sortedInsertionDecensding(int x)
    {
        if (first == NULL)
        {
            insertAtStart(x);
        }
        else
        {
            Node *temp;
            temp = first;
            while (temp->val > x && temp->next != first)
            {
                temp = temp->next;
            }
            if (temp == first && x > temp->val)
            {
                insertAtStart(x);
            }
            else if (temp == last && x < temp->val)
            {
                append(x);
            }
            else
            {
                Node *n = new Node(x);
                n->prev = temp->prev;
                n->next = temp;
                temp->prev->next = n;
                temp->prev = n;
            }
        }
    }
    // Deletion functions
    void deleteFirst()
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            if (first == last)
            {
                delete first;
                first = nullptr;
            }
            else
            {
                Node *temp = first;
                first = first->next;
                delete temp;
                first->prev = last;
                last->next = first;
            }
        }
    }
    void deleteEnd()
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            if (first->next == first)
            {
                delete first;
                first = nullptr;
            }
            else
            {
                Node *temp = last;
                last = last->prev;
                delete temp;
                last->next = first;
                first->prev = last;
            }
        }
    }
    void deleteKthOccurence(int index, int k)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            int count = 0;
            temp = first;
            while (temp->next != first)
            {
                if (temp->val == index)
                {
                    count++;
                    if (count == k)
                    {
                        break;
                    }
                    temp = temp->next;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (temp == first)
            {
                if (first == last)
                {
                    delete first;
                    // first==nullptr;
                }
                Node *temp = first;
                first = first->next;
                delete temp;
                first->prev = last;
                last->next = first;
            }
            else if (temp == last)
            {
                Node *temp;
                temp = last;
                last = last->prev;
                delete temp;
                last->next = first;
                first->prev = last;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
        }
    }
    void deleteKth(int k)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            int count = 0;
            temp = first;
            while (1)
            {
                count++;
                if (count == k)
                {
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (temp == first)
            {
                deleteFirst();
            }
            else if (first == last)
            {
                deleteEnd();
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
    void deleteAll(int val)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            temp = first;
            while (temp->next != first)
            {
                if (temp->val == val)
                {
                    if (temp == first)
                    {
                        deleteFirst();
                        temp = first;
                    }
                    else if (temp == last)
                    {
                        deleteEnd();
                        break;
                    }
                    else
                    {
                        Node *nextNode = temp->next;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                        temp = nextNode;
                    }
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (temp == last)
            {
                deleteEnd();
            }
            else
            {
                cout << "\nAll the Values are deleted  Successfully\n";
            }
        }
    }
    void printList()
    {
        Node *temp;
        if (first == last)
        {
            first->printData();
        }
        else
        {
            temp = first->next;
            first->printData();
            while (temp != first)
            {
                temp->printData();
                temp = temp->next;
            }
        }
    }
    void reverseDisplay()
    {
        Node *temp = last;
        do
        {
            temp->printData();
            temp = temp->prev;
        } while (temp != last);
    }
    ~CLL()
    {
        delete first;
        first = nullptr;
        delete last;
        last = nullptr;
    }
};
#include <iostream>
using namespace std;

int main()
{
    CLL cll;
    int choice, value, index, k;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at start\n";
        cout << "2. Append\n";
        cout << "3. Insert before value\n";
        cout << "4. Insert after value\n";
        cout << "5. Sorted insertion (ascending)\n";
        cout << "6. Sorted insertion (descending)\n";
        cout << "7. Delete first\n";
        cout << "8. Delete last\n";
        cout << "9. Delete kth occurrence of value\n";
        cout << "10. Delete kth node\n";
        cout << "11. Delete all occurrences of value\n";
        cout << "12. Print list\n";
        cout << "13. Reverse display\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at start: ";
            cin >> value;
            cll.insertAtStart(value);
            break;
        case 2:
            cout << "Enter value to append: ";
            cin >> value;
            cll.append(value);
            break;
        case 3:
            cout << "Enter value to insert before: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            cll.insertBefore(index, value);
            break;
        case 4:
            cout << "Enter value to insert after: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            cll.insertAfter(index, value);
            break;
        case 5:
            cout << "Enter value for sorted insertion (ascending): ";
            cin >> value;
            cll.sortedInsertionAscending(value);
            break;
        case 6:
            cout << "Enter value for sorted insertion (descending): ";
            cin >> value;
            cll.sortedInsertionDecensding(value);
            break;
        case 7:
            cll.deleteFirst();
            break;
        case 8:
            cll.deleteEnd();
            break;
        case 9:
            cout << "Enter value for deletion: ";
            cin >> index;
            cout << "Enter occurrence number to delete: ";
            cin >> k;
            cll.deleteKthOccurence(index, k);
            break;
        case 10:
            cout << "Enter position of node to delete: ";
            cin >> k;
            cll.deleteKth(k);
            break;
        case 11:
            cout << "Enter value to delete all occurrences: ";
            cin >> value;
            cll.deleteAll(value);
            break;
        case 12:
            cout << "List: ";
            cll.printList();
            cout << endl;
            break;
        case 13:
            cout << "Reverse List: ";
            cll.reverseDisplay();
            cout << endl;
            break;
        case 14:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
