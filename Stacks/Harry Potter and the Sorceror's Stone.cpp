/* Harry Potter wants to get the Philosopher's stone to protect it from Snape. Monk being the guard of Philosopher's Stone is very greedy and has a special bag, into which he can add one gold coin at a time or can remove the last gold coin he added. Monk will sleep, once he will have the enough number of gold coins worth amount X. To help Harry, Dumbledore has given a same kind of bag to Harry (as of Monk) with N gold coins each having worth A[i] where i range from 1=i=N.

Dumbledore also gave him a set of instructions which contains two types of strings:
1) "Harry" (without quotes): It means Harry will remove ith coin from his bag and throw it towards Monk and Monk will add it in his bag, where i will start from 1 and go up to N.
2) "Remove" (without quotes): it means Monk will remove the last coin he added in his bag.
Once the worth of the coins in Monk's bag becomes equal to X, Monk will go to sleep. In order to report Dumbledore, Harry wants to know the number of coins in Monk's bag, the first time their worth becomes equal to X.

Help Harry for the same and print the required number of coins. If the required condition doesn't occur print "-1" (without quotes).

Input Format

The first line will consists of one integer N denoting the number of gold coins in Harry's Bag.
Second line contains N space separated integers, denoting the worth of gold coins.
Third line contains 2 space separated integers Q and X, denoting the number of instructions and the value of X respectively.
In next Q lines, each line contains one string either "Harry" (without quotes) or "Remove" (without quotes).

Constraints

1=N=10^4
1=A[i]=10^4
1=Q=10^5
1=X=10^7

Output Format

In one line, print the the number of coins in the Monk's bag, the first time their worth becomes equal to X.

Sample Input 0

4
3 1 1 4
6 7
Harry
Harry
Harry
Remove
Remove
Harry
Sample Output 0

2
Explanation 0

Initailly, set of instructions contains "Harry", then Harry will throw 1st coin to Monk which is of worth 3 . Similarly Monk will have 2nd and 3rd gold coin in its bag, both having worth 1.

Now set contains "Remove" 2 times, which means Monk will remove 3rd and 2nd coin, both having worth 1.

Now Harry will throw 4th coin towards Monk having worth 4. Now the Monk's bag contains 2 coins with worth 3 and 4, which is equal to worth 7.

So the answer is 2. */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 stack<int> c;
 int n, q, x, t, j = 0, sum = 0;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 cin>>q>>x;
 while(q--){
     string sr;
     cin>>sr;
     if(sr == "Harry"){
         c.push(a[j]);
         sum+= a[j];
         j++;
     }
     if(sum == x){
         cout<<c.size()<<endl;
         break;
     }
     else if(sr == "Remove"){
         t = c.top();
         sum-= t;
         c.pop();
     }
 }
 if(sum!= x){
     cout<<"-1"<<endl;
 }
 return 0;
}
