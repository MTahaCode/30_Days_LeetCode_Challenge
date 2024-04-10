class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> ranking;

        for (int num : nums) {
            ranking[num]++;
        }

        vector<pair<int, int>> numWithOccurance;
        for (std::pair<int, int> num : ranking) {
            numWithOccurance.push_back(num);
        }

        std::sort(numWithOccurance.begin(), numWithOccurance.end(), 
            [](pair<int, int>& a, pair<int, int>& b) {
                return a.second > b.second;
            });

        vector<int> Final;
        for (int i = 0; i < k; i++) {
            Final.push_back(numWithOccurance[i].first);
        }

        return Final;
    }
};