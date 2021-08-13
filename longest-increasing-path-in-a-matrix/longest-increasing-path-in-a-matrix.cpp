class Solution {
public:
    int n,m;
    vector<vector<int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    int dfs(int x,int y, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int &memo = dp[x][y];

        if (memo != -1){
            return memo;
        }
        int best = 0;
        for(vector<int> &direction : directions){
            int x1 = x + direction[0];
            int y1 = y + direction[1];

            if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && matrix[x][y] < matrix[x1][y1]){
                best = max(best,dfs(x1,y1,matrix,dp) + 1);
            }
        }
        return memo = best;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix[0].size();

    vector<vector<int>> dp(n + 1,vector<int>(m + 1, -1));

    int best = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            best = max(best, dfs(i,j,matrix,dp) + 1);
        }
    }
    return best;
    }
};