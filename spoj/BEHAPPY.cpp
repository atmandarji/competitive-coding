// https://www.spoj.com/problems/BEHAPPY/
#include<bits/stdc++.h>
using namespace std;

long long dp[21][101];
long long chocs[21];

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

void init_dp(){
  int i,j;
  for(i=0;i<=21;i++){
    if(i<=chocs[0])
      dp[0][i] = 1;
    else
      dp[0][i] = 0;
  }
  for(i=1;i<21;i++){
    dp[i][0]=1;
    for(j=1;j<101;j++){
      dp[i][j]=-1;
    }
  }
}

long long calc_ans(int m, int n){
  if(dp[m][n]!=-1) return dp[m][n];

  int i,j;
  long long ans=0;
  for(i=0;i<=chocs[m] && n-i>=0;i++){
    ans += calc_ans(m-1,n-i);
  }
  dp[m][n]=ans;
  return ans;
}

int main(){
  int m,n,i;
  cin >>m>>n;
  for(i=0;i<m;i++){
    int a,b;
    cin >>a>>b;
    n-=a;
    b-=a;
    chocs[i] = b;
  }
  if(n<0){
    cout <<0<<endl;
  }
  else{
    init_dp();
    cout <<calc_ans(m-1,n)<<endl;
  }
  return 0;
}
