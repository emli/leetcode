class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<unsigned int>> pathNum(n,vector<unsigned int>(m));
        
        pathNum[0][0] = (obstacleGrid[0][0] == 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if (obstacleGrid[i][j])
                    continue;
                if (i - 1 >= 0){
                    pathNum[i][j] += pathNum[i - 1][j];
                }
                if (j - 1 >= 0){
                    pathNum[i][j] += pathNum[i][j - 1];
                }
            }
        return pathNum[n - 1][m - 1];
    }
};