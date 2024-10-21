// https://www.codechef.com/problems/COINS
#include<bits/stdc++.h>
using namespace std;

map<long long, long long> dp;

long long minn(long long a, long long b){
  if(a<b){
    return a;
  }
  return b;
}

long long maxx(long long a, long long b){
  if(a>b){
    return a;
  }
  return b;
}

long long calc_ans(int n){
  if(dp.find(n)!=dp.end()) return dp[n];

  long long ans = calc_ans(n/2) + calc_ans(n/3) + calc_ans(n/4);
  ans = maxx(ans, n);
  dp[n] = ans;
  return ans;
}

int main(){
  cin.tie(NULL);
  long long n;
  dp[0] = 0;
  while(cin >> n){
    cout <<calc_ans(n)<<endl;
  }
  return 0;
}
