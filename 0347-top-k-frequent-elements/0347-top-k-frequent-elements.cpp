class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> ranking;

        for (int num : nums) {
            ranking[num]++;
        }

        vector<pair<int, int>> numWithOccurance(ranking.begin(), ranking.end());

        std::sort(numWithOccurance.begin(), numWithOccurance.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });

        vector<int> Final;
        for (int i = 0; i < k; i++) {
            Final.push_back(numWithOccurance[i].first);
        }

        return Final;
    }
};