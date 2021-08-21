class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> curMaxHeights(n);
        
        int curMax = -1;
        for(int i = n - 1; i >= 0; i--){
            if (curMax == -1 || heights[i] > curMax){
                curMax = heights[i];
            }
            curMaxHeights[i] = curMax;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if (i == n - 1 || heights[i] > curMaxHeights[i + 1]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};