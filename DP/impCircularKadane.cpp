#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll kadane(vector<int> &nums)
{
     ll n = nums.size();
     vector<ll> dp(n);
     dp[0] = nums[0];
     ll maxi = dp[0];
     for (int i = 1; i < n; i++)
     {
          dp[i] = max(dp[i - 1] + nums[i], nums[i] * 1ll);
          maxi = max(maxi, dp[i]);
     }
     return maxi;
}

int main()
{
     ll n;
     cin >> n;
     vector<int> nums(n);
     ll tot = 0;
     for (auto &it : nums)
     {
          cin >> it;
          tot += it;
     }
     ll a = kadane(nums);
     for (int i = 0; i < n; i++)
     {
          nums[i] = nums[i] * -1;
     }
     ll b = kadane(nums);

     // corner case (what if all array elements are negative the below statement handles that)
     if (b + tot == 0)
     {
          cout << a << endl;
          return 0;
     }
     cout << max(a, tot + b) << endl;
     return 0;
}
