class Solution {
    public:
    
    void helper(vector<vector<int>>& maze , int x , int y , vector<vector<bool>>& visited , vector<string>& ans , string& s){
      //   if(visited[x][y] == 1){
      //       return;
      //   }
        if(x == maze.size() - 1 && y == maze.size() - 1){
            // goal has been reached
            ans.push_back(s);
          //   cout <<"This is current value of string: " << s <<"\n";
            return;
        }
        // check down
        if(x != maze.size() - 1 && maze[x + 1][y] != 0 && visited[x + 1][y] == 0){
            s += 'D';
        visited[x][y] = 1;
        helper(maze , x + 1 , y , visited , ans , s);
        s.pop_back();
        visited[x][y] = 0;
        }
        // check left
        if(y != 0 && maze[x][y - 1] != 0 && visited[x][y - 1] == 0){
          s += 'L';
        visited[x][y] = 1;
        helper(maze , x , y - 1 , visited , ans , s);
        s.pop_back();
        visited[x][y] = 0;
        }
        // check right
        if(y != maze.size() - 1 && maze[x][y + 1] != 0 && visited[x][y + 1] == 0){
            s += 'R';
        visited[x][y] = 1;
        helper(maze , x , y + 1 , visited , ans , s);
        s.pop_back();
        visited[x][y] = 0;
        }
        // check up
        if(x != 0 && maze[x - 1][y] != 0 && visited[x - 1][y] == 0){ 
        s += 'U';
        visited[x][y] = 1;
        helper(maze , x - 1 , y , visited , ans , s);
        s.pop_back();
        visited[x][y] = 0;
        }
        
        
        
    }
      vector<string> ratInMaze(vector<vector<int>>& maze) {
          vector<vector<bool>> visited(maze.size() , vector<bool>(maze.size() , 0));
          string s = "";
          visited[0][0] = 1;
          vector<string> ans;
          for(int i = 0 ; i < maze.size() ; i ++){
              for(int j = 0 ; j < maze.size() ; j ++){
                  if(maze[i][j] == 0){
                      visited[i][j] = 1;
                  }
              }
          }
          helper(maze , 0 , 0 , visited , ans , s);
          
          return ans;
          
          
      }
  };