class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map<int, int> freqMap;
        vector<int> ans(2);
        
        for(int i=0; i<nums.size(); i++){
            
            freqMap[nums[i]]++;
            
        }
        
        for(int i=1; i<=nums.size(); i++){
            if(freqMap[i] > 1) ans[0] = i;
            if(freqMap[i] == 0) ans[1] = i;
        }
        
        return ans;
    }
};