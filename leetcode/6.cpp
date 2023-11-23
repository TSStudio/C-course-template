#include <cstdio>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows);
        int row = 0, flagDir = -1;
        for (char c : s) {
            rows[row] += c;
            if (row == 0 || row == numRows - 1) flagDir = -flagDir;
            row += flagDir;
        }
        string ans;
        for (string &row : rows) ans += row;
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    printf("%s\n", solution.convert(s, numRows).c_str());
    getchar();
    return 0;
}