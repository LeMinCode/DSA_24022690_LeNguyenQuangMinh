#include <iostream>
using namespace std;

class PriorityQueue {
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
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void push(int data) {
        if (size == capacity) {
            return;
        }
        heap[size] = data;
        swim(size);
        size++;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return heap[0];
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        sink(0);
        return maxVal;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);

    cout << "Hang doi uu tien hien tai: ";
    pq.print();

    cout << "Phan tu uu tien cao nhat: " << pq.top() << endl;

    cout << "Xoa phan tu uu tien cao nhat: " << pq.pop() << endl;

    cout << "Sau khi xoa: ";
    pq.print();

    cout << "Kich thuoc: " << pq.getSize() << endl;
}
