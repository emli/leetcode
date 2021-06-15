class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        for(int i = left; i <= right; i++) {
            bool ok = false;
            for(vector<int> range : ranges){
                int x = range[0];
                int y = range[1];

                if (x <= i && i <= y){
                    ok = true;
                }
            }
            if (!ok){
                return false;
            }
        }
        return true;
    }
};