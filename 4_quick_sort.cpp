
/*
How does QuickSort Algorithm work?
QuickSort works on the principle of divide and conquer, breaking down the problem into smaller sub-problems.

There are mainly three steps in the algorithm:

1. Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
2. Partition the Array: Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct position, and we obtain the index of the pivot.
3. Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).
4. Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.
*/


#include<bits/stdc++.h>
using namespace std ; 

int partition2(vector<int>&arr , int low , int high){
    int pivot = arr[high];
    int i = low;
    int j = high - 1;

    while (i <= j) {
        if(arr[i] < pivot) {
            i++;
        }
        else if(arr[j] > pivot) {
            j--;
        }
        else{
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Place pivot in the correct position
    swap(arr[i], arr[high]);


    return i;
}

int partition(vector<int>& arr , int low , int high){

    int pivot = arr[high] ; 

    int i = low ; 

    for(int j = low ; j< high ; j++){
        if(arr[j] <= pivot){
            swap(arr[j] , arr[i]) ; 
            i++ ; 
        }
    }

    swap(arr[i] , arr[high]) ; 

    return i ; 

}



void quickSort(vector<int>& arr , int low , int high){
    if(low < high){
        int pi = partition2(arr , low , high) ; 

        quickSort(arr , low , pi-1) ;
        quickSort(arr , pi+1 , high) ;  

    }
}

int main(){
    vector<int> arr = {4,5,4,5,4,5,6,7,6};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}