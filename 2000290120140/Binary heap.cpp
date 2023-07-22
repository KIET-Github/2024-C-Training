//MAX HEAP
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
struct PriorityQueue
{
private:
    vector<int> A;
    int PARENT(int i) 
    {
        return (i - 1) / 2;
    }
    int LEFT(int i) 
    {
        return (2*i + 1);
    }
    int RIGHT(int i) 
    {
        return (2*i + 2);
    }
void heapify_down(int i)
    {
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int largest = i;
 
        if (left < size() && A[left] > A[i]) {
            largest = left;
        }
        if (right < size() && A[right] > A[largest]) {
            largest = right;
        }
        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }
    void heapify_up(int i)
    {
        if (i && A[PARENT(i)] < A[i])
        {
            swap(A[i], A[PARENT(i)]);
 
            heapify_up(PARENT(i));
         }
    }
 
public:
    unsigned int size() 
    {
        return A.size();
    }
    bool empty() {
        return size() == 0;
    }
    void push(int key)
    {
        A.push_back(key);
 
        int index = size() - 1;
        heapify_up(index);
    }
    void pop()
    {
        try {
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
 
            A[0] = A.back();
            A.pop_back();
            heapify_down(0);
     }
        catch (const out_of_range &oor) 
        {
            cout << endl << oor.what();
        }
    }
    int top()
    {
        try {
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
            }
        catch (const out_of_range &oor) 
        {
            cout << endl << oor.what();
        }
    }
};
int main()
{
    PriorityQueue pq;
 
    pq.push(4);
    pq.push(3);
    pq.push(16);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(6);
    pq.push(5);
    pq.push(46);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
cout << endl << boolalpha << pq.empty();
 
    pq.top();    
    pq.pop(); 
 
    return 0;
}
