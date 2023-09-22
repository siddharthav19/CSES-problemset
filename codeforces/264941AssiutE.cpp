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

int runner() {
     int n, k;
     cin >> n >> k;
     string s;
     cin >> s;
     map<char, int> mpp;
     for (int i = 0; i < k; i++) {
          mpp[s[i]]++;
     }
     int ans = mpp.size();
     int j = k;
     int i = 0;
     while (j < n) {
          mpp[s[i]]--;
          if (mpp[s[i]] == 0) mpp.erase(s[i]);
          i++;
          mpp[s[j]]++;
          j++;
          ans = max(ans, sz(mpp));
     }
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