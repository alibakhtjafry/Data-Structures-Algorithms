//Ali Bakht Jafry
//BCSF22M044_SINGLE_LINKED_LIST_2_POINTER
//Naming convention like "functionName()" new word have capital
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node(int data = 0, Node *l = NULL)
    {
        this->data = data;
        link = l;
    }
    void printData()
    {
        cout << data << " ";
    }
};
class SLL
{
    Node *start;
    Node *end;

public:
    SLL()
    {
        start = NULL;
        end = NULL;
    }
    void printEnd()
    {
        cout << endl
             << end->data;
    }
    void insertAtStart(int val)
    {
        if (start == NULL)
        {
            start = new Node(val);
            end = start;
        }
        else
        {
            Node *t;
            t = new Node(val);
            t->link = start;
            start = t;
        }
    }
    void insertAtEnd(int val)
    {
        if (start == NULL)
        {
            start = new Node(val);
            end = start;
        }
        else
        {
            Node *t;
            t = new Node(val);
            end->link = t;
            end = t;
        }
    }
    void insertBefore(int index, int val)
    {
        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        else if (start->data == index)
        {
            insertAtStart(val);
        }
        else
        {
            Node *temp;
            Node *t;
            Node *prev;
            t = new Node(val);
            temp = prev = start;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    prev->link = t;
                    t->link = temp;
                }
                prev = temp;
                temp = temp->link;
            }
        }
    }
    void insertAfter(int index, int val)
    {
        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        else if (end->data == index)
        {
            insertAtEnd(val);
        }
        else
        {
            Node *temp;
            Node *t;
            t = new Node(val);
            temp = start;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    t->link = temp->link;
                    temp->link = t;
                }
                temp = temp->link;
            }
        }
    }
    void deleteFirst()
    {
        if (start == NULL)
        {
            cout << "List is empyt\n";
        }
        else
        {
            Node *temp;
            temp = start->link;
            delete start;
            start = temp;
        }
    }
    void deleteEnd()
    {
        if (start == NULL)
        {
            cout << "List is empyt\n";
        }
        else
        {
            Node *temp;
            temp = start;
            while (temp->link != end)
            {
                temp = temp->link;
            }
            temp->link = NULL;
            delete end;
            end = temp;
        }
    }
    void deleteAtKth(int index, int k)
    {
        if (start == NULL)
        {
            cout << "List is empyt\n";
        }
        else
        {
            Node *temp;
            Node *prev;
            temp = prev = start;
            int count = 0;
            bool check=true;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    count++;
                    if (count == k)
                    {
                        check=false;
                        if (temp == start)
                        {
                            deleteFirst();
                            break;
                        }
                        else if (temp == end)
                        {
                            deleteEnd();
                            break;
                        }
                        else
                        {
                            prev->link = temp->link;
                            delete temp;
                            break;
                        }
                    }
                }
                prev = temp;
                temp = temp->link;
            }
            if(check==true){
                cout<<endl<<"!!!"<<index<<" Have no "<<k<<" th occurence \n";
            }
        }
    }
    void deleteAll(int index)
{
    if (start == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        Node *temp;
        Node *prev;
        temp = start;
        prev = start;

        while (temp != NULL)
        {
            if (temp->data == index)
            {
                if (temp == start)
                {
                    deleteFirst();
                    temp = start;
                }
                else if (temp == end)
                {
                    deleteEnd();
                    break;
                }
                else
                {
                    prev->link = temp->link;
                    delete temp;
                    temp = prev->link;
                }
            }
            else
            {
                prev = temp;
                temp = temp->link;
            }
        }
    }
}
    void ReverseList()
    {
        if (start == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }
        else
        {
            Node *prev = NULL;
            Node *temp = start;
            end = start;
            while (temp != NULL)
            {
                Node *next = temp->link;
                temp->link = prev;
                prev = temp;
                temp = next;
            }
            start = prev;
        }
    }
    void printList()
    {
        Node *temp;
        temp = start;
        while (temp != NULL)
        {
            temp->printData();
            temp = temp->link;
        }
    }
    void printReverse()
    {
        ReverseList();
        Node *temp;
        temp = start;
        while (temp != NULL)
        {
            temp->printData();
            temp = temp->link;
        }
    }
    ~SLL()
    {
        delete start;
        delete end;
        start = nullptr;
        end = nullptr;
    }
};
int main()
{
    SLL obj;

    // Test insertAtStart
    obj.insertAtStart(10);
    obj.insertAtStart(20);
    obj.insertAtStart(30);
    cout << "List after inserting 30, 20, 10 at start: ";
    obj.printList();
    cout << endl;

    // Test insertAtEnd
    obj.insertAtEnd(40);
    obj.insertAtEnd(50);
    cout << "List after inserting 40, 50 at end: ";
    obj.printList();
    cout << endl;

    // Test insertBefore
    obj.insertBefore(10, 5);
    cout << "List after inserting 5 before 10: ";
    obj.printList();
    cout << endl;

    // Test insertAfter
    obj.insertAfter(10, 15);
    cout << "List after inserting 15 after 10: ";
    obj.printList();
    cout << endl;

    // Test deleteFirst
    obj.deleteFirst();
    cout << "List after deleting the first element: ";
    obj.printList();
    cout << endl;

    // Test deleteEnd
    obj.deleteEnd();
    cout << "List after deleting the last element: ";
    obj.printList();
    cout << endl;

    // Test deleteAtKth
    obj.deleteAtKth(10, 1);
    cout << "List after deleting the 1st occurrence of 10: ";
    obj.printList();
    cout << endl;

    // Test deleteAll
    obj.insertAtEnd(10);
    obj.insertAtEnd(10);
    obj.deleteAll(10);
    cout << "List after deleting all occurrences of 10: ";
    obj.printList();
    cout << endl;

    // Test ReverseList
    obj.ReverseList();
    cout << "List after reversing: ";
    obj.printList();
    cout << endl;

    // Test printReverse
    cout << "List after printing in reverse: ";
    obj.printReverse();
    
    cout << endl;

    return 0;
}
