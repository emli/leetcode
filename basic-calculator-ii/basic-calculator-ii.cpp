
class Solution {
public:
    string removeAllSpaces(string &s){
        string ans;
        for(int i = 0; i < s.size(); i++){
            if (!isspace(s[i])){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
    int calculate(string s) {
      char operation = '+';
       stack<int> stack;
       int curNum = 0;
       s = removeAllSpaces(s); 
       for(int i = 0; i < s.size(); i++){
           char cur_char = s[i];
           if (isdigit(cur_char)){
               curNum = curNum * 10 + (cur_char - '0'); 
           }
           if(!isdigit(cur_char) || i == s.size() - 1){
               if (operation == '+'){
                   stack.push(curNum);
               }
               if (operation == '-'){
                   stack.push(-curNum);
               }
               if (operation == '*'){
                   int top = stack.top(); stack.pop();
                   stack.push(top * curNum);
               }
               if (operation == '/'){
                   int top = stack.top(); stack.pop();
                   stack.push(top / curNum);
               }
               operation = cur_char;
               curNum = 0;
           }
       }

       int result = 0;

       while(!stack.empty()){
           result += stack.top(); 
           stack.pop();
       }
   return result; 
    }
};
