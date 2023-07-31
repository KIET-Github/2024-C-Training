#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {}

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }

        int maxVal = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);

        return maxVal;
    }

    void printHeap() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(40);
    heap.insert(20);
    heap.insert(30);
    heap.insert(50);

    cout << "Max Heap: ";
    heap.printHeap();

    cout << "Extracting Max: " << heap.extractMax() << endl;

    cout << "Max Heap after extraction: ";
    heap.printHeap();

    return 0;
}
