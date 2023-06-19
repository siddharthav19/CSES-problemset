#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int dp[5005][5005];
int solve(int i, int j, string &s, string &t)
{
     if (i == s.size())
          return t.size() - j;
     if (j == t.size())
          return s.size() - i;
     if (dp[i][j] != -1)
          return dp[i][j];
     if (s[i] == t[j])
          return solve(i + 1, j + 1, s, t);
     int op1 = 1 + solve(i, j + 1, s, t);
     int op2 = 1 + solve(i + 1, j, s, t);
     int op3 = 1 + solve(i + 1, j + 1, s, t);
     return dp[i][j] = min(op1, min(op2, op3));
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp, -1, sizeof dp);
     string s, t;
     cin >> s >> t;
     cout << solve(0, 0, s, t) << endl;
}