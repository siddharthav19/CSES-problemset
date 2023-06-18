#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int mod = 1e9 + 7;
vector<int> dp;

// this mod operation is very heavy so do
// if(ways >= mod) ways = ways - mod;
// instead of ways = ways % mod;

ll solve(vector<int> &nums, ll sum, ll tar)
{
     if (sum >= tar)
          return sum == tar;
     if (dp[sum] != -1)
          return dp[sum];
     ll ways = 0;
     for (auto it : nums)
     {
          ways = ways + solve(nums, sum + it, tar);
          if (ways >= mod)
               ways -= mod;
     }
     return dp[sum] = ways;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll n, x;
     cin >> n >> x;
     dp.resize(x + 100, -1);
     vector<int> nums(n);
     for (auto &it : nums)
          cin >> it;
     cout << solve(nums, 0, x) << endl;
}