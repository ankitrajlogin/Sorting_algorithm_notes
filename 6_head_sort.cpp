/*
Heap Sort Algorithm
First convert the array into a max heap using heapify, Please note that this happens in-place. The array elements are re-arranged to follow heap properties. Then one by one delete the root node of the Max-heap and replace it with the last node and heapify. Repeat this process while size of heap is greater than 1.

1. Rearrange array elements so that they form a Max Heap.

2. Repeat the following steps until the heap contains only one element:
i. Swap the root element of the heap (which is the largest element in current heap) with the last element of the heap.
ii. Remove the last element of the heap (which is now in the correct position). We mainly reduce heap size and do not remove element from the actual array.
iii. Heapify the remaining elements of the heap.

3. Finally we get sorted array.
*/

#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 


    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }


    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr) {
    int n = arr.size();

    // build head( rearrange vector) ; 
    // we can run from n-1 but no need as there is no parent have on n-1 and n-2 ---. 
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main() {
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };

    heapSort(arr);
    cout << "Sorted array is: \n";
    printArray(arr);

    return 0;
}
