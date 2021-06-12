class Solution {
public:
    string simplifyPath(string path) {
        string tmp;
        
        stringstream ss(path);
        
        vector<string> folders;
        
        while(getline(ss,tmp,'/')){
            if (tmp == "" || tmp == "."){
                continue;
            }else if (tmp == ".."){
                if(!folders.empty())
                    folders.pop_back();
            }else {
                folders.push_back(tmp);
            }
        }
        
        string ans = "";
        
        for(string folder : folders){
            ans.push_back('/');
            ans.append(folder);
        }
        return ans == "" ? "/" : ans;
    }
};