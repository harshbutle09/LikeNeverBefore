#include<iostream>
using namespace std;

class MaxHeap{
    int size;
    int currentSize;
    int * arr;
    public:
    MaxHeap(int n){
        this -> size = n;
        this -> currentSize = 0;
        arr = new int [n];
    }
    ~MaxHeap(){
        delete [] arr;
    }

    void insert(int n){
        if(currentSize == size){
            cout << "Heap Overflow\n";
            return;
        }
        int index = currentSize;
        arr[index] = n;
        currentSize ++;
        while(index > 0){
            int parent = (index - 1) / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }else{
                break;
            }
        }
    }
    void heapify(int index){
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if(left < currentSize && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < currentSize && arr[right] > arr[largest]){
            largest = right;
        }

        if(index != largest){
            swap(arr[index] , arr[largest]);
            heapify(largest);
        }
    }
    void remove(){
        if(currentSize == 0){
            cout << "Heap underflow\n";
            return;
        }
        cout << arr[0] << " removed from the heap\n";
        arr[0] = arr[currentSize - 1];
        currentSize --;
        if(currentSize == 0){
            return;
        }else{
            heapify(0);
        }
    }

    void print(){
        if(currentSize == 0){
            cout << "Heap is empty\n";
            return;
        }
        for(int i = 0 ; i < currentSize ; i ++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main(){
    MaxHeap h(6);
    h.insert(6);
    h.print();
    h.insert(16);
    h.print();
    h.insert(36);
    h.print();
    h.insert(0);
    h.print();
    h.insert(76);
    h.print();
    h.insert(21);
    h.print();
    h.insert(100);
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();

    return 0;
}