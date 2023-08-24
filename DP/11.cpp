#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/189/A

int runner()
{
     int n, a, b, c;
     cin >> n >> a >> b >> c;
     int dp[n + 1] = {0};
     int x[] = {a, b, c};
     for (int i = 0; i < 3; i++)
          if (x[i] <= n)
               dp[x[i]] = 1;
     for (int i = min(a, min(b, c)); i <= n; i++)
     {
          int cur = i;
          for (int i = 0; i < 3; i++)
               if (cur - x[i] >= 0 && dp[cur - x[i]] != 0)
                    dp[cur] = max(dp[cur], 1 + dp[cur - x[i]]);
     }
     cout << dp[n] << endl;
     return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     runner();
}