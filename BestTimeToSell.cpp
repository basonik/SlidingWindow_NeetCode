#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_min = prices[0];
        int res = 0;
        for(int i = 0; i<prices.size(); i++){
            current_min = min(current_min, prices[i]);
            res = max(res, prices[i] - current_min);
        }
        return res;
    }
};