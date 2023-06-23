#include <bits/stdc++.h>
typedef long long int ll;
#define pb push_back
using namespace std;

// CSES
// Topological Sorting
// whenever you want to solve questions like number of paths from source to destination and longest path from source to destination in DAG(V.V.V.V IMP) (basically NP hard problems on normal graphs but these will be solvable in O(N) or O(N log N) using TOPOLOGICAL SORTING when the graph is DAG)

int mod = 1e9 + 7;

vector<int> s;
void dfs(int node, vector<bool> &visi, vector<vector<int>> &adj)
{
     visi[node] = 1;
     for (auto it : adj[node])
          if (!visi[it])
               dfs(it, visi, adj);
     s.push_back(node);
}

int main()
{

     clock_t start;
     double cpu_time_used;
     start = clock();
     int n, m;
     cin >> n >> m;
     vector<bool> visi(n + 1, 0);
     vector<vector<int>> adj(n + 1);
     for (int i = 0; i < m; i++)
     {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
     }
     for (int i = 1; i <= n; i++)
          if (!visi[i])
               dfs(i, visi, adj);
     reverse(s.begin(), s.end());

     vector<ll> cur(n + 1, 0);
     vector<ll> total(n + 1, 0);
     cur[1] = 1;
     total[1] = 1;
     for (int i = 0; i < s.size(); i++)
     {
          for (auto it : adj[s[i]])
          {
               cur[it] += cur[s[i]] % mod;
               cur[it] %= mod;
          }
     }

     cout << cur[n] % mod;
#ifndef ONLINE_JUDGE
     clock_t end = clock();
     cpu_time_used = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;
     cout << "\n\ncode executed in : " << cpu_time_used << " ms";
#endif
}