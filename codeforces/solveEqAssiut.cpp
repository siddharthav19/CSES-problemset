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

// https://codeforces.com/group/c3FDl9EUi9/contest/264941/problem/C
// AC'd

int runner() {
     double c, time;
     cin >> c >> time;
     cout << setprecision(15);

     auto f = [&](double mid) -> bool {
          double r = mid * c * log2(mid);
          return r <= time;
     };

     double lo = 0.00000001, hi = 1.0000000;
     while (f(hi))
          hi = 2.0 * hi;
     double ans = hi;
     while (abs(hi - lo) >= 0.0000001) {
          double mid = lo + (hi - lo) / 2;
          if (f(mid)) {
               ans = mid;
               lo = mid;
          } else {
               hi = mid;
          }
     }
     // if f(x) <= time then f(x-1) is also <= time
     cout << ans << endl;

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