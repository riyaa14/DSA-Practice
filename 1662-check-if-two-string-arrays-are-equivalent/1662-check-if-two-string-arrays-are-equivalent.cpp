class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1 = "", s2 = "";
        
        for(string s: word1){
            s1.append(s);
        }
        
        for(string s: word2){
            s2.append(s);
        }
        
        return (s1 == s2);
        
    }
};