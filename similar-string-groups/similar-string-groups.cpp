class disjoint_set{
    vector<int> v;
    int sz;
    public:
        disjoint_set(int n){
           make_set(n); 
           sz = n; 
        }
    
        void make_set(int n){
            v.resize(n);
            iota(v.begin(),v.end(),0);
        }
        int find(int i){
            if (i != v[i]){
                v[i] = find(v[i]);
            }
            return v[i];
        }
        void join(int i,int j){
            int x = find(i);
            int y = find(j);
            
            if (x != y){
                v[x] = y;
                sz--;
            }
        }
        int size(){
            return sz;
        }
};

class Solution {
    bool isSimilar(string &a, string &b){
        int c = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i] && ++c > 2){
                return false;
            }
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        disjoint_set ds(n);
        
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                  if(isSimilar(strs[i], strs[j])){
                        ds.join(i,j);
                  } 
            }   
        }
        
        return ds.size();
    }
};

