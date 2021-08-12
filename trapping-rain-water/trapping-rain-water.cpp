class Solution {
public:
    int trap(vector<int>& nums) {
        if (nums.empty()){
             return 0;
        }
        int n = nums.size();
        vector<int> prefixMax(n), suffixMax(n);

        prefixMax[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMax[n - 1] = nums.back();

        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }

        int ans = 0;

        for(int i = 1; i < n - 1; i++){
            if (min(prefixMax[i - 1], suffixMax[i + 1]) - nums[i] >= 0) {
                ans += min(prefixMax[i - 1], suffixMax[i + 1]) - nums[i];
            } 
        }

        return ans;
    }
};



    