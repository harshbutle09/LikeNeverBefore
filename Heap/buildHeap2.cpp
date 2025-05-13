#include<iostream>
using namespace std;

class Heap{
    public:
    int size;
    int currentSize;
    int * arr;
    Heap(int n){
        arr = new int [n];
        this -> size = n;
        this -> currentSize = 0;
    }

    void print(){
        for(int i = 0 ; i < size ; i ++){
            cout << arr[i] << " ";
        }cout << endl;
    }
    
    void buildHeapNlogN(int index){ // we'll use step up method; i.e we'll check the value of the node with it's
        // parent node
        while(index > 0){
            int parent = (index - 1) / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
                buildHeapNlogN(index);
            }
            break;
        }

    }

    void buildHeapN(int index){ // we'll use step down method here; i.e we'll check the value of the node with it's 
        // children node
        for(int i = index ; i >= 0 ; i --){
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if(left < size && arr[left] > arr[largest]){
                largest = left;
            }
            if(right < size && arr[right] > arr[largest]){
                largest = right;
            }

            if(largest != index){
                swap(arr[largest] , arr[index]);
                buildHeapN(largest);
            }
        }
    }

};
int main(){
    int arr[] = {14 , 15 , 12 , 22 , 17 , 20 , 18 , 24 , 23 , 30 , 19};
    Heap h(11);
    h.arr = arr;
    cout << "Array before heap is built: ";
    h.print();
    cout << "Array after heap is built(Step Up -> O(NlogN)): ";
    for(int i = 0 ; i < 11 ; i ++){
        h.buildHeapNlogN(i);
    }
    h.print();
    h.arr = arr;
    cout << "Array after heap is built(Step Down -> O(N)): ";
    h.buildHeapN(4);
    h.print();


    return 0;
}