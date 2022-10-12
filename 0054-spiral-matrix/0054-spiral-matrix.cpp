class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> spiral;
        
        // sr = start row, er = end row , sc = start column, ec = end column
        
        int sr = 0, sc = 0, er = matrix.size()-1, ec = matrix[0].size()-1;
        
        while(sr<=er and sc<=ec){
            
            for(int j=sc; j<=ec; j++){
               spiral.push_back(matrix[sr][j]);
            }
            
            sr++;
            
            for(int i=sr; i<=er; i++){
                spiral.push_back(matrix[i][ec]);
            }
            
            ec--;
            
            if(sr<=er){
                for(int j=ec; j>=sc; j--){
                spiral.push_back(matrix[er][j]);
                }
                
                    er--;
            }
            
        
            
            if(sc<=ec){
                for(int i=er; i>=sr; i--){
                spiral.push_back(matrix[i][sc]);
                }
                
                   sc++;
            }
            
            
        }
        
        return spiral;
        
    }
    
};