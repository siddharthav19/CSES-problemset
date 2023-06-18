#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int dp[(int)1e3 + 1][100001];

int solve(int ind, int x, vector<int> &nums, vector<int> &cost)
{
     if (ind >= nums.size() || x == 0)
          return 0;
     if (dp[ind][x] != -1)
          return dp[ind][x];
     int maxi = solve(ind + 1, x, nums, cost);
     if (cost[ind] <= x)
          maxi = max(maxi, nums[ind] + solve(ind + 1, x - cost[ind], nums, cost));
     return dp[ind][x] = maxi;
}

int solveTabulation(int maxim, vector<int> &nums, vector<int> &cost)
{
     vector<vector<int>> dp(nums.size() + 10, vector<int>(maxim + 10, 0));
     for (int ind = nums.size() - 1; ind >= 0; ind--)
     {
          for (int x = maxim; x >= 0; x--)
          {
               int maxi = dp[ind + 1][x];
               if (cost[ind] <= x)
                    maxi = max(maxi, nums[ind] + dp[ind + 1][x - cost[ind]]);
               dp[ind][x] = maxi;
          }
     }
     return dp[0][maxim];
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll n, x;
     cin >> n >> x;
     // memset(dp,-1,sizeof dp);
     vector<int> nums(n), cost(n);
     for (auto &it : cost)
          cin >> it;
     for (auto &it : nums)
          cin >> it;
     // cout<<solve(0,x,nums,cost)<<endl;
     cout << solveTabulation(x, nums, cost) << endl;
}