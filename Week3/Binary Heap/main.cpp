#include <iostream>
using namespace std;

class MaxBinaryHeap {
private:
    int *heap;
    int capacity;
    int size;

    void swim(int k) {
        while (k > 0 && heap[(k - 1) / 2] < heap[k]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    void sink(int k) {
        while (2 * k + 1 < size) {
            int j = 2 * k + 1;
            if (j + 1 < size && heap[j + 1] > heap[j])
                j++;
            if (heap[k] >= heap[j])
                break;
            swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    MaxBinaryHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }

    ~MaxBinaryHeap() {
        delete[] heap;
    }

    void insert(int data) {
        if (size == capacity) {
            return;
        }
        heap[size] = data;
        swim(size);
        size++;
    }

    int delMax() {
        if (isEmpty()) {
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        sink(0);
        return maxVal;
    }

    bool isEmpty() {
        return size == 0;
    }

    int max() {
        if (isEmpty()) {
            return -1;
        }
        return heap[0];
    }


    int getSize() {
        return size;
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxBinaryHeap h(10);

    h.insert(10);
    h.insert(5);
    h.insert(30);
    h.insert(20);

    cout << "Heap hien tai: ";
    h.printHeap();

    cout << "Phan tu lon nhat: " << h.max() << endl;

    cout << "Xoa phan tu lon nhat: " << h.delMax() << endl;

    cout << "Heap sau khi xoa: ";
    h.printHeap();

    cout << "Kich thuoc heap: " << h.getSize() << endl;
}

