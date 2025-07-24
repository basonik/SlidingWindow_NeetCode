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
First, I tried to find the minimum element in the array and iterate through the increasing elements, but this approach was slow and inefficient.  
Then, I remembered that this problem belongs to the Sliding Window category and applied that technique.
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

# 2. Longest Substring Without Repeating Characters

## Condition:

Given a string `s`, find the _length of the longest substring_ without duplicate characters.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```java
Input: s = "zxyzxyz"

Output: 3
```

Explanation: The string "xyz" is the longest without duplicate characters.

**Example 2:**

```java
Input: s = "xxxx"

Output: 1
```

## Intuition:

The first thing that came to my mind was a hash table. This structure allows storing certain elements and comparing them with the elements of the array. The hash table can also remove elements if they don’t meet the required conditions. Unlike arrays, hash tables can find specific elements with much lower time complexity. With an array, we would have to perform an unnecessary iteration over the elements. That's what I took advantage of.

## Listing of my code:

```c++
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
```

