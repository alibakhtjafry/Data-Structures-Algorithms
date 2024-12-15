//Ali Bakht Jafry
//BCSF22M044_SINGLE_LINKED_LIST_1_POINTER
//Naming convention like "functionName()" new word have capital
#include <iostream>
using namespace std;
class Node
{
public:
    Node *link;
    int data;
    Node()
    {
        data = 0;
        link = NULL;
    }
    Node(int x)
    {
        data = x;
        link = NULL;
    }

    void printData()
    {
        cout << data << " ";
    }
};
class SLL
{
public:
    Node *start;
    SLL()
    {
        start = NULL;
    }
    Node *getstart()
    {
        return start;
    }
    void insertAtEnd(int num)
    {
        if (start == NULL)
        {
            start = new Node(num);
        }
        else
        {
            Node *temp;
            temp = start;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = new Node(num);
        }
    }
    void insertAtStart(int num)
    {
        if (start == NULL)
        {
            start = new Node(num);
        }
        else
        {
            Node *temp;
            temp = new Node(num);
            temp->link = start;
            start = temp;
        }
    }
    Node *search(int num)
    {
        Node *temp;
        temp = NULL;
        temp = start;
        if (start == NULL)
        {
            cout << "Empty List\n";
        }
        else
        {

            while (temp != NULL)
            {
                if (temp->data == num)
                {
                    cout << "\nValue found\n";
                    return temp;
                }
                temp = temp->link;
            }
        }
        cout << "\nValue Not found\n";
        return temp;
    }
    void insertBefore(int num1, int val)
    {
        Node *temp;
        Node *previous;
        Node *newNode;
        temp = start;
        previous = NULL;
        newNode = new Node(val);
        if (start == NULL)
        {
            cout << "Empty List\n";
            exit(0);
        }
        if (start->data == num1)
        {
            newNode->link = start;
            start = newNode;
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->data == num1)
                {
                    break;
                }
                previous = temp;
                temp = temp->link;
            }
            previous->link = newNode;
            newNode->link = temp;
        }
    }
    void insertAfter(int num1, int val)
    {
        if (start == NULL)
        {
            cout << "Empty list\n";
            exit(0);
        }
        Node *temp;
        Node *after;
        Node *newNode;
        temp = start;
        after = NULL;
        newNode = new Node(val);
        while (temp != NULL)
        {
            if (temp->data == num1)
            {
                after = temp->link;
                break;
            }
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = after;
    }
    void deleteAtStart()
    {
        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            Node *temp;
            temp = start;
            start = start->link;
            delete temp;
        }
    }
    void deleteAtEnd()
    {
        Node *temp;
        Node *prev;
        prev = start;
        temp = start;
        if (start == NULL)
        {
            cout << "Empty List\n";
        }
        else if (start->link == NULL)
        {
            deleteAtStart();
        }
        else
        {

            while (temp->link != NULL)
            {
                prev = temp;
                temp = temp->link;
            }
            prev->link = NULL;
            delete temp;
        }
    }
    void deleteAtSpecific(int index)
    {
        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        else if (start->data == index)
        {
            deleteAtStart();
        }
        else
        {
            Node *temp;
            Node *previous;
            previous = start;
            temp = start;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    if (temp->link == NULL)
                    {
                        deleteAtEnd();
                        break;
                    }
                    else
                    {
                        Node *temp2;
                        temp2 = temp->link;
                        previous->link = temp2;
                        delete temp;
                        break;
                    }
                }
                previous = temp;
                temp = temp->link;
            }
        }
    }
    void deleteAtKth(int index, int k)
    {
        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            int count = 0;
            Node *temp;
            Node *previous;
            temp = previous = start;
            bool check = true;
            while (temp != NULL)
            {
                if (temp->data == index)
                {
                    count++;
                    if (count == k)
                    {
                        check = false;
                        if (temp == start)
                        {
                            deleteAtStart();
                            break;
                        }
                        else if (temp->link == NULL)
                        {
                            deleteAtEnd();
                            break;
                        }
                        else
                        {
                            previous->link = temp->link;
                            delete temp;
                            break;
                        }
                    }
                }
                previous = temp;
                temp = temp->link;
            }
            if (check == true)
            {
                cout << endl
                     << "!!!" << index << " Have no " << k << " th occurence \n";
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
                        deleteAtStart();
                        temp = start;
                    }
                    else if (temp->link == NULL)
                    {
                        deleteAtEnd();
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
    void printReverse()
    {
        ReverseList();
        printList();
    }
    
    void removeNthFromEnd(int n) {
        if(start==NULL){
           cout<<"a";
        }
        else{
            int l=0;
            Node* temp;
            temp=start;
            while(temp!=NULL){
                l++;
                temp=temp->link;
            }
            temp=NULL;
            temp=start;
            Node* p=start;
            l=l+1;
            while(temp!=NULL){
                l--;
                if(l==n){
                    if(temp->link==NULL){
                        p->link=NULL;
                        delete temp;
                        break;
                    }
                    else{
                        p->link=temp->link;
                        delete temp;
                        break;
                    }
                    }
                else{
                    p=temp;
                    temp=temp->link;
                }
              
            }
        }
    }
    void rotateRight(int k) {
        if(start==NULL){
            // return NULL;
        }
        if(start->link==NULL){
            // return start;
        }
        else{
            Node* temp=start;
            int length=1;
            while(temp->link!=NULL){
                length++;
                temp=temp->link;
            }
            Node* last=start;
             while(last->link!=NULL){
                last=last->link;
             }

            length=length-k;
            int c=0;
            temp=start;
            // ListNode* temp2=start;
            while(temp!=NULL){
                c++;
                if(length==c){
                    break;
                }
                else{
                    temp=temp->link;
                }
            }
            last->link=start;
            start=temp->link;
            temp->link=NULL;
        }
        // return start;
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
    ~SLL(){
        delete start;
        start=nullptr;
    }
};
int main()
{
    SLL obj;

    // Inserting elements at the end of the list
    obj.insertAtEnd(10);
    obj.insertAtEnd(20);
    obj.insertAtEnd(30);
    obj.insertAtEnd(40);
    obj.insertAtEnd(10);

    // // Printing the list
    // cout << "Original List: ";
    // obj.printList();
    // cout << endl;

    // // Inserting elements at the start of the list
    // obj.insertAtStart(5);
    // cout << "After inserting 5 at start: ";
    // obj.printList();
    // cout << endl;

    // // Inserting before a specific element
    // obj.insertBefore(20, 15);
    // cout << "After inserting 15 before 20: ";
    // obj.printList();
    // cout << endl;

    // // Inserting after a specific element
    // obj.insertAfter(30, 35);
    // cout << "After inserting 35 after 30: ";
    // obj.printList();
    // cout << endl;

    // // Deleting the first element
    // obj.deleteAtStart();
    // cout << "After deleting the first element: ";
    // obj.printList();
    // cout << endl;

    // // Deleting the last element
    // obj.deleteAtEnd();
    // cout << "After deleting the last element: ";
    // obj.printList();
    // cout << endl;

    // // Deleting a specific element
    // obj.deleteAtSpecific(20);
    // cout << "After deleting 20: ";
    // obj.printList();
    // cout << endl;

    // // Deleting the kth occurrence of an element
    // obj.deleteAtKth(10, 2);
    // cout << "After deleting the 2nd occurrence of 10: ";
    // obj.printList();
    // cout << endl;

    // // Deleting all occurrences of an element
    // obj.deleteAll(30);
    // cout << "After deleting all occurrences of 30: ";
    // obj.printList();
    // cout << endl;

    // // Reversing the list
    // obj.ReverseList();
    // cout << "After reversing the list: ";
    // obj.printList();
    // cout << endl;

    // // Printing the list in reverse order (which is reversed again)
    // cout << "Printing the list in reverse order: ";
    // obj.printReverse();
    // cout << endl;
    obj.printList();
    cout<<endl;
    obj.rotateRight(2);
    // obj.removeNthFromEnd(1);
    obj.printList();

    return 0;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
