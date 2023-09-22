#include <bits/stdc++.h>
#define IOS                   \
     ios::sync_with_stdio(0); \
     cin.tie(0);              \
     cout.tie(0);
#define ll long long
#define endl "\n"
#define PI 3.14159265

using namespace std;

int freq[2001];
void solve() {
     stack<pair<int, int>> s;

     int n;
     cin >> n;
     int arr[n + 1];
     int i = 1;
     memset(arr, -1, sizeof(arr));
     while (n--) {
          int x;
          cin >> x;
          if (!s.empty()) {
               if (x > s.top().first) {
                    while (s.size() && x > s.top().first) {
                         arr[s.top().second] = i;
                         s.pop();
                    }
                    s.push({x, i});
               } else
                    s.push({x, i});
          } else
               s.push({x, i});
          i++;
     }
     int q;
     cin >> q;
     while (q--) {
          int x;
          cin >> x;
          cout << arr[x] << endl;
     }
}
int main() {
     IOS int t = 1;
     // cin>>t;
     while (t--)
          solve();

     return 0;
}
