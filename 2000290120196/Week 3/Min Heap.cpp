#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    // Helper function to move an element up to its correct position in the heap.
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Helper function to move an element down to its correct position in the heap.
    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    MinHeap() {}

    // Inserts a new element into the heap.
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Removes the minimum element (root) from the heap.
    void removeMin() {
        if (heap.empty()) {
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Returns the minimum element in the heap.
    int getMin() const {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty.");
        }
        return heap[0];
    }

    // Returns the size of the heap.
    int size() const {
        return heap.size();
    }

    // Checks if the heap is empty.
    bool empty() const {
        return heap.empty();
    }
};
