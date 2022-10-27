class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // if(s == " ") return 1;
        
        unordered_set<char> currElements;
        
        int end = 0, start = 0, maxLen = 0, currLen = 0;
        
        for(int i=0; i<s.length(); i++){
            
            if(currElements.find(s[i]) != currElements.end()){
                
                maxLen = max(maxLen, currLen);
                // element is already present
                while(s[start] != s[i]){
                    auto it = currElements.find(s[start]);
                    currElements.erase(it);
                    currLen--;
                    start++;
                }
                
                start++;
                end = i;
                
            }else{
                currElements.insert(s[i]);
                end = i;
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            
        }
        
        return maxLen;
        
    }
};