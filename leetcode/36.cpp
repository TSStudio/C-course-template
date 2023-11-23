#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int box_num = (i / 3) * 3 + (j / 3);
                if (row[i][num] || col[j][num] || box[box_num][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                box[box_num][num] = true;
            }
        }
        return true;
    }
};