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
                    // odd number of occurences for "aa", "bb"..etc type elements
                    mid = 2;
                    result2 += (x.second-1)*2;
                 }else{
                    // even number of occurences for "aa", "bb"..etc type elements
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
        
        // result1 is for pairs like "lc"/"cl", "ab"/"ba" which will be counted twice cause 1st time for "lc" and next when we have "cl" thus we need to divide the result by 2.
        
        // This wont happen in case of result2 (for elements like "aa", "bb", etc)
        result1 /= 2;
        return result1 + result2 + mid;
        
        // TIME COMPLEXITY: O(N)
        
    }
};