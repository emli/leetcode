class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = -1; 
        int right = nums.size() - 1; 

        while(left + 1 != right){ 
            int m = (left + right) / 2; 
            if (nums[m] < nums[m + 1]){ 
                left = m;		
            }else {
                right = m;
            }
        }
        return  right; 
    }
};