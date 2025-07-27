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

## Explanation:

We have two main variables:

1. The **left pointer** – for easy movement when the condition fails (i.e., when a duplicate element is encountered).
    
2. The **hash table** – to store seen elements, allowing efficient uniqueness checks for each element in the substring.
    

We process each element using the **right pointer** (following the sliding window technique), adding it to the hash table and checking:

- If the element already exists in the hash table, we move the **left pointer** forward.
    
- We then check if the current substring is the longest found so far, since our goal is to find the **maximum-length substring with all unique elements**.

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

# 3. Longest Repeating Character Replacement

## Condition

You are given a string `s` consisting of only uppercase english characters and an integer `k`. You can choose up to `k` characters of the string and replace them with any other uppercase English character.

After performing at most `k` replacements, return the length of the longest substring which contains only one distinct character.

**Example 1:**

```java
Input: s = "XYYX", k = 2

Output: 4
```

Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

**Example 2:**

```java
Input: s = "AAABABB", k = 1

Output: 5
```


## Intuition:

First, I had the idea to use a hash function, just like in the previous problem: track the used letters, find the one that appears most frequently in the string, and then perform k swaps—replacing the least frequent letters with the most frequent one.
The idea was good, but clearly incomplete. I looked up the solution and its explanation on GeeksforGeeks. I was fascinated by the approach of using a 26-element vector (initially filled with zeros) to represent letter counts, and how it accessed specific letters via `[s[right] - 'A']`. Let’s break down the solution.
## Explanation:

First, we use the sliding window method, meaning we declare the variables `left` and `right`, as well as `max_cnt` to keep track of how many times a specific letter appears. While iterating with the right pointer, we increase the count of the encountered letters in our vector and update `max_cnt`. If the number of letters we can theoretically change exceeds `k`, we shift the left pointer to the right and remember to adjust the letter count vector—when moving the pointer, we decrement the count of the letter that was at the left pointer. Finally, we return the difference between the right and left pointers.

## Listing of my code:

```c++
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
```

# 4. Permutation in string

## Condition:

You are given two strings `s1` and `s2`.

Return `true` if `s2` contains a permutation of `s1`, or `false` otherwise. That means if a permutation of `s1` exists as a substring of `s2`, then return `true`.

Both strings only contain lowercase letters.

**Example 1:**

```java
Input: s1 = "abc", s2 = "lecabee"

Output: true
```

Explanation: The substring `"cab"` is a permutation of `"abc"` and is present in `"lecabee"`.

**Example 2:**

```java
Input: s1 = "abc", s2 = "lecaabee"

Output: false
```

## Listing of my code:

```c++
class Solution {

public:

    bool checkInclusion(string s1, string s2) {

        unordered_map<char, int> f_string;

        for(char c : s1){

            f_string[c]++;

        }

        int wind_size = s1.size();

        unordered_map<char, int> wind;

  

        for(int i = 0; i < wind_size; i++){

            wind[s2[i]]++;

        }

  

        if(wind == f_string){

            return true;

        }

  

        for(int i = wind_size; i < s2.size(); i++){

            char left = s2[i-wind_size];

            if(wind[left] == 1){

                wind.erase(left);

            }

            else{

                wind[left]--;

            }

  

            char right = s2[i];

            wind[right]++;

  

            if(wind == f_string){

                return true;

            }

        }

        return false;

    }

};
```
