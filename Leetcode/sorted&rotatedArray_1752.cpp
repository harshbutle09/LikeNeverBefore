#include<bits/stdc++.h>
class Solution {
public:
// ===============================================
//              BRUTE FORCE
// ===============================================
// bohot he ghatiya approach hai ye
// this is brutal brute force

// Time complexity = O(n^2)
// Space complexity = O(n)
// bool isOkay(vector<int>& temp){
//     for(int i = 0 ; i < temp.size() - 1 ; i ++){
//         if(temp[i] > temp[i + 1])return false;
//     }
//     return true;
// }
//     bool check(vector<int>& nums) {
//         for(int i = 0 ; i < nums.size() ; i ++){
//             vector<int> temp(nums.size() , 0);
//             for(int j = 0 ; j < nums.size() ; j ++){
//                 int index = (j + i) % nums.size();
//                 temp[index] = nums[j];
//             }
//             if(isOkay(temp)){
//                 return true;
//             }
//         }
//         return false;
//     }

// =====================================================
//                  (MY TRY): OPTIMAL SOLUTION
// =====================================================
    // bool check(vector<int>& nums) {
    //     int miniIndex = 0;
    //     for(int i = 0 ; i < nums.size() ; i ++){
    //         if(nums[i] <= nums[miniIndex]){
    //             miniIndex = i;
    //         }
    //     }
    //     if(miniIndex == 0) return true;
    //     int leftMiniIndex = 0;
    //     int rightMaxiIndex = nums.size() - 1;
    //     for(int i = 0 ; i < miniIndex - 1 ; i ++){
    //         if(nums[i] > nums[i + 1] && nums[i + 1] != nums[miniIndex]) return false;

    //     }
    //     for(int i = miniIndex ; i < nums.size() - 1 ; i ++){
    //         if(nums[i] > nums[i + 1] && nums[i + 1] != nums[miniIndex]) return false;
    //     }
    //     if(nums[leftMiniIndex] < nums[rightMaxiIndex]) return false;
    //     return true;
    // }




// ================================================
//              ACTUAL SOLUTION
// ================================================

bool check(vector<int>& nums) {
        // Logic : for any sorted array, which is rotated, there will exist only one Breaking point
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            if(nums[i] > nums[(i + 1) % nums.size()]){
                count ++;
            }
        }
        if(count > 1) return false;

        return true;
    }
};