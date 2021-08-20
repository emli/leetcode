class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pos_word = 0;
        
        string cur = "0";
        for(int i = 0; i < abbr.size(); i++){
            if (isalpha(abbr[i])){
                int num = stoi(cur);
                pos_word += num;
                cur = "0";
                if (abbr[i] == word[pos_word]){
                    pos_word++;        
                }else {
                    return false;
                }
            }else if (abbr[i] == '0' && cur == "0" ){
                return false;
            }else {
                cur.push_back(abbr[i]);
            }
        }
        int num = stoi(cur);
        pos_word += num;
        return pos_word == word.size();
    }
};