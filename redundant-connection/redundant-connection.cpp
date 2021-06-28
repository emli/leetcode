class Solution {
public:
    int find_parent(int x, vector<int> &parent){
        if (x == parent[x]){
            return x;
        }
        return parent[x] = find_parent(parent[x],parent);
    }
    void make_union(int from,int to,vector<int> &parent){
        int x = find_parent(from,parent);
        int y = find_parent(to,parent);
        
        parent[x] = y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        } 

        vector<int> ans;
        for(vector<int> edge : edges){
            int from = edge[0];
            int to = edge[1];
            
            cout << "from = " << from << endl;
            cout << "to = " << to << endl;
            cout << "find_parent(from,parent) = " << find_parent(from,parent) << endl;
            cout << "find_parent(to,parent) = " << find_parent(to,parent) << endl;
            
            if (find_parent(from,parent) == find_parent(to,parent)){
                ans = {from,to};
            }else {
                make_union(from,to,parent);
            }
        }
        return ans;
   
    }
};