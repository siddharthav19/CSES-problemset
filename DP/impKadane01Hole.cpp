#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int> &arr)
{
     // vector<vector<int>> dp(arr.size(),vector<int>(2,0));
     // extending the powerful kadanes algo
     /*
         dp[i] = max subarray ending at index i
         dp[i] = max(arr[i],arr[i]+dp[i-1])
     */

     // dp[i][0] -> denotes maximum sum of subarray ending at index i with exactly 0 deletion
     // dp[i][1] -> denotes maximum sum of subarray ending at index i with exactly 1 deletion

     // the relation would be
     // dp[i][0] = max(arr[i]+dp[i-1][0],arr[i])
     // dp[i][1] = max(dp[i-1][0],dp[i-1][1]+arr[i])

     // initialising maxi correctly is pretty important here as they -
     //  - are asking non empty subarray

     /*
           vector<vector<int>> dp(arr.size(),vector<int>(2,0));
              dp[0][0] = arr[0];
              dp[0][1] = max(0,dp[0][0]);
              int maxi = dp[0][0];
              for(int i = 1;i<arr.size();i++){
                  dp[i][0] = max(arr[i]+dp[i-1][0],arr[i]);
                  dp[i][1] = max(dp[i-1][0],dp[i-1][1]+arr[i]);
                  maxi = max(maxi,max(dp[i][0],dp[i][1]));
              }
              return maxi;


     */

     // after optimising the space you would get the below one

     vector<int> dp(2, 0);
     vector<int> next(2, 0);
     dp[0] = arr[0];
     dp[1] = max(0, dp[0]);
     int maxi = dp[0];
     for (int i = 1; i < arr.size(); i++)
     {
          next[0] = max(arr[i] + dp[0], arr[i]);
          next[1] = max(dp[0], dp[1] + arr[i]);
          maxi = max(maxi, max(next[0], next[1]));
          dp = next;
     }
     return maxi;
}

int main()
{
     vector<int> v;
}