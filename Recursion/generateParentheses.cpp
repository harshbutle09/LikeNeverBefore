#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void helper(vector<string>& ans , string& s , int n , int lc , int rc){
      /*
      logic : rc < lc
      when rc + lc == 2*n return
      */

      // base condition
      if(lc + rc == 2 * n){
          ans.push_back(s);
          return ;
      }
      // code
      if(lc < n){
          s.push_back('(');
          lc += 1;
          helper(ans , s , n , lc , rc);
          s.pop_back();
          lc -= 1;
      }
      
      if(rc < lc){
          s.push_back(')');
          rc += 1;
          helper(ans , s , n , lc , rc);
          s.pop_back();
          rc -= 1;
      }
      
  }
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        string s = "";
        helper(ans , s , n / 2 , 0 , 0);
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.generateParentheses(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
