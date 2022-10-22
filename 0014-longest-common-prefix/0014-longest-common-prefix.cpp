class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        
        // vertical scanning
        
       // if(strs == NULL || strs.length == 0) return "";
        
        int n = strs[0].length();
        int m = strs.size();
        string lcp = "";
        
        // i is iterating over prefixes.
        for(int i=1; i<=n; i++){
            
            string s = strs[0].substr(0, i);
            
            // j is iterating over vector strs.
            for(int j=1; j<m; j++){
                
                if(strs[j].substr(0, i) != s) return lcp; 
                
            }
            
            lcp = s;
            
        }
        
        return lcp;  
        
    }
};