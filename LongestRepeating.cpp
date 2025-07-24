#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int max_cnt = 0;
        vector<int> cnt(26, 0);

        for(right = 0; right < s.size(); ++right){
            cnt[s[right]- 'A']++;
            max_cnt = max(max_cnt, cnt[s[right]- 'A']);

            if(right-left+1-max_cnt > k){
                cnt[s[left]- 'A']--;
                left+=1;
            }
        }
        return right - left;
    }
};