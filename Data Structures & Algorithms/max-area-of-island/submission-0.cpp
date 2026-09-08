class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i, int j){
        //checking for boundary
        int n=grid.size();
        int m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]==0){
            return 0;
        }
        //mark that node visited
        grid[i][j]=0;
        // make area
        int area=1;
        area += dfs(grid,i+1,j);
        area += dfs(grid,i-1,j);
        area += dfs(grid,i,j+1);
        area += dfs(grid,i,j-1);
        //return area
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();

      int ans = 0;

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]==1){
            int area=dfs(grid,i,j);
            ans=max(ans,area);
           } 
        }
      }  
      return ans;
        
    }
};
