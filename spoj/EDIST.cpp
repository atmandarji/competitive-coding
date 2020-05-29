// https://www.spoj.com/problems/EDIST/
#include<bits/stdc++.h>
using namespace std;

string s1,s2;
long long dp[2001][2001];

void init_dp(int m,int n){
  int i,j;
  bool flag=false;
  for(i=0;i<m;i++){
    flag = flag || s1[i]==s2[0];
    if(flag)
      dp[i][0] = i;
    else
      dp[i][0] = i+1;
  }
  flag=false;
  for(i=0;i<n;i++){
    flag = flag || s2[i]==s1[0];
    if(flag)
      dp[0][i] = i;
    else
      dp[0][i] = i+1;
  }
}

long long calc_ans(int m, int n){
  int i,j,k;
  for(i=1;i<m;i++){
    for(j=1;j<n;j++){
      if(s1[i]==s2[j])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1+dp[i-1][j-1];
      dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
    }
  }
  return dp[m-1][n-1];
}

int main(){
  int t;
  cin >>t;
  while(t--){
    cin >>s1>>s2;
    int m=s1.size();
    int n=s2.size();
    init_dp(m,n);
    cout <<calc_ans(m, n)<<endl;
  }
  return 0;
}
