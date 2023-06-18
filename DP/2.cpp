#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int dp[(int)1e6 + 1];

ll solve(vector<int> &nums, ll sum, ll tar)
{
     if (sum == tar)
          return 0;
     if (sum > tar)
          return 1e9;
     if (dp[sum] != -1)
          return dp[sum];
     ll mini = 1e9;
     for (auto it : nums)
          mini = min(mini, 1 + solve(nums, sum + it, tar));
     return dp[sum] = mini;
}

int main()
{
     memset(dp, -1, sizeof dp);
     ll n, x;
     cin >> n >> x;
     vector<int> nums(n);
     for (auto &it : nums)
          cin >> it;
     int ans = solve(nums, 0, x);
     ans = ans == 1e9 ? -1 : ans;
     cout << ans << endl;
}