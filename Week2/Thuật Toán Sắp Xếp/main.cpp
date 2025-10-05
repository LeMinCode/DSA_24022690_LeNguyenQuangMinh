#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

bool searchElement(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int arr[n];
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "* Sap xep lua chon" << endl;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "* Sap xep noi bot" << endl;
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "* Sap xep chen" << endl;
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int x;
    cout << "*Nhap phan tu X can tim: ";
    cin >> x;
    if (searchElement(arr, n, x))
        cout << "Phan tu " << x << " co trong mang" << endl;
    else
        cout << "Phan tu " << x << " khong co trong mang" << endl;

    return 0;
}
