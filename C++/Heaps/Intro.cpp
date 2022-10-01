#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                    return;
            }
        }

        void print(){
            for(int i = 1; i <= size; i++){
                cout<<arr[i] << " ";
            }
            cout<<endl;
        }

        void Delete(){
            if (size == 0){
                cout<<"Nothing to delete"<<endl;
                return;
            }
            // step1: put last element into first Index
            arr[1] == arr[size];
            // step2: remove last element
            size--;

            // step3: Take root node to its correct position
            int i = 1;
            while(i < size){
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;
                
                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if ( rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else
                    return;
            }

        }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;

    while(size > 1){
        // step1: swap
        swap(arr[size], arr[1]);
        // step2
        size--;

        // step3
        heapify(arr, size, 1);

    }
}

int main(){
    
    heap h;
    h.insert(40);
    h.insert(35);
    h.insert(30);
    h.insert(25);
    h.insert(20);
    h.insert(10);
    h.print();
    h.insert(37);
    h.print();
    cout<<endl;

    cout<<"Using priority_queue"<<endl;

    // Max_Heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element at top -> "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top -> "<<pq.top()<<endl;
    cout<<"Size of queue is -> "<<pq.size()<<endl;
    if(pq.empty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;

    
    // Min_Heap
    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"Element at top -> "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top -> "<<minheap.top()<<endl;
    cout<<"Size of queue is -> "<<minheap.size()<<endl;
    return 0;
}