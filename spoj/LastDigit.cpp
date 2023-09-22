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
int unitnumber(int x, int y) {
     x = x % 10;

     if (y != 0)
          y = y % 4 + 4;

     return (((int)(pow(x, y))) % 10);
}
int runner() {
     ll a, b;
     cin >> a >> b;
     if (a == 0 || b == 0) {
          cout << 0 << endl;
          return 0;
     }
     cout<<unitnumber(a,b)<<endl;
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