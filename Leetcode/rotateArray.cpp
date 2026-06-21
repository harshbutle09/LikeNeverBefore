class Solution {
public:
void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
}
    void rotate(vector<int>& arr, int k) {
        if(arr.size() == 1) return;
        int left = 0;
        int right = arr.size() - 1;
        while(left < right){
            swap(arr[left] , arr[right]);
            left ++;
            right --;
        }
        k %= arr.size();
        left = 0;
        right = k - 1;
        while(left < right){
            swap(arr[left] , arr[right]);
            left ++;
            right --;
        }
        left = k;
        right = arr.size() - 1;
        while(left < right){
            swap(arr[left] , arr[right]);
            left ++;
            right --;
        }

        return;
    }
};