class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int j = 1, k = nums.size()-1;
        int ans = nums[0] + nums[1] + nums[nums.size()-1];
        for(int i=0; i<nums.size(); i++){
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k] == target) return target;
                
                // update ans if currSum is closer to target 
                if(abs(target-(nums[i]+nums[j]+nums[k])) < abs(target-ans)){
                // curr sum becomes prev sum
                    ans = nums[i]+nums[j]+nums[k];
                }
                // creating a new triplet
                if(nums[i]+nums[j]+nums[k] < target) j++;
                else k--;
                
            }
        }
        
        return ans;
    }
};