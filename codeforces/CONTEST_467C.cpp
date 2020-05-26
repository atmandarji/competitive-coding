// https://codeforces.com/contest/467/problem/C
#include<bits/stdc++.h>
using namespace std;

long long nums[5010];
long long dp[5010][5010];
int m;

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
  for(i=0;i<5010;i++){
    for(j=0;j<5010;j++){
      dp[i][j]=-1;
    }
  }
  nums[0]=0;
  for(i=1;i<=n;i++){
    nums[i] += nums[i-1];
    dp[0][i] = 0;
  }
}

long long calc_ans(int n, int k){
  if(n==0) return 0;
  if(dp[n][k]!=-1) return dp[n][k];

  if(n<m || k==0){
    dp[n][k] = 0;
    return 0;
  }

  int i;
  long long ans = 0;
  for(i=0;i<m && n-i-m>=0;i++){
    long long sum = nums[n-i] - nums[n-i-m];
    long long curr_ans = maxx(calc_ans(n-i-m,k), sum + calc_ans(n-i-m,k-1));
    ans = maxx(ans, curr_ans);
  }
  dp[n][k] = ans;
  return ans;
}

int main(){
  int n,k,i;
  cin >>n>>m>>k;
  for(i=1;i<=n;i++){
    cin >>nums[i];
  }
  init_dp(n);
  cout <<calc_ans(n,k)<<endl;
  return 0;
}
