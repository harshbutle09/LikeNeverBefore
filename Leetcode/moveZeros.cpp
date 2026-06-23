#include<vector>
using namespace std;
class Solution {
public:
void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
}
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while(left < nums.size() && right < nums.size()){
            if(nums[right] == 0){
                right ++;
                continue;
            }
            if(nums[right] != 0){
                swap(nums[left] , nums[right]);
                left ++;
                right ++;
            }
        }
        return;
    }
};