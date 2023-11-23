#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int a = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int b = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (a == b) return {-1, -1};
        return {a, b - 1};
    }
};