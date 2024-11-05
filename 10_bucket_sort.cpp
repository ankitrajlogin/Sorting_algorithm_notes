
/*
Bucket Sort is a sorting algorithm that divides elements into different "buckets" and then sorts each bucket individually. It’s particularly useful when elements are uniformly distributed over a range, as it allows us to sort elements in linear time under ideal conditions.

Here’s how Bucket Sort works step-by-step:

Steps of Bucket Sort
Divide Elements into Buckets:

1. Choose a number of buckets based on the input size and range.
2. Calculate the interval/range of values each bucket will hold.
3. Distribute each element from the array into the appropriate bucket based on its value.
Sort Each Bucket:

4. Each bucket is sorted individually. This can be done using any sorting algorithm, such as Insertion Sort or even a recursive application of another sorting algorithm (like Merge Sort or Quick Sort) if there are many elements in each bucket.
Concatenate Buckets:

Once all buckets are sorted, concatenate them to get the final sorted array.

Complexity:
Best Case: O(n) when elements are uniformly distributed across buckets.
Worst Case: O(n^2) if all elements fall into a single bucket, making it behave like a quadratic sort.
Average Case: O(n + k * log(k)), where k is the average number of elements per bucket.

*/

#include <iostream>
#include <vector>
using namespace std;

// Insertion sort function to sort individual buckets
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    // we can also difine for which range value which index it goes. 
    
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

// Driver program to test above function
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

