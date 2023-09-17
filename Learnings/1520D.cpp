#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define copyVec(nums)      \
     for (auto &it : nums) \
          cin >> it;
#define vecIterator(nums) for (auto &it : nums)
#define vecIndex(nums) for (int i = 0; i < nums.size(); i++)
int runner()
{
     int n;
     cin >> n;
     vi nums(n);
     copyVec(nums);
     ll count = 0;
     map<int, ll> mpp;
     vecIndex(nums)
     {
          int cur = nums[i];
          count += mpp[cur - i];
          mpp[cur - i]++;
     }
     cout << count << endl;
     return 0;
}

int main()
{

#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     int _t;
     cin >> _t;
     while (_t--)
          runner();
}
