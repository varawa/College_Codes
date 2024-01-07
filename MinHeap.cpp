#include <iostream>

class MinHeap {
private:
    int* heap;
    int capacity;
    int size;

    
    void heapify(int index) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        
        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    
    MinHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }

    
    ~MinHeap() {
        delete[] heap;
    }

    
    void insert(int value) {
        if (size == capacity) {
            std::cout << "Heap is full. Cannot insert more elements.\n";
            return;
        }

        heap[size++] = value;
        int index = size - 1;

        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap(10); 
    minHeap.insert(4);
    minHeap.insert(10);
    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.insert(1);

   
    std::cout << "Min Heap: ";
    minHeap.print();

    return 0;
}