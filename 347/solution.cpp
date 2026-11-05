
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Count frequency of each element
        for (int num : nums) {
            mp[num]++;
        }

        // Store elements in a vector
        vector<pair<int, int>> v;

        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }

        // Sort according to frequency (descending)
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Store top k frequent elements
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = obj.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
