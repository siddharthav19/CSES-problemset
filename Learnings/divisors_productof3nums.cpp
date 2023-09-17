#include <bits/stdc++.h>
typedef long long int ll;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define vvpi vector<vector<pair<int, int>>>
#define fs first
#define sd second
#define endl '\n'
#include <ctime>
using namespace std;

ll pairs(ll x) { return (x * (x - 1)) / 2; }
vector<pair<int, int>> divisors(int n)
{
     vector<pair<int, int>> ans;
     for (int i = 2; i <= sqrt(n); i++)
     {
          if (n % i == 0)
          {
               if (n / i == i)
                    ans.push_back({i, i});
               else
                    i < n / i ? ans.push_back({i, n / i}) : ans.push_back({n / i, i});
          }
     }
     return ans;
}

pair<int, int> div(int n)
{
     for (int i = 2; i <= sqrt(n); i++)
     {
          if (n % i == 0)
               return {i, n / i};
     }
     return {-1, -1};
}

int runner()
{

     ll n;
     cin >> n;
     vector<pair<int, int>> d1 = divisors(n);
     for (int i = 0; i < d1.size(); i++)
     {
          ll x = d1[i].first;
          ll y = d1[i].second;
          auto s1 = div(y);
          auto s2 = div(x);
          set<int> s;
          if (s1.first != -1)
          {
               s.insert(x);
               s.insert(s1.first);
               s.insert(s1.second);
          }
          else if (s2.first != -1)
          {
               s.insert(y);
               s.insert(s2.first);
               s.insert(s2.second);
          }
          if (s.size() == 3)
          {
               auto it = s.begin();
               cout << "YES" << endl;
               cout << *it << " " << *(++it) << " " << *(++it) << endl;
               return 0;
          }
     }
     cout << "NO" << endl;
     // ++++++++++++++
     return 0;
}

int main()
{

     clock_t start, end;
     double cpu_time_used;
     start = clock();
     int tessie = 1;
     cin >> tessie;
     while (tessie--)
          runner();

#ifndef ONLINE_JUDGE
     end = clock();
     cpu_time_used = static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC;
     cout << "\n\ncode executed in : " << cpu_time_used << " ms";
#endif
}