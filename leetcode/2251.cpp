#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using std::map;
using std::sort;
using std::vector;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int> > &flowers, vector<int> &people) {
        map<int, int> count;
        for (auto &flower : flowers) {
            count[flower[0]]++;
            count[flower[1] + 1]--;
        }
        int m = people.size();
        vector<int> indices(m);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return people[a] < people[b];
        });
        vector<int> ans(m);
        int curr = 0;
        auto it = count.begin();
        for (int x : indices) {
            while (it != count.end() && it->first <= people[x]) {
                curr += it->second;
                it++;
            }
            ans[x] = curr;
        }
        return ans;
    }
};