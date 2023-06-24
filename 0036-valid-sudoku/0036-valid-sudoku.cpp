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
    bool isUnique(char c, unordered_set<char>& set) {
        if (c == '.') return true;
        auto p = set.insert(c);
        return p.second;
    }

    bool isValidRow(int row, vector<vector<char>>& board) {
        unordered_set<char> set;
        for (auto const& c : board[row]) {
            if (!isUnique(c, set)) return false;
        }
        return true;
    }

    bool isValidCol(int col, vector<vector<char>>& board) {
        unordered_set<char> set;
        for (int i = 0; i < 9; i++) {
            char c = board[i][col];
            if (!isUnique(c, set)) return false;
        }
        return true;
    }

    bool isValidBox(int box, vector<vector<char>>& board) {
        unordered_set<char> set;
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