//Ali Bakht Jafry
//BCSF22M044_DOUBLE_LINKED_LIST_2_POINTER
//Naming convention like "functionName()" new word have capital
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d = 0, Node *p = NULL, Node *n = NULL)
    {
        data = d;
        prev = p;
        next = n;
    }
    void printData()
    {
        cout << data << " ";
    }
};
class DLL
{
    Node *first;
    Node *last;

public:
    DLL()
    {
        first = NULL;
        last = NULL;
    }
    void insertAtEnd(int val)
    {
        if (first == NULL)
        {
            first = new Node(val);
            last = first;
        }
        else
        {
            Node *t;
            t = new Node(val);
            last->next = t;
            t->prev = last;
            last = t;

        }
    }
    void lastPrint()
    {
        cout << last->data << endl;
    }
    void printFirst()
    {
        cout << first->data << endl;
    }
    void insertAtStart(int val)
    {
        if (first == NULL)
        {
            first = new Node(val);
            last = first;
        }
        else
        {
            Node *t;
            t = new Node(val);
            first->prev = t;
            t->next = first;
            first = t;
        }
    }
    void insertBefore(int index, int val)
    {
        if (first == NULL)
        {
            cout << "List is Empty\n";
        }
        if (first->data == index)
        {
            insertAtStart(val);
        }
        else
        {
            Node *t;
            t = new Node(val);
            Node *temp;
            temp = first;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    t->next = temp;
                    t->prev = temp->prev;
                    temp->prev->next = t;
                    temp->prev = t;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    void insertAfter(int index, int val)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        if (last->data == index)
        {
            insertAtEnd(val);
        }
        else
        {
            Node *t;
            t = new Node(val);
            Node *temp;
            temp = first;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    t->prev = temp;
                    t->next = temp->next;
                    temp->next->prev = t;
                    temp->next = t;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    void deleteStart()
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            temp = first;
            if (first->next != NULL)
                first->next->prev = NULL;
            first = first->next;
            delete temp;
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
            Node *temp;
            temp = last;
            temp=temp->prev;
            temp->next=NULL;
            last=temp;
        }
    }
    void deleteAtSpecific(int index)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        if (first->data == index)
        {
            deleteStart();
        }
        if (last->data == index)
        {
            deleteEnd();
        }
        else
        {
            Node *temp;
            temp = first;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    void deleteAll(int index)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            temp = first;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    if (temp==first)
                    {
                        deleteStart();
                        delete temp;
                        temp = first;
                    }
                    if (temp == last)
                    {
                        deleteEnd();
                        break;
                    }
                    if (temp->data == index)
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp = temp->next;
                    }
                }
                else
                    temp = temp->next;
            }
        }
    }
    
    void deleteAtKth(int index, int k)
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
            bool check = true;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    count++;
                    if (count == k)
                    {
                        check = false;
                        if (temp == first)
                        {
                            deleteStart();
                            break;
                        }
                        if (temp == last)
                        {
                            deleteEnd();
                            break;
                        }
                        else
                        {
                            temp->prev->next = temp->next;
                            temp->next->prev = temp->prev;
                            break;
                        }
                    }
                }
                temp = temp->next;
            }
            if (check == true)
            {
                cout << endl
                     << "!!!" << index << " Have no " << k << " th occurence \n";
            }
        }
    }
    void printReverse()
    {
        Node *temp;
        temp = last;
        while (temp != NULL)
        {
            temp->printData();
            temp = temp->prev;
        }
    }
    void reverseList()
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            temp = first;
            Node *temp2 = last;
            
            while (temp != temp2 && temp->prev != temp2)
            {
                int t1 = temp->data;
                int t2 = temp2->data;
                temp->data = t2;
                temp2->data = t1;

                temp = temp->next;
                temp2 = temp2->prev;
            }
        }
    }
    void printList()
    {
        Node *temp;
        temp = first;
        while (temp != NULL)
        {
            temp->printData();
            temp = temp->next;
        }
    }
    ~DLL()
    {
        delete first;
        delete last;
        first = nullptr;
        last = nullptr;
    }
};
int main()
{
    DLL obj;

    // Inserting elements
    obj.insertAtEnd(10);
    obj.insertAtEnd(20);
    obj.insertAtEnd(30);
    obj.insertAtStart(5);
    obj.insertAtStart(2);

    cout << "Initial list: ";
    obj.printList(); 
    cout << endl;

    // Inserting before and after
    obj.insertBefore(20, 15);
    obj.insertAfter(30, 35);

    cout << "List after insertions: ";
    obj.printList();
    cout << endl;

    // Deleting elements
    obj.deleteStart();
    obj.deleteEnd();
    obj.deleteAtSpecific(10);

    cout << "List after deletions: ";
    obj.printList();
    cout << endl;

    // Deleting all occurrences
    obj.deleteAll(20);

    cout << "List after deleting all occurrences of 20: ";
    obj.printList(); 
    cout << endl;

    // Deleting at kth occurrence
    obj.deleteAtKth(5, 1); // Deleting second occurrence of 5

    cout << "List after deleting 2nd occurrence of 5: ";
    obj.printList(); 
    cout << endl;

    // Printing in reverse order
    cout << "Reverse list: ";
    obj.printReverse(); 
    cout << endl;

    // Reversing the entire list
    obj.reverseList();

    cout << "Reversed list: ";
    obj.printList();
    cout << endl;

    return 0;
}
