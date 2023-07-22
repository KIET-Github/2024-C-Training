
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < n && heap[leftChild] > heap[largest])
                largest = leftChild;
            if (rightChild < n && heap[rightChild] > heap[largest])
                largest = rightChild;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty())
            throw out_of_range("Heap is empty");

        int maxElement = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
        return maxElement;
    }

    int peekMax() {
        if (heap.empty())
            throw out_of_range("Heap is empty");
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(50);
    maxHeap.insert(20);
    maxHeap.insert(70);

    cout << "Max Heap: ";
    while (!maxHeap.isEmpty())
        cout << maxHeap.extractMax() << " ";
    cout << endl;

    return 0;
}
