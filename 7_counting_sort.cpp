/*
What is Counting Sort?
Counting Sort is a non-comparison-based sorting algorithm. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted. The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return arr;  // Handle empty array case

    // Step 1: Find the maximum value in the array
    int M = *max_element(arr.begin(), arr.end());

    // Step 2: Create the count array
    vector<int> count(M + 1, 0);

    // Step 3: Count the occurrences of each element
    for (int num : arr) {
        count[num]++;
    }

    // Step 4: Update the count array to store cumulative counts
    for (int i = 1; i <= M; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the output array using the count array
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return output;  // Return the sorted array
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    vector<int> sortedArr = countingSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
