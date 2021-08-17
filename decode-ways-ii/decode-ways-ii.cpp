int mod = 1e9 + 7;
class Solution {
public:
    int go(string &s,int pos,vector<int>& dp){
        int &memo = dp[pos];
        
        if (memo != -1){
            return memo;
        }
        if (pos == s.size()){
            return memo = 1;
        }
        
        string partOne(1, s[pos]);
        
        long long sum = 0;
        if (partOne == "*"){
            sum += 9L * go(s,pos + 1,dp) % mod;
        }else if (isdigit(partOne[0]) && partOne > "0"){
            sum += go(s,pos + 1,dp) % mod;
        }
        
        if (pos + 1 <  s.size()){
            string partTwo = partOne;
            partTwo.push_back(s[pos + 1]);
            
            if(partTwo == "**"){
                for(int i = 11; i <= 26; i++){
                    if(i ==  20) continue;
                    sum += go(s,pos + 2,dp) % mod;
                }
            }else if (partTwo[0] == '*'){
                for(char d = '1'; d <= '9'; d++){
                    string tmp = partTwo;
                    tmp[0] = d;
                    if (stoi(tmp) >= 10 && stoi(tmp) <= 26) 
                        sum += go(s,pos + 2,dp) % mod;
                }
                
            }else if (partTwo[1] == '*'){
                for(char d = '1'; d <= '9'; d++){
                    string tmp = partTwo;
                    tmp[1] = d;
                    if (stoi(tmp) >= 10 && stoi(tmp) <= 26) 
                        sum += go(s,pos + 2,dp) % mod;
                }
                
            }else {
                if (stoi(partTwo) >= 10 && stoi(partTwo) <= 26) 
                    sum += go(s,pos + 2,dp) % mod;
            }
        }
        
        return memo = sum % mod;
        
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return go(s,0,dp);   
    }
};