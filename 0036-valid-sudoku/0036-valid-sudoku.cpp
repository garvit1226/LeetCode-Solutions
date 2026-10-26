
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int dig = board[i][j] - '1';
                int idx = (i / 3) * 3 + j / 3;

                if (row[i][dig] || col[j][dig] || box[idx][dig])
                    return false;

                row[i][dig] = true;
                col[j][dig] = true;
                box[idx][dig] = true;
            }
        }

        return true;
    }
};
