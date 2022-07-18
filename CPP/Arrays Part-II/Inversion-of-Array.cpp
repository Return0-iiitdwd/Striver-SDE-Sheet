//Link: - https://www.codingninjas.com/codestudio/problems/count-inversions_615

#include<iostream>
using namespace std;

//Approach - 1 (Brute Force) Time: - O(n^2) Space: - O(1)
long long getInversions(long long *arr, int n){
    long long ans = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                ans++;
            }
        }
    }
    return ans;
}

//Approach - 2 (Divide and Conquer: - Improvised mergeSort) Time: - O(nlogn) Space: - O(n)
long long merge(long long *arr, int low, int mid, int high){
    int *sortedArray = new int[high - low + 1];
    int i = low, j = mid + 1, k = 0, count = 0;
    while (i <= mid && j <= high){
        if (arr[i] <= arr[j]){
            sortedArray[k++] = arr[i++];
        }
        else{
            count += mid - i + 1;
            sortedArray[k++] = arr[j++];
        }
    }
    while (i <= mid){
        sortedArray[k++] = arr[i++];
    }
    while (j <= high){
        sortedArray[k++] = arr[j++];
    }
    
    for (int q = 0; q < k; q++){
        arr[low + q] = sortedArray[q];
    }
    
    return count;
}

long long mergeSort(long long *arr, int low, int high){
    if (low >= high){
        return 0;
    }
    int mid = low + (high - low) / 2;
    long long count = mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count+= merge(arr, low, mid, high);
    
    return count;
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n - 1);
}

