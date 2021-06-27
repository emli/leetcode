class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> positive(n), negative(n);
        
        positive[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            positive[i] = max(positive[i - 1], negative[i - 1] + nums[i]);
            negative[i] = max(negative[i - 1], positive[i - 1] - nums[i]);
        }
        
        return positive[n - 1];
    }
};


