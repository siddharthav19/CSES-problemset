#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int mod = 1e9 + 7;

int dp[(int)1e6 + 10];

int solve(int n)
{
     if (n == 0)
          return 0;
     if (n < 0)
          return 1e9;
     if (dp[n] != -1)
          return dp[n];
     string s = to_string(n);
     int mini = 1e9;
     for (int i = 0; i < s.size(); i++)
     {
          char it = s[i];
          int dig = it - '0';
          if (it == '0')
               continue;
          mini = min(mini, 1 + solve(n - dig));
     }
     return dp[n] = mini;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp, -1, sizeof dp);
     ll n;
     cin >> n;
     int ans = solve(n);
     cout << ans << endl;
}