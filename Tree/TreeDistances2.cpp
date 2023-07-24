#include <bits/stdc++.h>
#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;

vi sub_tree_size, ans, child_depth;
vvi adj;
int total_nodes = 0;

int eval_size(int node, int par)
{
     sub_tree_size[node] = 1;
     for (auto &it : adj[node])
     {
          if (it != par)
               sub_tree_size[node] += eval_size(it, node);
     }
     return sub_tree_size[node];
}

int eval_child_depth(int node, int par)
{
     for (auto &it : adj[node])
     {
          if (it != par)
          {
               child_depth[node] += eval_child_depth(it, node);
          }
     }
     child_depth[node] += sub_tree_size[node] - 1;
     return child_depth[node];
}

void dfs(int node, int par)
{
     ans[node] = 0;
}

void runner()
{
     int n;
     cin >> n;
     sub_tree_size.resize(n + 1, 0);
     adj.resize(n + 1);
     ans.resize(n + 1, 0);
     child_depth.resize(n + 1, 0);
     for (int i = 0; i < n - 1; i++)
     {
          int a, b;
          cin >> a >> b;
          adj[a].push_back(b);
          adj[b].push_back(a);
     }
     eval_size(1, -1);
     eval_child_depth(1, -1);
     total_nodes = sub_tree_size[1];
     dfs(1, -1);
     for (auto &it : ans)
          cout << it << " ";
     cout << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     runner();
     // cout << 36 << endl;
}