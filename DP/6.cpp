#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int mod = 1e9 + 7;
int dp[(int)1e3 + 10][1010];
int solve(int i, int j, vector<vector<char>> &grid)
{
     int n = grid.size();
     if (i >= n || j >= n || j < 0 || i < 0 || grid[i][j] == '*')
          return 0;
     if (i == n - 1 && j == n - 1)
          return 1;
     if (dp[i][j] != -1)
          return dp[i][j];
     ll ways = 0;
     ways = ways + solve(i, j + 1, grid) + solve(i + 1, j, grid);
     if (ways >= mod)
          ways -= mod;
     return dp[i][j] = ways;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp, -1, sizeof dp);
     ll n;
     cin >> n;
     vector<vector<char>> grid(n, vector<char>(n));
     for (auto &i : grid)
          for (auto &it : i)
               cin >> it;
     int ans = 0;
     if (grid[0][0] != '*' && grid[n - 1][n - 1] != '*')
          ans = solve(0, 0, grid);
     cout << ans << endl;
}