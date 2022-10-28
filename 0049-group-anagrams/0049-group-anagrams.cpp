class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        unordered_map<string, pair<int, int>> freqIdxMap;
        int countOfVectors = 0;
        
        for(int i=0; i < strs.size(); i++){
            string word = strs[i];
            string sortedword = strs[i];
            sort(sortedword.begin(), sortedword.end());
            
            if(freqIdxMap[sortedword].first != 0){
                //this word has an anagram in result vector.
                
                int idx = freqIdxMap[sortedword].second;
                result[idx].push_back(word);
                (freqIdxMap[sortedword].first)++;
            }else{
                // this is a new word
                vector<string> newVector;
                newVector.push_back(word);
                result.push_back(newVector);
                
                (freqIdxMap[sortedword].first)++;
                countOfVectors++;
                freqIdxMap[sortedword].second = countOfVectors-1;
            }
        }
        
        return result;
        
    }
};