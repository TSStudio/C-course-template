#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct roman {
        int val;
        string str;
    };
    string intToRoman(int num) {
        roman romans[] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}};
        string ans = "";
        for (int i = 0; i < 13; i++) {
            while (num >= romans[i].val) {
                ans += romans[i].str;
                num -= romans[i].val;
            }
        }
        return ans;
    }
};