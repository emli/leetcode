class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        vector<long long> sum(1e5 + 10);
        vector<bool> used(1e5 + 10);
        for(vector<int> segment : segments){
            sum[segment[0]] += segment[2];
            sum[segment[1]] -= segment[2];
            used[segment[1] - 1] = true;
        }
        
        for(int i = 1; i <= 1e5; i++){
            sum[i] += sum[i - 1];
        }
        
        int open  = -1;
        int close = -1;
        
        vector<vector<long long>> ans;
        for(int i = 1; i <= 1e5; i++){
            if (open == -1 && sum[i] > 0){
                open = i;
            } 
            if (sum[i] > 0 && (sum[i] != sum[i + 1] || used[i])){  
                close = i;
                ans.push_back({open,i + 1, sum[i]});
                open = close = -1;
            }    
        }
        return ans;
    }
};