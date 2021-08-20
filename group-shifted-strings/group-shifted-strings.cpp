class Solution {
public:
    bool isSameGroup(string &a,string &b){
        if (a.size() != b.size()){
            return false;
        }
        set<int> set;
        
        
        for(int i = 0; i < a.size(); i++){
            if (set.size() > 1){
                return false;
            }
            if (a[i] - b[i] < 0){
                set.insert(a[i] - b[i] + 26);
            }else {
                set.insert(a[i] - b[i]);
            }
        }
        return set.size() == 1;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> groups;
        
        int n = strings.size();
        
        vector<bool> used(n);
        
        for(int i = 0; i < n; i++){
            if (used[i]){
                continue;
            }
            vector<string> group = {strings[i]};
            for(int j = i + 1; j < n; j++){
                if (!used[j] && isSameGroup(strings[i],strings[j])){
                    group.push_back(strings[j]);
                    used[j] = true;
                }
            }
            groups.push_back(group);
        }
        return groups;
    }
};


