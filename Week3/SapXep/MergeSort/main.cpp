#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0;i < n1;i++) L[i] = a[left + i];
    for(int j = 0;j < n2;j++) R[j] = a[mid + 1 + j];

    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergeSort(int arr[],int left, int right) {
    if(left < right) {
        int mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 8, 4, 1, 7, 6, 3};
    int n = 8;

    mergeSort(arr, 0, n - 1);

    for(int x : arr) cout << x << " ";
    return 0;
}











