#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < n && heap[leftChild] < heap[smallest])
                smallest = leftChild;
            if (rightChild < n && heap[rightChild] < heap[smallest])
                smallest = rightChild;

            if (smallest == index)
                break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty())
            throw out_of_range("Heap is empty");

        int minElement = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
        return minElement;
    }

    int peekMin() {
        if (heap.empty())
            throw out_of_range("Heap is empty");
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(70);
    minHeap.insert(50);
    minHeap.insert(5);

    cout << "Min Heap: ";
    while (!minHeap.isEmpty())
        cout << minHeap.extractMin() << " ";
    cout << endl;

    return 0;
}
