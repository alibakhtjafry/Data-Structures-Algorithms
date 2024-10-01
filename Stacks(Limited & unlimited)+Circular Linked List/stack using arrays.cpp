// Stack using Array (limited stack)
#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *stack;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        stack = new int[size];
    }
    void PUSH(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack is FULL" << endl;
        }
        else
        {
            top++;
            stack[top] = x;
        }
    }
    int POP()
    {
        if (top == -1)
        {
            cout << "Stack is EMPTY" << endl;
            return -1;
        }
        int x = stack[top--];
        return x;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == size - 1) // if top is full
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is EMPTY" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) // Last in First Out
        {
            cout << stack[i];
            if (i == top)
                cout << "   <- TOP";
            cout << endl;
        }
        cout << endl;
    }
};
// main() to check the implementation of the Functions
int main()
{
    Stack stack(5);

    stack.PUSH(10);
    stack.PUSH(20);
    stack.PUSH(30);
    stack.PUSH(40);
    stack.PUSH(50);

    cout << "Stack after pushing 5 elements:" << endl;
    stack.display();

    stack.PUSH(60);

    cout << "Popped element: " << stack.POP() << endl;
    cout << "Popped element: " << stack.POP() << endl;

    cout << "Stack after popping 2 elements:" << endl;
    stack.display();

    // Check if stack is empty
    if (stack.isEmpty())
    {
        cout << "Stack is EMPTY" << endl;
    }
    else
    {
        cout << "Stack is NOT EMPTY" << endl;
    }

    if (stack.isFull())
    {
        cout << "Stack is FULL" << endl;
    }
    else
    {
        cout << "Stack is NOT FULL" << endl;
    }

    return 0;
}
