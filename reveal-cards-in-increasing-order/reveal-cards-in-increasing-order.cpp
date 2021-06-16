class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        deque<int> indexes;
        vector<int> order;
        
        for(int i = 0; i < n; i++){
            indexes.push_back(i);
        }
        
        for(int i = 0; i < n; i++){ 
            order.push_back(indexes.front()); indexes.pop_front(); 
            if (!indexes.empty()){
                indexes.push_back(indexes.front());
                indexes.pop_front(); 
            }
        }
        
        sort(deck.begin(),deck.end());
        
        vector<int> ans(n);
        
        int pos = 0;
        for(int index : order){
            ans[index] = (deck[pos++]);
        }
        
        return ans;
    }
};
