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

int runner(int a, int b, int c) {
     string ap = "AP", gp = "GP";
     int ans = -1;
     int diff = b - a;
     if (diff == c - b) {
          cout << ap << " " << diff + c << endl;
          return 0;
     }
     if (a == 0 || b == 0 || c == 0) return 0;
     int ratio = b / a;
     if (ratio == c / b) {
          cout << gp << " " << int(c * ratio) << endl;
     }
     return 0;
}

int main() {
#ifndef ONLINE_JUDGE
     freopen("./../input.txt", "r", stdin);
     freopen("./../output.txt", "w", stdout);
#endif
     while (true) {
          int a, b, c;
          cin >> a >> b >> c;
          if (a == 0 && b == 0 && c == 0) break;
          runner(a, b, c);
     }
}