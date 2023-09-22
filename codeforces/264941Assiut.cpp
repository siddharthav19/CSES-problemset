#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define copyVec(nums) \
     for (auto &it : nums) cin >> it;
#define vecIterator(nums) for (auto &it : nums)
#define vecIndex(nums) for (int i = 0; i < nums.size(); i++)
#define vecMax(nums) *max_element(nums.begin(), nums.end())
#define vecMin(nums) *min_element(nums.begin(), nums.end())
#define all(nums) nums.begin(), nums.end()
#define sz(nums) (int)nums.size()

// https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/D
// AC'd

int runner() {
     int n;
     ll m;
     cin >> n >> m;
     vi nums(n);
     copyVec(nums);
     int i = 0, j = 0;
     ll sum = 0;
     int ans = n + 1;
     while (j < n) {
          sum += nums[j];
          while (sum >= m) {
               ans = min(ans, j - i + 1);
               sum -= nums[i];
               i++;
          }
          j++;
     }
     cout << (ans == n + 1 ? -1 : ans) << endl;
     return 0;
}

int main() {
#ifndef ONLINE_JUDGE
     freopen("./../input.txt", "r", stdin);
     freopen("./../output.txt", "w", stdout);
#endif

     // int _t;cin>>_t;while(_t--)
     runner();
}