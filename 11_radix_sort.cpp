
/*
Radix Sort is a non-comparative integer sorting algorithm that sorts numbers by processing individual digits. It works by distributing the numbers into "buckets" according to each digit, starting from the least significant digit (LSD) to the most significant digit (MSD). Radix Sort is particularly efficient for sorting large lists of integers or strings.

How Radix Sort Works
Identify the Maximum Number:

Before sorting, determine the maximum number in the input array. This will help in figuring out how many digits need to be processed.
Digit Processing:

Radix Sort processes the numbers digit by digit. It typically uses a stable sorting algorithm (like Counting Sort) as a subroutine to sort the numbers based on each digit.
Sorting by Each Digit:

Starting from the least significant digit (the rightmost digit), sort the array using the chosen stable sorting algorithm.
Move to the next significant digit and repeat the sorting process until all digits have been processed.
*/


 /*

    Time Complexity:
    
    The time complexity of Radix Sort is 
    O(d × (n + k)), where:
    n is the number of elements in the array.
    k is the range of the input (for example, 10 for decimal numbers).
    d is the number of digits in the maximum number.
*/


#include <iostream>
#include <vector>
using namespace std;

// Function to perform counting sort based on the significant digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0}; // Initialize count array for digits (0-9)

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it contains the actual position of the digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to get the maximum value in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

// Function to perform radix sortS
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr); // Get the maximum number to determine number of digits

    // Perform counting sort for every digit (exp is 10^i where i is the current digit number)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}


void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
