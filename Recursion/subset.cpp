#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    void helper(vector<int>& nums ,vector<int>& container ,int index , vector<vector<int>>& ans){
    
        // base condition
        if(index == nums.size()){
            ans.push_back(container);
            return;
        }
        // code
        container.push_back(nums[index]);
        helper(nums , container , index + 1 , ans);
        container.pop_back();
        helper(nums , container , index + 1 , ans);
    }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>ans;
            int index = 0;
            vector<int>container;
            helper(nums , container , index , ans);
    
            return ans;
        }
    };