class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> queue;
        unordered_map<string,int> distance;


        for(string word : wordList){
            distance[word] = INT_MAX;
        }
        
        distance[beginWord] = 1;

        queue.push(beginWord);
        
        unordered_set<string> dict(wordList.begin(),wordList.end());
        

        while(!queue.empty()){
            string front = queue.front(); queue.pop();

            for(int i = 0; i < front.size(); i++){
                for(char x = 'a'; x <= 'z'; x++){
                    string tmp = front;
                    tmp[i] = x; 
                    if (distance[front] + 1 < distance[tmp] ){
                        distance[tmp] = distance[front] + 1;
                        queue.push(tmp);
                    }
                }
            }    
        }

        if (distance[endWord] != INT_MAX){
            return distance[endWord];
        }
        return 0;
    }
};