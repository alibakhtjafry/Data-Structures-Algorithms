//Ali Bakht Jafry
//BCSF22M044_DOUBLE_LINKED_LIST_1_POINTER
//Naming convention like "functionName()" new word have capital
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
class DLL
{
    Node *first;

public:
    DLL()
    {
        first = NULL;
    }
    void insertAtStart(int val)
    {
        if (first == NULL)
        {
            first = new Node(val);
        }
        else
        {
            Node *t;
            t = new Node(val);
            t->prev = NULL;
            t->next = first;
            first = t;
        }
    }
    void insertAtEnd(int val)
    {
        if (first == NULL)
        {
            first = new Node(val);
        }
        else
        {
            Node *t;
            t = new Node(val);
            Node *last;
            last = first;
            if (first->next == NULL)
            {
                last = first;
            }
            else
            {
                while (last->next != NULL)
                {
                    last = last->next;
                }
            }
            t->prev = last;
            last->next = t;
        }
    }
    void insertBefore(int index, int val)
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else if (first->data == index)
        {
            insertAtStart(val);
        }
        else
        {
            Node *temp;
            // Node* prev;
            Node *t;
            t = new Node(val);
            temp = first;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    t->prev = temp->prev->next;
                    t->next = temp;
                    temp->prev->next = t;
                    temp->prev = t;
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
                    if (temp->next == NULL)
                    {
                        insertAtEnd(val);
                    }
                    else
                    {
                        t->prev = temp;
                        t->next = temp->next;
                        temp->next->prev = t;
                        temp->next = t;
                    }
                }
                temp = temp->next;
            }
        }
    }
    void deleteFirst()
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
        else if(first->next == NULL)
        {
            first = nullptr;
        }
        else
        {
            Node *temp;
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *last;
            last = temp->prev;
            last->next = NULL;
            delete temp;
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
            bool check=true;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    count++;
                    if (count == k)
                    {
                        check=false;
                        if (temp->prev == NULL)
                        {
                            deleteFirst();
                            break;
                        }
                        if (temp->next == NULL)
                        {
                            deleteEnd();
                            break;
                        }
                        else
                        {
                            temp->prev->next = temp->next;
                            temp->next->prev = temp->prev;
                            delete temp;
                            break;
                        }
                    }
                }
                temp = temp->next;
            }
            if(check==true){
                cout<<endl<<"!!!"<<index<<" Have no "<<k<<" th occurence \n";
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
                    if (temp->prev == NULL)
                    {
                        deleteFirst();
                        // delete temp;
                        temp = first;
                    }
                    if (temp->next == NULL)
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
    void listReverse()
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            Node *p = NULL;
            temp = first;

            while (temp != NULL)
            {
                Node *next = temp->next;
                temp->next = p;
                temp->prev = next;
                p = temp;
                temp = next;
            }
            first = p;
        }
    }
    void printReverse()
    {
        if (first == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            listReverse();
            printList();
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
        first = nullptr;
    }
};
int main()  
{
    DLL obj;

    // Inserting elements at start and end
    obj.insertAtStart(10);
    obj.insertAtStart(5);
    obj.insertAtEnd(15);
    obj.insertAtEnd(20);

    cout << "Initial list: ";
    obj.printList(); 
    cout << endl;

    // Inserting before and after specific elements
    obj.insertBefore(15, 12);
    obj.insertAfter(10, 8);

    cout << "List after insertions: ";
    obj.printList(); 
    cout << endl;

    // Deleting first and last elements
    obj.deleteFirst();
    obj.deleteEnd();

    cout << "List after deleting first and last elements: ";
    obj.printList(); 
    cout << endl;

    // Deleting at kth occurrence
    obj.insertAtEnd(10);
    obj.deleteAtKth(10, 2);

    cout << "List after deleting 2nd occurrence of 10: ";
    obj.printList(); 
    cout << endl;

    // Deleting all occurrences of a specific element
    obj.insertAtEnd(15);
    obj.insertAtEnd(15);
    obj.deleteAll(15);

    cout << "List after deleting all occurrences of 15: ";
    obj.printList(); 
    cout << endl;

    // Printing list in reverse
    cout << "Reversed list: ";
    obj.printReverse(); 
    cout << endl;

    // Printing original list again to verify the reverse function worked correctly
    cout << "Original list: ";
    obj.printList();
    cout << endl;

    return 0;
}
