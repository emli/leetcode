class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalSum = accumulate(chalk.begin(),chalk.end(),0LL);
        
        k %= totalSum;
        if (k == 0){
            return 0;
        }
        
        for(int i = 0; i < chalk.size(); i++){
            if (k - chalk[i] < 0){
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }
};