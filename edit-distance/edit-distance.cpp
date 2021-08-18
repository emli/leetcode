class Solution {
public:
    int minMoves(int i,int j,string &a,string &b,vector<vector<int>> &min_moves){
        int &memo = min_moves[i][j];
        if (memo != -1){
            return memo;
        }
        if (i == a.size() && j == b.size()){
            return memo = 0;
        }
        
        if (i == a.size() || j == b.size()){
            if (i == a.size()) return memo = abs(int(b.size()) - j);
            if (j == b.size()) return memo = abs(int(a.size()) - i);
        }
        int ans = 0;
        if (a[i] == b[j]){
            ans += minMoves(i + 1,j + 1,a,b,min_moves);
        }else if(a[i] != b[j]){
            ans += min({minMoves(i + 1,j,a,b,min_moves) , minMoves(i,j + 1,a,b,min_moves) , minMoves(i + 1,j + 1,a,b,min_moves) }) + 1; 
        }
        return memo = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> min_moves(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return minMoves(0,0,word1,word2,min_moves);
    }
};