class Solution {
public:
    vector<int> intersection(vector<int> a,vector<int> b){
        if (a.empty()){
            return b;
        }
        int start = max(a[0],b[0]);
        int end   = min(a[1],b[1]);
        
        if (start <= end){
            return {min(a[0],b[0]),max(a[1],b[1])};
        }
        return {};
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> merged;

        int right = 0;
        for(int left = 0; left < n; left++){

            while(right < n && !intersection(intervals[left],intervals[right]).empty()){
                intervals[left] = intersection(intervals[left],intervals[right]);
                right++;
            }
            ans.push_back(intervals[left]);
            left = right - 1;
        }
        return ans;
        
    }
};