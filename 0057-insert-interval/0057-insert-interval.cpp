class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> FinalIntervals;

        vector<int> temp = newInterval;

        for (vector<int> curr : intervals)
        {
            if (are_overlapping(curr, temp)) //overlap is in same order
            {
                // combine the curr and temp and replace it with temp
                temp = combineInterval(curr, temp);
            }
            else // no overlap
            {
                if (curr[0] < temp[0]) //current is smaller than the temp
                {
                    //add current to final
                    FinalIntervals.push_back(curr);
                }
                else
                {
                    //add temp to final and replace temp with current
                    FinalIntervals.push_back(temp);
                    temp = curr;
                }
            }
        }
        FinalIntervals.push_back(temp);

        return FinalIntervals;
    }
    
    vector<int> combineInterval(vector<int>& interval1, vector<int>& interval2)
    {
        return { min(interval1[0], interval2[0]), max(interval1[1], interval2[1]) };
    }

    bool are_overlapping(vector<int>& interval1, vector<int>& interval2)
    {
        if (interval1[0] < interval2[0])//interval are in same order
        {
            if (interval1[1] - interval2[0] < 0)// no overlap
            {
                return 0;
            }
        }
        else if (interval1[0] > interval2[0]) //interval in reverse order
        {
            if (interval2[1] - interval1[0] < 0)// no overlap
            {
                return 0;
            }
        }
        
        return 1;//overlap anyway
    }
};



