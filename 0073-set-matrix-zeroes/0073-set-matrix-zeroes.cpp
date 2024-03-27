class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        vector<pair<int, int>> Zero_Coords;

        for (int row = 0; row < matrix.size(); row++)
        {
            for (int column = 0; column < matrix[0].size(); column++)
            {
                if (matrix[row][column] == 0)
                {
                    Zero_Coords.push_back({ row, column });
                }
            }
        }

        for (pair<int, int> coords : Zero_Coords)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[coords.first][i] = 0;
            }

            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][coords.second] = 0;
            }
        }
    }
};