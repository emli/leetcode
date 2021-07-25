
class Solution {
public:
    bool go(int pos,int k,vector<int>& stones,vector<vector<int>> &dp){
    int &memo = dp[pos][k];

    if (memo != -1){
        return memo;
    }
    if (pos >= stones.size() - 1){
        return memo = true;
    }
    bool ok = false;
    for(int i = -1; i <= 1; i++){
        int sum = stones[pos] + (k + i);

        for(int j = pos + 1; j < stones.size(); j++){
            if (stones[j] == sum){
                ok |= go(j,k + i,stones,dp);
            }
        }
    }

    return memo = ok;

}
    bool canCross(vector<int>& stones) {
        int n = stones.size();
    vector<vector<int>> dp(n + 1,vector<int>(n + 100, -1));
    if (stones[0] + 1 == stones[1]){
        return go(1,1,stones,dp);
    }
    return false;
    }
};