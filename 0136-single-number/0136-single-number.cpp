#include <map>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        map<int, int> num_map;

        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            cout << "Intermediate: " << *it << endl;

            if (num_map.find(*it) == num_map.end())
            {
                num_map[*it] = 1;
                continue;
            }
            num_map[*it]++;
        }

        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (num_map[*it] == 1)
            {
                return *it;
            }
        }

        return NULL;
    }
};