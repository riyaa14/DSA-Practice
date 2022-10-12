class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        // int largestSide = nums[0], side1 = nums[1], side2 = nums[2];
        
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