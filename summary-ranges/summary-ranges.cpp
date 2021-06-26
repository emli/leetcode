class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int left = -1;
        int right = -1;
        for(int i = 0; i < nums.size(); i++){
            if (left == -1){
                left = nums[i];
            }
            
            if (i == int(nums.size()) - 1 || long(nums[i + 1]) - long(nums[i]) > 1){
                right = nums[i];
                if (left == right){
                    ans.push_back(to_string(left));
                }else {
                    ans.push_back(to_string(left) + "->" + to_string(right));
                }
                left = right = -1;
            }
        }
        
        return ans;
    }
};