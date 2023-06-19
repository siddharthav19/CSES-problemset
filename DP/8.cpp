#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int mod = 1e9 + 7;

int dp[(int)1e5 + 10][110];
int solve(int i, int prev, vector<int> &nums, int m)
{
     if (i >= nums.size())
          return 1;
     if (dp[i][prev] != -1)
          return dp[i][prev];
     ll ways = 0;
     if (nums[i] != 0)
     {
          if (prev != m + 1 && abs(nums[i] - prev) > 1)
               return 0;
          return dp[i][prev] = solve(i + 1, nums[i], nums, m);
     }
     int start = 1, end = m;
     if (prev != m + 1)
     {
          start = max(prev - 1, 1);
          end = min(prev + 1, m);
     }
     for (int j = start; j <= end; j++)
     {
          ways = ways + solve(i + 1, j, nums, m);
          if (ways >= mod)
               ways -= mod;
     }

     return dp[i][prev] = ways;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp, -1, sizeof dp);
     ll n, m;
     cin >> n >> m;
     vector<int> nums(n);
     for (auto &it : nums)
          cin >> it;
     cout << solve(0, m + 1, nums, m) << endl;
}