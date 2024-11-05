/*
Explanation of the Code
Insertion Sort Function: This function sorts each individual bucket using the Insertion Sort algorithm.

Bucket Sort Function:

Create Buckets: Determine the number of buckets based on the square root of the number of elements.
Distribute Elements: Place each element into the appropriate bucket based on its value.
Sort Buckets: Each bucket is sorted using the insertion sort.
Concatenate: After sorting, all the elements from the buckets are combined back into the original array.
Print Array Function: This utility function prints the contents of the array.

Main Function: This is where the array is defined, and the bucket sort is called. It prints the original and sorted arrays to show the result.
*/


#include <iostream>
#include <vector>

using namespace std;

// Function to perform insertion sort on a bucket
void insertionSort(vector<int>& bucket) {
    for (size_t i = 1; i < bucket.size(); ++i) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            --j;
        }
        bucket[j + 1] = key;
    }
}

// Function to find the maximum element in the array
int findMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

// Function to perform bucket sort
void bucketSort(vector<int>& arr) {
    // Step 1: Create empty buckets
    int n = arr.size();
    if (n <= 0) return; // Handle empty array

    // Find the maximum value to determine the range of the buckets
    int maxValue = findMax(arr);
    int bucketCount = 10; // You can adjust the number of buckets
    vector<vector<int>> buckets(bucketCount);

    // Step 2: Distribute the elements into buckets
    for (int num : arr) {
        int bucketIndex = (num * bucketCount) / (maxValue + 1);
        buckets[bucketIndex].push_back(num);
    }

    // Step 3: Sort each bucket and concatenate the results
    arr.clear(); // Clear original array
    for (auto& bucket : buckets) {
        insertionSort(bucket); // Sort each bucket
        for (int num : bucket) {
            arr.push_back(num); // Concatenate the sorted buckets
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to demonstrate bucket sort
int main() {
    vector<int> arr = {4, 5, 4, 5, 4, 5, 6, 7, 6};
    
    cout << "Original array: ";
    printArray(arr);
    
    bucketSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}
