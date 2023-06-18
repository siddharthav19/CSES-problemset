#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int mod = 1e9 + 7;

vector<vector<int>> dp;

// ll solve(int ind,vector<int> & nums,ll sum,ll tar){
// 	if(sum >= tar) return sum == tar;
// 	if(ind >= nums.size()) return 0;
// 	if(dp[ind][sum]!=-1) return dp[ind][sum];
// 	ll a1 = solve(ind,nums,sum+nums[ind],tar);
// 	ll a2 = solve(ind+1,nums,sum,tar);
// 	if(a1 >= mod) a1 = a1-mod;
// 	if(a2 >= mod) a2 = a2-mod;
// 	return dp[ind][sum] =(a1+a2 >= mod ? a1+a2 - mod: a1+a2);
// }

ll solveTabulation(vector<int> &nums, int x)
{
     int n = nums.size();
     vector<vector<int>> dp(n + 10, vector<int>(x + 1, 0));
     for (int i = 0; i < dp.size(); i++)
          dp[i][x] = 1;
     for (int ind = n - 1; ind >= 0; ind--)
     {
          for (int sum = x; sum >= 0; sum--)
          {
               ll a1 = 0;
               if (sum + nums[ind] <= x)
                    a1 = dp[ind][sum + nums[ind]];
               ll a2 = dp[ind + 1][sum];
               if (a1 >= mod)
                    a1 = a1 - mod;
               if (a2 >= mod)
                    a2 = a2 - mod;
               dp[ind][sum] = (a1 + a2 >= mod ? a1 + a2 - mod : a1 + a2);
          }
     }
     return dp[0][0];
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll n, x;
     cin >> n >> x;
     vector<int> nums(n);
     for (auto &it : nums)
          cin >> it;
     cout << solveTabulation(nums, x) << endl;
}