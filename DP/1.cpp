#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int mod = 1e9 + 7;
int dp[1000001];
ll solve(int n)
{
     if (n == 0)
          return 1;
     if (dp[n] != -1)
          return dp[n];
     ll ways = 0;
     for (int i = 1; i <= 6; i++)
          if (n >= i)
               ways = (ways % mod + solve(n - i) % mod) % mod;
     return dp[n] = ways % mod;
}

int main()
{
     memset(dp, -1, sizeof dp);
     int n;
     cin >> n;
     cout << solve(n) << endl;
}