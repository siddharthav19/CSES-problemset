#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

// O(n^2) solution is very easy but converting
// that O(n^2) to O(n) is quite difficult/tricky & interesting

int mod = 1e9 + 7;

// int dp[(int)1e6+10][3];
// int solve(int i,int prev,int n){
// 	if(i>= n) return i==n;
// 	if(dp[i][prev]!=-1) return dp[i][prev];
// 	ll ans = 0;
// 	ll blocks1 = solve(i+1,0,n)%mod;
// 	ll blocks2 = solve(i+1,1,n)%mod;
// 	if(prev==2)
// 		ans = blocks1%mod+blocks2%mod;
// 	else if(prev == 0)
// 		ans = (4*(blocks1%mod))%mod + blocks2%mod;
// 	else
// 		ans = blocks1%mod + (2*(blocks2%mod))%mod;
// 	return dp[i][prev] = ans%mod;
// }

int solveTabulation(int n, vector<vector<int>> &dp)
{
     dp[n][0] = 1;
     dp[n][1] = 1;
     dp[n][3] = 1;
     for (int i = n - 1; i >= 0; i--)
     {
          for (int prev = 0; prev < 3; prev++)
          {
               ll ans = 0;
               ll blocks1 = dp[i + 1][0] % mod;
               ll blocks2 = dp[i + 1][1] % mod;
               if (prev == 2)
                    ans = blocks1 % mod + blocks2 % mod;
               else if (prev == 0)
                    ans = (4 * (blocks1 % mod)) % mod + blocks2 % mod;
               else
                    ans = blocks1 % mod + (2 * (blocks2 % mod)) % mod;
               dp[i][prev] = ans % mod;
          }
     }
     return dp[0][2];
}

int main()
{
     vector<vector<int>> dp(1e6 + 10, vector<int>(3, 0));
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll tessie;
     cin >> tessie;
     solveTabulation(1000000, dp);
     while (tessie--)
     {
          ll n;
          cin >> n;
          cout << dp[1000000 - n][2] << endl;
     }
}