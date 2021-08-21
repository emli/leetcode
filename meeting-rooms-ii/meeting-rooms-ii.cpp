class Solution {
    enum type { open = 1, close = -1};
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
    
        vector<pair<int,int>> timeline;

        for(vector<int> interval : intervals){
            timeline.push_back({interval[0],type :: open});
            timeline.push_back({interval[1],type :: close});
        }

        sort(timeline.begin(),timeline.end());

        int cur = 0;
        int ans = 0;
        for(pair<int,int> time : timeline){
            if (time.second == type :: open){
                cur++;
            }else {
                cur--;
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};