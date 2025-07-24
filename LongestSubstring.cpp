#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        int left = 0;
        unordered_map<int, int> seen;

        for (int right = 0; right < n; right++) {
            int right_ch = s[right];

            while (seen.count(right_ch)) {
                int left_ch = s[left];
                seen.erase(left_ch);
                left += 1;
            }
            seen[right_ch] = right;
            res = max(res, right - left + 1);
        }
        return res; 
    }
};