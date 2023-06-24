std::ostream& operator<< (std::ostream& os, std::unordered_set<char> const& s) {
    for (char i : s)
        os << i << ' ';
    return os << "\n";
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(i, board) || !isValidCol(i, board) || !isValidBox(i, board))
                return false;
        }
        return true;
    }
private:
    bool isUnique(char c, bool set[]) {
        if (c == '.') return true;
        if (set[c - '1']) return false;
        return set[c - '1'] = true;
    }

    bool isValidRow(int row, vector<vector<char>>& board) {
        bool set[9];
        memset(set, false, sizeof(set));
        for (auto const& c : board[row]) {
            if (!isUnique(c, set)) return false;
        }
        return true;
    }

    bool isValidCol(int col, vector<vector<char>>& board) {
        bool set[9];
        memset(set, false, sizeof(set));

        for (int i = 0; i < 9; i++) {
            char c = board[i][col];
            if (!isUnique(c, set)) return false;
        }
        return true;
    }

    bool isValidBox(int box, vector<vector<char>>& board) {
        bool set[9];
        memset(set, false, sizeof(set));

        int x = (box % 3) * 3;
        int y = (box / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[y + i][x + j];
                if (!isUnique(c, set)) return false;
            }
        }
        return true;
    }

    
};