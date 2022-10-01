//  1. BUBBLE SORT  //
// #include<iostream>
// using namespace std;

// void Bubble_Sort(int arr[], int size){
//     int i, j;
//     for (i = 0; i < (size-1); i++){
//         for (j = i; j < size; j++){
//             if (arr[i] > arr[j])
//                 swap(arr[i], arr[j]);
//         }
//     }
// }

// int main(){
//     int arr1[8] = {14, 5, 8, 10, 13, 1, 18, 3};
//     Bubble_Sort(arr1, 8);
//     for (int ind = 0; ind < 8; ind++){
//         cout<<arr1[ind]<<" ";
//     }    
//     return 0;
// }


//  2. MERGE SORT  //

// #include<iostream>
// using namespace std;

// void printArray(int arr[], int arrSize){
//     int i;

//     for (i = 0; i < arrSize; i++){
//         cout<<arr[i]<<' ';
//     }
//     cout<<endl;
// }

// void merge(int arr[], int lowLeft, int highLeft, int highRight){
//     int lowRight, size, iArr, i;
//     int *mergedArr;
//     int iRight, iLeft, iRes;

//     lowRight = highLeft + 1;
//     size = highRight - lowLeft + 1;
//     mergedArr = new int[size];

//     iLeft = lowLeft;
//     iRight = lowRight;
//     iRes = 0;
    
//     while(iLeft <= highLeft && iRight <= highRight){
//         if (arr[iLeft] < arr[iRight]){
//             mergedArr[iRes] = arr[iLeft];
//             iLeft++;
//             iRes++;
//         }
//         else{
//             mergedArr[iRes] = arr[iRight];
//             iRight++;
//             iRes++;
//         }
//     }

//     while(iLeft <= highLeft){
//         mergedArr[iRes] = arr[iLeft];
//         iLeft++;
//         iRes++;
//     }

//     while(iRight <= highRight){
//         mergedArr[iRes] = arr[iRight];
//         iRight++;
//         iRes; 
//     }

//     for (i = 0, iArr = lowLeft; i < size; i++, iArr++)
//         arr[iArr] = mergedArr[i];

//     delete []mergedArr;
// }

// void mergeSort(int arr[], int low, int high){
//     int midInd;

//     if (low == high)
//         return;
//     else{
//         midInd = (low + high)/2;
//         mergeSort(arr, low, midInd);
//         mergeSort(arr, midInd+1, high);
//         merge(arr, low, midInd, high);
//     }
// }

// int main(){
//     int arr2[8] = {14, 5, 8, 10, 13, 1, 18, 3};
//     int arrSize = 8;

//     mergeSort(arr2, 0, arrSize - 1);
//     printArray(arr2, arrSize);
//     return 0;
// }


//  3. SELECTION SORT  //
#include<iostream>
using namespace std;

int findIndexOfMin(int arr[], int low, int high){
    int min, minInd;
    int i;

    min = arr[low];
    minInd = low;
    for (i = low+1; i <= high; i++){
        if (arr[i] < min){
            min = arr[i];
            minInd = i;
        }
    }
    return minInd;
}

void selectionSort(int arr[], int arrSize){
    int i, minInd;

    for (i = 0; i < arrSize; i++){
        minInd = findIndexOfMin(arr, i, arrSize-1);
        swap(arr[i],arr[minInd]);
    }
}

int main(){
    int arr1[8] = {14, 5, 8, 10, 13, 1, 18, 3};
    selectionSort(arr1, 8);
    for (int ind = 0; ind < 8; ind++){
        cout<<arr1[ind]<<" ";
    }   
    return 0;
}