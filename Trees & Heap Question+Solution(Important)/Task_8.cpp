// Sort all the values present in a binary tree using heap sort.
#include <iostream>
#include <cmath>
using namespace std;
class Tree
{
public:
    int *tree;
    int size;
    int count;

    Tree(int levels)
    {
        this->size = pow(2, levels) - 1; // as size does not effect by 1-index so....
        // levels are 2^power
        this->count = 1;
        tree = new int[size + 1]; // as tree starts from zero index
        for (int i = 1; i <= size; i++)
        {
            tree[i] = -1; // making as all nulls
        }
    }

    ~Tree()
    {
        delete[] tree;
        tree = nullptr;
    }

    bool isFull()
    {
        if (count == size + 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (count == 1)
            return true;
        return false;
    }

    // void insert(int value){
    //     if(isFull()){
    //         cout<<"Tree is Full\n";
    //         return;
    //     }
    //     else{
    //         tree[count++]=value;
    //         int i=count-1;
    //         while(i>1){
    //             int j=i/2;
    //             if(tree[i]<tree[j]){
    //                 swap(tree[i],tree[j]);
    //                 i=j;
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     }
    // }
    void printTree()
    {
        int k = 0;
        for (int i = 1; i < count; i++)
        {
            if (i == pow(2, k)) // as it will print levels (level=2^pow)
            {
                k++;
                cout << endl;
            }
            cout << " " << tree[i];
        }
        cout << endl;
    }
    // give max heap
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right <= n && arr[largest] < arr[right])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest); // if after swap there is child then this happens
        }
    }
    void heapSort(int arr[], int n)
    {
        int temp = n;
        while (temp > 1)
        {
            swap(arr[temp], arr[1]);

            temp--;

            heapify(arr, temp, 1);
        }
    }
};
int main()
{
    int level;
    cout << "Enter the number of levels you want to enter: ";
    cin >> level;

    Tree obj(level);

    cout << "\nEnter the number of elements (up to " << obj.size << "): ";
    int numEle = 0;
    for (int i = 1; i <= obj.size; i++)
    {
        cin >> obj.tree[i]; // Read directly into the tree array
        numEle++;
    }

    // Build the max heap from the tree
    for (int i = numEle / 2; i >= 1; i--)
    {
        obj.heapify(obj.tree, numEle, i);
    }

    // Sort the array using heap sort
    obj.heapSort(obj.tree, numEle);

    cout << "Sorted Array will be: ";
    for (int j = 1; j <= numEle; j++)
    {
        cout << obj.tree[j] << " ";
    }
    cout << endl;

    return 0;
}
