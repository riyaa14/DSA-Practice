class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int> ans;
        int i=0, j;
        for(int k=0; k<grid[0].size(); k++){
            i=0;
            j = k;
            while(i<grid.size()){
                
                // corner cases
                if((j==grid[0].size()-1 and grid[i][j] == 1) or (j==0 and grid[i][j] == -1)) break;
                if(grid[i][j] == 1 and grid[i][j+1] == -1 or grid[i][j] == -1 and grid[i][j-1] == 1) break;
                
                // normal case
                if(grid[i][j] == 1){
                    i++; j++;
                }else if(grid[i][j] == -1){
                    i++; j--;
                }
                
            }
            
            if(i<grid.size()) ans.push_back(-1);
            else ans.push_back(j);
            
        }
        
        return ans;
        
    }
};