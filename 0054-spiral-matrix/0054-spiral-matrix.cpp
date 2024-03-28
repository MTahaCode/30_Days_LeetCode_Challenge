class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> SpiralPattern;
        
        pair<int, int> top_left(0, 0);
        pair<int, int> top_right(matrix[0].size() - 1, 0);
        pair<int, int> bottom_left(0, matrix.size() - 1);
        pair<int, int> bottom_right(matrix[0].size() - 1, matrix.size() - 1);

        int direction = 0;

        for (int i = 0; i < matrix.size() * matrix[0].size(); i++)
        {
            if (direction == 0) // move right
            {
                for (int changes = top_left.first; changes <= top_right.first; changes++)
                {
                    //move from top left to top right
                    //y changes
                    // x same
                    SpiralPattern.push_back(matrix[top_left.second][changes]);
                    
                }
                top_left.second++;
                top_right.second++;
            }
            else if (direction == 1) // move down
            {
                for (int changes = top_right.second; changes <= bottom_right.second; changes++)
                {
                    //move from top right to bottom right
                    //x remain same
                    // y is j
                    SpiralPattern.push_back(matrix[changes][top_right.first]);
                }
                top_right.first--;
                bottom_right.first--;
            }
            else if (direction == 2) // move left
            {
                for (int changes = bottom_right.first; changes >= bottom_left.first; changes--)
                {
                    //move from bottom right to bottom left
                    //y remain same
                    // x is j
                    SpiralPattern.push_back(matrix[bottom_right.second][changes]);
                }
                bottom_right.second--;
                bottom_left.second--;
            }
            else if (direction == 3) // move up
            {
                for (int changes = bottom_left.second; changes >= top_left.second; changes--)
                {
                    //move from bottom left to top right
                    //x remain same
                    // y is j
                    SpiralPattern.push_back(matrix[changes][bottom_left.first]);
                }
                bottom_left.first++;
                top_left.first++;
                //bottom_left.second--;
            }
            
            if (top_left.second > bottom_left.second || top_left.first > top_right.first)
            {
                break;
            }

            direction = (direction + 1) % 4;
        }
        return SpiralPattern;
    }
};