/*
There are N students, Girls or Boys, standing in a line forming an alt sequence.

A non empty sequence of Girls and Boys is called an alt sequence, if Boys and Girls are standing alternatively.
For example, sequence "Girl, Boy, Girl" and "Boy" are both alt sequence while "Girl, Girl" is not an alt sequence.

You need to find out, how many ways are there to pick an alt subsequence from original sequence. Since number of ways will be huge, report after taking modulo 109+7.



Input ::

First Line: Integer N denoting number of students standing in line. You can assume this to be Girl, Boy, Girl,...
Constraints 1 ≤ N ≤ 106

Output ::
Print a single number, answer modulo 1000000007.

example :
 i)  n = 3
     ans is 6

     reason::
     Lets take first example. Initial line is {Girl, Boy, Girl}. So there are 6 possible subsequences that form alt sequence.
     pick first student
     pick second student
     pick third student
     pick first and second student
     pick second and third student
     pick first, second and third student


 ii) n = 4
     ans is 11


*/

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

// 0 means prev boy
// 1 means prev girl
// 2 means prev not exists

// i%2 == 1 -> girl
int mod = 1e9 + 7;

int dp[(int)1e6 + 9][3];

int solve(int i, int prev)
{
    if (i == 0)
        return prev != 2;
    if (dp[i][prev] != -1)
        return dp[i][prev];
    ll ways = solve(i - 1, prev) % mod;
    if (i % 2 == 1 && (prev == 0 || prev == 2))
        ways += solve(i - 1, 1) % mod;
    if (i % 2 == 0 && (prev == 1 || prev == 2))
        ways += solve(i - 1, 0) % mod;
    return dp[i][prev] = ways % mod;
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << solve(n, 2) << endl;
    return 0;
}