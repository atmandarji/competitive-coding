// https://www.spoj.com/problems/FARIDA/
#include<bits/stdc++.h>
using namespace std;

long long nums[10010];
long long dp[10010][2];

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

void init_dp(int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
      dp[i][j]=-1;
    }
  }
  dp[0][0] = 0;
  dp[0][1] = nums[0];
}

long long calc_ans(int n, int include){
  if(dp[n][include]!=-1) return dp[n][include];

  long long ans = 0;
  if(include==1){
    ans = nums[n] + calc_ans(n-1,0);
  }
  else{
    ans = maxx(calc_ans(n-1,1), calc_ans(n-1,0));
  }
  dp[n][include] = ans;
  return ans;
}

int main(){
  int t,c;
  cin >>t;
  long long anss[t];
  for(c=1;c<=t;c++){
    int n,i;
    cin >>n;
    for(i=0;i<n;i++){
      cin >>nums[i];
    }
    init_dp(n);
    anss[c-1] = maxx(calc_ans(n-1, 1), calc_ans(n-1, 0));
  }
  for(c=1;c<=t;c++){
    cout <<"Case "<<c<<": "<<anss[c-1]<<endl;
  }
}
