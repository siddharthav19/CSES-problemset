#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// https://codeforces.com/problemset/problem/189/A

// very good problem for understanding greedy algorithm

// basically the greedy algorithm, will make an locally optimal choice at each stage and ends up being globally optimal but it doesnot blindly select the locally optimal choice/element, in most cases selection will be done in the following manner

// * [sort the data based on some property which leads/helps us to maximize/minimize the ans (used in many cases)] (mostly some classical problems follows this strategy)

//? (in this question for finding the maximum value/number)
//? take the maximum valued element such that after taking this element we can still reach the answer by filling digits in (currDigitsTrack-1) positions

bool printmax(int s, int m)
{
     int numsum = s;
     int len = m;
     string smax = "";
     bool found = true;
     while (len)
     {
          bool flag = false;
          for (int i = 9; i >= 0; i--)
          {
               if (i > numsum)
                    continue;
               int remsum = numsum - i;
               if ((len - 1) * 9 >= remsum)
               {
                    flag = true;
                    numsum = remsum;
                    smax.push_back('0' + i);
                    break;
               }
          }
          if (flag == false)
          {
               found = false;
               break;
          }
          len--;
     }
     if (found == false)
     {
          cout << "-1 -1" << endl;
          return false;
     }
     else
     {

          cout << smax << endl;
     }
     return true;
}
int runner()
{
     // You have a positive integer m and a non-negative integer s. Your task is to find the smallest and the largest of the numbers that have length m and sum of digits s. The required numbers should be non-negative integers written in the decimal base without leading zeroes.

     // Input
     // The single line of the input contains a pair of integers m, s (1 ≤ m ≤ 100, 0 ≤ s ≤ 900) — the length and the sum of the digits of the required numbers.

     // Output
     // In the output print the pair of the required non-negative integer numbers — first the minimum possible number, then — the maximum possible number. If no numbers satisfying conditions required exist, print the pair of numbers "-1 -1"

     int m, s;
     cin >> m >> s;
     if (s == 0 && m == 1)
     {
          cout << "0 0" << endl;
          return 0;
     }
     if (s == 0 && m > 1)
     {
          cout << "-1 -1" << endl;
          return 0;
     }
     if (printmax(s, m) == false)
          return 0;
     // printmin
     return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
#endif
     runner();
}
