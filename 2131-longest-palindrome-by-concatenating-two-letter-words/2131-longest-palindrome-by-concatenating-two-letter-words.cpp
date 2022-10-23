class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int midMax = INT_MIN, result1 = 0, mid = 0, result2 = 0;
        
        // create a hashmap
        unordered_map<string, int> freq;
        
        for(int i=0; i<words.size(); i++){
            freq[words[i]]++;
        }
        
        // iterate over words in map and look for pairs
        for(auto x : freq){
            
            if(x.first[0] == x.first[1]){
                if(x.second == 1 or x.second %2 != 0) {
                    mid = 2;
                    result2 += (x.second-1)*2;
                 }else{
                    result2 += (x.second)*2;
                }
            }else{
                string reverse = x.first;
                swap(reverse[0], reverse[1]);
                
                if(freq.find(reverse) != freq.end()){
                    result1 += min(freq[reverse], x.second)*4;
                }
            }
            
        }
        
        result1 /= 2;
        return result1 + result2 + mid;
        
    }
};