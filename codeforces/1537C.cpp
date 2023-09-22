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

// https :  // codeforces.com/problemset/problem/1537/C
// AC'd

int runner() {
     int n;
     cin >> n;
     vi nums(n);
     copyVec(nums);
     sort(all(nums));
     int s = -1, e = -1;
     int mini = 1e9;
     for (int i = n - 1; i >= 1; i--) {
          if (mini >= nums[i] - nums[i - 1]) {
               mini = nums[i] - nums[i - 1];
               s = i - 1, e = i;
          }
     }

     vi ans(n);
     ans[0] = nums[s], ans[n - 1] = nums[e];
     int r = 1;
     for (int i = e + 1; i < n; i++) {
          ans[r++] = nums[i];
     }
     for (int i = 0; i < s; i++) {
          ans[r++] = nums[i];
     }
     for (auto &it : ans) cout << it << " ";
     cout << endl;
     return 0;
}

int main() {
#ifndef ONLINE_JUDGE
     freopen("./../input.txt", "r", stdin);
     freopen("./../output.txt", "w", stdout);
#endif

     int _t;
     cin >> _t;
     while (_t--)
          runner();
}
