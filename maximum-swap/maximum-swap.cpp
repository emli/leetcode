class Solution {
public:
    int maximumSwap(int n) {
       string s = to_string(n);

    int first_index = -1;
    int second_index = -1;
    int can_swap;

   
    for(int i = s.size() - 1; i >= 0; i--){
        if (first_index == -1 || s[i] > s[first_index]){
            first_index = i;
            continue;
        }

        if (s[i] < s[first_index]){
            second_index = i;
            can_swap = first_index;
        }
    }
    
    if (second_index == -1){
        return n;
    }
 
    swap(s[second_index],s[can_swap]);
    return stoi(s);
}
};