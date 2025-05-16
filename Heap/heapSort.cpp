#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index 'i'
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max Heap
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);       // Move current root to end
        heapify(arr, i, 0);         // Call max heapify on the reduced heap
    }
}

int main() {
    vector<int> v = {30, 24, 20, 23, 19, 12, 18, 22, 14, 17, 15};

    cout << "Original array:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    heapSort(v);

    cout << "Sorted array using Heap Sort:\n";
    for (int x : v) cout << x << " ";
    cout << "\n";

    return 0;
}
