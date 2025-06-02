class Solution {
    public:
      void helper(int n , int source , int destination , int help , int& count){
          count ++;
          if(n == 1){
              return;
          }
          helper(n - 1 , source , help , destination , count);
          // take the current ring to it's destination
          helper(n - 1 , help , destination , source , count);
      }
  
      int towerOfHanoi(int n, int from, int to, int aux) {
          int count = 0;
          helper(n , from , to , aux , count);
          
          
          return count;
      }
  };