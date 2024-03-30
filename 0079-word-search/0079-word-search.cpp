class Solution {
public:
    bool recurrExistence(vector<vector<char>>& board,
        pair<int, int> boardIndex, string word, int strIndex)
    {
        //if outside range or not matching return false
        if (boardIndex.first < 0 || boardIndex.first >= board.size()
        || boardIndex.second < 0 || boardIndex.second >= board[0].size()
        || word[strIndex] != board[boardIndex.first][boardIndex.second])
        {
            return false;
        }

        /*upon reaching here the index is within range and
          the word is present in this instance*/


        //now if word ended then word is foun
        if (strIndex == word.length() - 1)
        {
            return true;
        }

        //reaching here then the part of word is still left

        board[boardIndex.first][boardIndex.second] = '*';//making this visited

        //going to adjacent spaces
        bool local =  
                recurrExistence(board, { boardIndex.first, boardIndex.second - 1 }, word, strIndex + 1) ||
                recurrExistence(board, { boardIndex.first, boardIndex.second + 1 }, word, strIndex + 1) ||
                recurrExistence(board, { boardIndex.first - 1, boardIndex.second }, word, strIndex + 1) ||
                recurrExistence(board, { boardIndex.first + 1, boardIndex.second }, word, strIndex + 1);

        board[boardIndex.first][boardIndex.second] = word[strIndex];

        return local;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j= 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (recurrExistence(board, {i,j}, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};