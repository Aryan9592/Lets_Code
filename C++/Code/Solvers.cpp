#include<iostream>
using namespace std;

void sorted_array(int arr2[], int size){
    int i, j;
    for (i = 0; i < size - 1; i++){
        for (j = i; j < size; j++){
            if (arr2[i] > arr2[j]){
                swap(arr2[i], arr2[j]);
            }
        }   
    }
}

void binary_search(int num, int arr1[], int size){
    int high, low, mid, val, Count;
    bool found = false;
    int arr3[size] = {arr1[size]};
    sorted_array(arr3, 6);
    low = 0;
    high = size - 1;
    Count = 0;
    while ((found == false) && (low <= high)){
        Count++;
        mid = (low + high)/2;
        if (arr3[mid] == num){
            found = true;
        }
        else if (num > arr3[mid])
            low = mid + 1;
        else
            high = mid;
    }
    if (found == true){
        for (val = 0; val < size; val++){
            if (arr1[val] == num)
                break;
        }
        cout<<"The number is found..It's at index "<<val<<endl;
    }
    else
        cout<<"The number is not found...Total Searches made are "<<Count<<endl;
}

int main(){
    int arr[6] = {19, 2, 20, 1, 0, 18};
    binary_search(20, arr, 6);
    return 0;
}