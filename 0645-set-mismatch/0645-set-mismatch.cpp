class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
//         unordered_map<int, int> freqMap;
//         vector<int> ans(2);
        
//         for(int i=0; i<nums.size(); i++){
            
//             freqMap[nums[i]]++;
            
//         }
        
//         for(int i=1; i<=nums.size(); i++){
//             if(freqMap[i] > 1) ans[0] = i;
//             if(freqMap[i] == 0) ans[1] = i;
//         }
        
//         return ans;
        
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        
        int duplicate = -2, missing = 1;
        
        for(int i=0; i<nums.size(); i++){
            int idxForCurrentNo = abs(nums[i])-1;
            // make number at this idx -ve to mark that this idx is reserved for a number.
            cout << idxForCurrentNo << " ";
            if(nums[idxForCurrentNo] < 0) duplicate = abs(nums[i]);            
            else nums[idxForCurrentNo]*=(-1);
        }
        
        for(int i=0; i<nums.size(); i++){
            // there will be a number in the array that wont be changed to -ve cause number corresponding to that idx is missing, thus the idx is not reserved and hence it is not marked as -ve.
            if(nums[i] > 0){
                missing = i+1;
                break;
            }
        }
        
        vector<int> result;
        result.push_back(duplicate);
        result.push_back(missing);
        
        return result;
        
        // Time Complexity: O(N)
        // Space Complexity: O(1)
    }
};