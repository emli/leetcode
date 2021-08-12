vector<vector<int>> directions = {
    {1, 0},
    {-1,0},
    {0, 1},
    {0, -1}
};
class Solution {
public:

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& connectedComp,int x,int y,int color){
        int n = matrix.size();
        int m = matrix[0].size();

        connectedComp[x][y] = color;

        matrix[x][y] = -1;

        int result = 0;
        for(vector<int> direction : directions){
            int x1 = x + direction[0];
            int y1 = y + direction[1];

            if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && (matrix[x1][y1] == 1)){
                result = result + (dfs(matrix,connectedComp,x1,y1,color) + 1);
            }
        }
        return result;
    }
    int largestIsland(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> connectedComp(n, vector<int>(m));  

        int color = 1;

        unordered_map<int,int> size_of_comp;
        int best = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (matrix[i][j] == 1) {
                    int size = dfs(matrix,connectedComp,i,j, color) + 1;
                    size_of_comp[color] = size;
                    color++;
                    best = max(best,size);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                     set<int> set; 
                     for(vector<int> direction : directions){
                        int x1 = i + direction[0];
                        int y1 = j + direction[1];

                        if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m){
                            set.insert(connectedComp[x1][y1]);    
                        }
                    }

                    int size = 1;
                    for (auto color : set){
                        size += size_of_comp[color];
                    }

                    best = max(best,size);
                }
            }
        }
        return best;
        
    }
};