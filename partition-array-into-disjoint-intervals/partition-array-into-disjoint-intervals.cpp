class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int n = nums.size();
        
        vector<int> leftMax(n), rightMin(n);
        
        int cur = nums[0];
        
        for(int i = 0; i < n; i++){
            cur = max(cur, nums[i]);
            leftMax[i] = cur;
        }
        
        cur = nums.back();
        
        for(int i = n - 1; i >= 0; i--){
            cur = min(cur, nums[i]);
            rightMin[i] = cur;
        }
        

        int ans = 0;
        for(int i = 0; i < n - 1; i++)
            if (leftMax[i] <= rightMin[i + 1]){
                ans = i + 1;
                break;
            }
        return ans;
    }
};