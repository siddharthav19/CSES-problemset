#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vvs vector<vs>
#define copyVec(nums) \
     for (auto &it : nums) cin >> it;
#define vecIterator(nums) for (auto &it : nums)
#define vecIndex(nums) for (int i = 0; i < nums.size(); i++)
#define vecMax(nums) *max_element(nums.begin(), nums.end())
#define vecMin(nums) *min_element(nums.begin(), nums.end())
#define all(nums) nums.begin(), nums.end()
#define sz(nums) (int)nums.size()

int runner() {
     int n;
     cin >> n;
     vi nums;
     for (int i = 0; i < n; i++) {
          string x;
          int r;
          cin >> x >> r;
          nums.push_back(r);
     }
     int count = 0;
     sort(all(nums));
     for (auto &it : nums) cout << it << " ";
     cout << endl;
     int lo = 1;
     for (int i = 0; i < n; i++) {
          count += abs(nums[i] - i - 1);
     }
     cout << count << endl;
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