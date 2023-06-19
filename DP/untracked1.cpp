
/*

(I wrote this and also optimised by implementing my very own custom propagator)
(Without the custom propagator TC would be n^3)
*/

/*

You have a bag of N chocolates that you intend to eat. Eating chocolates makes you happy, but however, eating different number of chocolates in one sitting gives you different amounts of happiness. Formally, eating i number of chocolates, gives you hi amount of happiness.

Given the amounts of happiness you gain by eating i number of chocolates for all 1≤i≤N,you wonder what is the maximum total happiness that you can obtain from the N chocolates.

Note that you are allowed to eat the same number of chocolates i multiple times as long as the remaining number of chocolates is not lesser than i

[INPUT]
The first line of input contains a single integer t (1≤t≤1000) that denotes the number of test-cases. The next 2t lines describe the test-cases. The first line of each test-case contains a single integer N (1≤N≤1000) denoting the total number of chocolates. The next line of each test-case contains N space-separated integers, the ith number denoting the amount of happiness gained by eating i chocolates, hi (1≤hi≤105).

It is guaranteed that the sum of N across all test-cases does not exceed 1000

[OUTPUT]
For each test-case, output a single integer - the maximum amount of happiness that can be obtained from N chocolates.


SAMPLE INPUT 1:
2
8
3 5 8 9 10 17 17 20
8
1 5 8 9 10 17 17 20

SAMPLE OUTPUT 1:
24   (In the TC 1 eat all chocolates of index 0 ( happiness 3) )
22


*/

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<vector<int>> dp;

ll solve(int i, int chocos, vector<int> &nums)
{
     if (i >= nums.size())
          return 0;
     if (chocos == 0)
          return 0;
     if (chocos < 0)
          return -1e9;
     if (dp[i][chocos] != -1)
          return dp[i][chocos];
     ll maxi = solve(i + 1, chocos, nums);
     ll ch = maxi;
     if ((i + 1) <= chocos)
     {
          ch = nums[i] + solve(i, chocos - (i + 1), nums);
     }
     maxi = max(maxi, ch);
     return dp[i][chocos] = maxi;
}

int main()
{

     int tessie;
     cin >> tessie;
     while (tessie--)
     {
          int n;
          cin >> n;
          dp.clear();
          dp.resize(n + 10, vector<int>(n + 10, -1));
          vector<int> nums(n);
          for (auto &it : nums)
               cin >> it;
          cout << solve(0, n, nums) << endl;
     }
     return 0;
}