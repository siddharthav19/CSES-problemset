/*
Irene Adler has managed to sneak into the historic museum of binary land. She wants to borrow
some of the historic binary strings of independence. She has a special handbag that can fit any number of binary strings in it as long as they have at most m zeroes and at most n ones. She plans to take as many of the historic binary strings of independence as possible. Help her achieve this by telling her the maximum number of historic binary strings of independence she can borrow quickly before Sherlock Holmes catches up with her.

INPUT ::
The first line contains three integers c(1≤c≤200)
, m(1≤m≤100) and n(1≤n≤100) the number of binary strings, the maximum number of zeros and the maximum number of ones,respectively. The next c lines contain c binary strings (1≤len(stringi)≤100)

OUTPUT ::
Output a single integer as the answer

*/

#include <bits/stdc++.h>
using namespace std;

int dp[201][101][101];
int solve(int i, int z, int o, vector<string> &binary_strings, vector<pair<int, int>> &counter)
{
     if (i >= binary_strings.size())
          return 0;
     if (z == 0 && o == 0)
          return 0;
     if (dp[i][z][o] != -1)
          return dp[i][z][o];
     int zeroes = counter[i].first;
     int ones = counter[i].second;
     int maxi = solve(i + 1, z, o, binary_strings, counter);
     if (zeroes <= z && ones <= o)
     {
          maxi = max(maxi, 1 + solve(i + 1, z - zeroes, o - ones, binary_strings, counter));
     }
     return dp[i][z][o] = maxi;
}

pair<int, int> count_zero_one(string &a)
{
     int zeroes = 0;
     int ones = 0;
     for (auto &it : a)
     {
          if (it == '0')
               zeroes++;
          else
               ones++;
     }
     return {zeroes, ones};
}

int main()
{

     int c, z, o;
     cin >> c >> z >> o;
     vector<string> binary_strings;
     // zeroes , ones
     vector<pair<int, int>> counter;
     for (int i = 0; i < c; i++)
     {
          string s;
          cin >> s;
          binary_strings.push_back(s);
          counter.push_back(count_zero_one(s));
     }
     memset(dp, -1, sizeof dp);
     cout << solve(0, z, o, binary_strings, counter) << endl;
     return 0;
}