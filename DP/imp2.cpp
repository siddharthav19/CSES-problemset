/*
Question

You are given N positive integers. You are allowed to drop some (≥ 0) numbers
while keeping remaining numbers in same relative order as originally given.
You need to print, minimum number of drop
operation needed such that remaining numbers form a dividing sequence.

A dividing sequence is, a sequence of ordered numbers where ith number is
divisible by (i-1)th number for all possible i > 0.



Input::

First line has N, number of integers.
Each of next N lines has one integer representing array.


Constraints::

1   ≤   N   ≤   104
1   ≤   Each Value in Array   ≤   109

Output::

Single Integer, number of remaining numbers after applying
min possible number of drop operations.



*/

// Kind of similar to Algorithmic LIS

// dp[i] denotes maximum length of dividing subsequence ending at i

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int i, int prev, vector<int> &nums)
{
     if (i >= nums.size())
          return 0;
     if (dp[i][prev] != -1)
          return dp[i][prev];
     int maxi = solve(i + 1, prev, nums);
     if (prev == nums.size() || nums[i] % nums[prev] == 0)
     {
          maxi = max(maxi, 1 + solve(i + 1, i, nums));
     }
     return dp[i][prev] = maxi;
}

int main()
{
     int n;
     cin >> n;
     vector<int> nums(n);
     for (auto &it : nums)
          cin >> it;
     vector<int> dp(n, 1);
     int maxi = 0;

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < i; j++)
          {
               if (nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], 1 + dp[j]);
          }
          maxi = max(maxi, dp[i]);
     }

     cout << maxi << endl;
     return 0;
}