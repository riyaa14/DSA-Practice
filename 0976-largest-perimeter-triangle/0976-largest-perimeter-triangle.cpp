class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        
        int i = nums.size()-3, j = nums.size()-1;
        
        while(i >= 0){
            
            if(nums[j] >= nums[i+1] + nums[i]){
                i--;
                j--;
            }else{
                return nums[j] + nums[i+1] + nums[i];
            }
        }
        
        return 0;
    }
};