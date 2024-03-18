#include<iostream>
#include<chrono>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
void mergeSort(int arr[],int low,int high)
{
    if(low>=high)
        return;
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
}
int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=rand()%10;
    }
    cout<<"Random numbers before sorting:";
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    auto start=chrono::high_resolution_clock::now();
    mergeSort(arr,0,9);
    auto end=chrono::high_resolution_clock::now();
    cout<<"Random numbers after sorting:";
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    auto duration=chrono::duration_cast<chrono::nanoseconds>(end-start);
    cout<<"Runtime: "<<duration.count()<<"nanoseconds<<endl";
}