/*
How does Merge Sort work?
Merge sort is a popular sorting algorithm known for its efficiency and stability. It follows the divide-and-conquer approach to sort a given array of elements.

Here’s a step-by-step explanation of how merge sort works:

Divide: Divide the list or array recursively into two halves until it can no more be divided.
Conquer: Each subarray is sorted individually using the merge sort algorithm.
Merge: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.
*/








#include<bits/stdc++.h>
using namespace std ; 


void merge(vector<int>&arr , int low , int mid , int high){
    
    int left = low ; 
    int right = mid+1; 

    vector<int>temp(high-low+1) ; 
    int k = 0 ; 

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[k] = arr[left] ;
            left++ ; 
            k++;  
        }
        else{
            temp[k] = arr[right] ; 
            right++ ; 
            k++; 
        }
    }

    while(right <= high){
        temp[k] = arr[right] ;
        right++ ; 
        k++ ; 
    }

    while(left <= mid){
        temp[k] = arr[left] ;
        left++; 
        k++ ; 
    }


    for(int i = low ; i<= high ; i++){
        arr[i] = temp[i-low] ;
    }

    
}




void mergeSort(vector<int>& arr , int left , int right){
    if(left >= right){
        return ; 
    }

    int mid = left + (right-left)/2 ; 

    mergeSort(arr , left , mid) ; 
    mergeSort(arr , mid+1 , right) ; 

    merge(arr , left , mid , right) ; 
}


int main(){
    vector<int> arr = {4,5,4,5,4,5,6,7,6};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}