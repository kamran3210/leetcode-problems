class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        bool rowSets[9][9] = {0};
        bool colSets[9][9] = {0}; 
        bool boxSets[9][9] = {0};
        
        for(int row = 0; row < 9; row++)
            for(int col = 0; col < 9; col++)
                if(board[row][col] != '.')
                {
                    int num = board[row][col] - '1';
                    int box = row / 3 * 3 + col / 3;
                    if(rowSets[row][num] || colSets[col][num] || boxSets[box][num])
                        return false;
                    rowSets[row][num] = colSets[col][num] = boxSets[box][num] = true;
                }
        
        return true;
    }
};