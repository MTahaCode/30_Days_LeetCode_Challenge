class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });
        
        for (int i=0;i<intervals.size() - 1;i++)
        {
            vector<int>& curr = intervals[i];
            vector<int>& next = intervals[i+1];
            
            if (curr[1] >= next[0])
            {
                curr[0] = min(curr[0], next[0]);
                curr[1] = max(curr[1], next[1]);
                intervals.erase(intervals.begin() + i +1);
                i--;
            }
        }
        return intervals;
    }
};