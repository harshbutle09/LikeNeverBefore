class Solution {
public:

// ===========================================
//              MY ATTEMPT Using HashMap
// ===========================================

    int removeDuplicates(vector<int>& nums) {
        unordered_map<int , int> numbers;
        for(int i = 0 ; i < nums.size() ; i ++){
            int num = nums[i];
            if(numbers.find(num) != numbers.end()){
                continue;
            }
            numbers[nums[i]] = 1;
        }
        int k = numbers.size();
        int i = 0;
        for(auto &pair : numbers){
            nums[i] = pair.first;
            i ++;
        }
        while(i < nums.size()){
            nums[i] = 101;
            i ++;
        }
        sort(nums.begin() , nums.end());


        return k;
    }





// ================================================
//                      OPTIMAL SOLUTION
// ================================================


int removeDuplicates(vector<int>& nums) {
    int currentElement = nums[0];
    vector<int> temp;
    temp.push_back(currentElement);
    int k = 1;
       for(int i = 1 ; i < nums.size() ; i ++){
        if(nums[i] == currentElement){
            nums[i] = 101;
        }else{
            currentElement = nums[i];
            temp.push_back(currentElement);
            k ++;
        }
        
       }
       for(int i = 0 ; i < k ; i ++){
        nums[i] = temp[i];
       }

       return k;
    }
};