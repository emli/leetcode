vector<vector<int>> directions = {
    {1, 0},
    {-1,0},
    {0,1},
    {0,-1}
};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> distance(n,vector<int>(m));
        vector<vector<int>> reach(n,vector<int>(m));


        vector<pair<int,int>> starting_points;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if (matrix[i][j] == 1){
                    starting_points.push_back({i,j});
                }else if (matrix[i][j] == 1){
                    distance[i][j] = INT_MAX;
                }
        }


        for(pair<int,int> &starting_point : starting_points){
            queue<pair<int,int>> queue;
            queue.push(starting_point);
            set<pair<int,int>> used;
            vector<vector<int>> distance_tmp(n,vector<int>(m));
            distance_tmp[starting_point.first][starting_point.second] = 0;
            used.insert(starting_point);

            while(!queue.empty()){
                pair<int,int> front = queue.front(); queue.pop();
                reach[front.first][front.second]++;

                for(vector<int> direction : directions){
                    int x1 = front.first  + direction[0];
                    int y1 = front.second + direction[1];

                    if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && matrix[x1][y1] == 0 && used.count({x1,y1}) == 0){
                        queue.push({x1,y1});
                        distance_tmp[x1][y1] = distance_tmp[front.first][front.second] + 1;
                        distance[x1][y1] += distance_tmp[x1][y1];
                        used.insert({x1,y1});
                    }
                }
            }
        }

        int best = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if (reach[i][j] == starting_points.size() && matrix[i][j] == 0){
                    best = min(best,distance[i][j]);
                }
        }
        if (best == INT_MAX){
            return -1;
        }

        return best;
    }
};