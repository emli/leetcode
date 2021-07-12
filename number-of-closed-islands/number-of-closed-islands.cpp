const int dx[] = {1,-1,0,0};
const int dy[] = {0, 0,1,-1};

class Solution {
public:   
    bool dfs(int x,int y,vector<vector<int>> &matrix,vector<vector<bool>> &used){
        used[x][y] = true;

        int n = matrix.size();
        int m = matrix[0].size();

        bool result = true;

        for(int i = 0; i < 4; i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m){
                result = false;
            }else {
                if (!used[x1][y1] && matrix[x1][y1] == 0){
                    result &= dfs(x1,y1,matrix,used);
                }
            }
        }
        return result;
    }
    int closedIsland(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<bool>> used(n,vector<bool>(m));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (matrix[i][j] == 0 && !used[i][j]){
                    ans += dfs(i,j,matrix,used);
                }
            }
        }
        return ans;
    }
};