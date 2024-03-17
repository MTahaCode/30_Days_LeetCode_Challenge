class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> Final;
        
        vector<int> prev;
        for (int i=0;i<numRows;i++)
        {
            vector<int> temp(prev.size() + 1, 1);
            for (int j=1; j<temp.size() - 1; j++)
            {
                temp[j] = prev[j] + prev[j - 1];
            }
            Final.push_back(temp);
            prev = temp;
        }
        
        return Final;
    }
};