class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        	//first take transpose
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = row + 1; col < matrix[0].size(); col++)
            {
                if (row >= col)
                {
                    continue;
                }
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        //then swap column having same distance from middle
        for (int col = 0; col < matrix[0].size()/2; col++)
        {
            for (int row = 0; row < matrix.size(); row++)
            {
                swap(matrix[row][col], matrix[row][matrix.size() - 1 - col]);
            }
        }
    }
};