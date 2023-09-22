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

// https://codeforces.com/problemset/problem/1527/B1

// AC'd

int runner() {
     int n;
     cin >> n;
     string alice = "ALICE", bob = "BOB", draw = "DRAW";
     string s;
     cin >> s;
     int zercnt = 0;
     for (auto &it : s)
          zercnt += (it == '0');
     if (zercnt == 0) {
          cout << draw << endl;
          return 0;
     }
     if (zercnt == 1) {
          cout << bob << endl;
          return 0;
     }
     if (zercnt % 2 == 0) {
          cout << bob << endl;

     } else {
          cout << alice << endl;
     }

     return 0;
}

int main() {
#ifndef ONLINE_JUDGE
     freopen("./../input.txt", "r", stdin);
     freopen("./../output.txt", "w", stdout);
#endif

     int _t;
     cin >>
         _t;
     while (_t--)
          runner();
}