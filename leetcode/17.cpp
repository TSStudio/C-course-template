#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tmp;
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < letters[digits[i] - '2'].size(); k++) {
                    tmp.push_back(ans[j] + letters[digits[i] - '2'][k]);
                }
            }
            ans = tmp;
        }
        return ans;
    }
};