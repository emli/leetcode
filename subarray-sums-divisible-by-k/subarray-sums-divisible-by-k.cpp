class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        
        int curSum = 0;
        prefixSum[0] = 1;
        
        int ans = 0;
        for(int num : nums){
            curSum = (curSum + num) % k;
            if (curSum < 0){
                curSum += k;
            }
            ans += prefixSum[curSum];
            prefixSum[curSum]++;
        }
        
        return ans;
    }
};

