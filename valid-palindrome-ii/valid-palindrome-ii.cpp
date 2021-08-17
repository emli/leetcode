class Solution {
public:
    bool isValid(string &s,int left,int right,int times){
        if (left >= right){
            return true;
        }
        if (s[left] == s[right]){
            return isValid(s,left + 1, right - 1,times);
        }else if (times >= 1){
            return false;
        }else {
            return isValid(s,left + 1, right,times + 1) || isValid(s,left, right - 1,times + 1);
        }
    }
    bool validPalindrome(string s) {
        return isValid(s,0,(int) s.size() - 1, 0);
    }
};