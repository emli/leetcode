int mod = 1e9 + 7;
class Solution {
public:
       int go(string s,int pos,vector<int>& dp,unordered_map<string,int> &cache){
        int &memo = dp[pos];
        
        if (memo != -1){
            return memo;
        }
        if (pos >= s.size()){
            return memo = 1;
        }
        string partOne(1, s[pos]);
        int sum = 0;
        if (partOne == "*"){
            sum += 9 * go(s,pos + 1,dp,cache);
        }else if (isdigit(partOne[0]) && partOne > "0"){
            sum += go(s,pos + 1,dp,cache);
        }
        
        if (pos + 1 <  s.size()){
            string partTwo = partOne;
            partTwo.push_back(s[pos + 1]);
            
            if(partTwo == "**"){
                int x = 0;
                for(int i = 11; i <= 26; i++){
                    if(i ==  20) continue;
                    sum += go(s,pos + 2,dp,cache);
                    x++;
                }
                cache[partTwo] = x;
            }else if (partTwo[0] == '*'){
                int x = 0;

                    for(char d = '1'; d <= '9'; d++){
                        string tmp = partTwo;
                        tmp[0] = d;
                        if (stoi(tmp) >= 10 && stoi(tmp) <= 26) {  
                            sum += go(s,pos + 2,dp,cache);
                            x++;
                        }
                    }
                
                cache[partTwo] = x; 
                
            }else if (partTwo[1] == '*'){
                int x = 0;
                for(char d = '1'; d <= '9'; d++){
                    string tmp = partTwo;
                    tmp[1] = d;
                    if (stoi(tmp) >= 10 && stoi(tmp) <= 26) {
                        sum += go(s,pos + 2,dp,cache);
                        x++;
                    }
                }
                cache[partTwo] = x;   
                
            }else {
                int x = 0;
                if (stoi(partTwo) >= 10 && stoi(partTwo) <= 26) {
                    sum += go(s,pos + 2,dp,cache);
                    x++;
                }
                cache[partTwo] = x;   

            }
        }
        
        return sum;
        
    }
    int go_cache(string &s,int pos,vector<int>& dp,unordered_map<string,int> &cache){
        int &memo = dp[pos];
        
        if (memo != -1){
            return memo;
        }
        if (pos == s.size()){
            return memo = 1;
        }
        
        string partOne(1, s[pos]);
        
        int sum = 0;
        if (partOne == "*"){
            sum += 9LL * go_cache(s,pos + 1,dp,cache) % mod;
        }else if (isdigit(partOne[0]) && partOne > "0"){
            sum += go_cache(s,pos + 1,dp,cache) % mod;
        }
        
        if (pos + 1 <  s.size()){
            string partTwo = partOne;
            partTwo.push_back(s[pos + 1]);
            sum += cache[partTwo] * 1LL * go_cache(s,pos + 2,dp,cache) % mod;
        }
        
        return memo = sum % mod;
        
    }
    int numDecodings(string s) {
        unordered_map<string,int> cache;
        vector<int> dp(s.size() + 100, -1);

        vector<char> digits = {'*'};
        for(char d = '0'; d <= '9'; d++){
            digits.push_back(d);
        }
        
        for(char x : digits){
            for(char y : digits){
                string ss;
                ss.push_back(x);
                ss.push_back(y);
               if(s[0] == '0') continue;
                go(ss,0,dp,cache);
            }
        }
        vector<int> dp1(s.size() + 100, -1);
        return go_cache(s,0,dp1,cache);  
    }
};