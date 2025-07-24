# SlidingWindow_NeetCode

# 1. Best Time to Buy and Sell Stock
## Condition:

You are given an integer array `prices` where `prices[i]` is the price of NeetCoin on the `ith` day.

You may choose a **single day** to buy one NeetCoin and choose a **different day in the future** to sell it.

Return the maximum profit you can achieve. You may choose to **not make any transactions**, in which case the profit would be `0`.

**Example 1:**

```java
Input: prices = [10,1,5,6,7,1]

Output: 6
```

Explanation: Buy `prices[1]` and sell `prices[4]`, `profit = 7 - 1 = 6`.

**Example 2:**

```java
Input: prices = [10,8,7,5,2]

Output: 0
```

Explanation: No profitable transactions can be made, thus the max profit is 0.

## Intuition:
![[Pasted image 20250724153328.png]]
First, I tried to find the minimum element in the array and iterate through the increasing elements, but this approach was slow and inefficient.  
Then, I remembered that this problem belongs to the Sliding Window category and applied that technique.
![[Pasted image 20250724154931.png]]
Sliding Window used here in simplest form, we just move the left boardary whenever we encounter an element smaller than current one. Then we expend the window until we reach the maximum in our substring.
## Listing of my code:

```c++
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
```
