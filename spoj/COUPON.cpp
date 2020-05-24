// https://www.codechef.com/problems/COUPON
#include<bits/stdc++.h>
using namespace std;

long long min(long long a, long long b){
  if(a>b){
    return b;
  }
  return a;
}

int main(){
  long long t;
  cin >>t;
  while(t--){
    long long n,m,i,j;
    cin >>n>>m;
    long long cost[n][m];
    long long disc[n][m];
    long long dp[n][m];
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cin >>cost[i][j];
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cin >>disc[i][j];
      }
    }
    long long ans = 0;
    long long min_c = cost[0][0];
    for(i=0;i<m;i++){
      dp[0][i] = cost[0][i];
      min_c = min(min_c, cost[0][i]);
    }
    ans = min_c;
    long long prev_min = min_c;
    for(i=1;i<n;i++){
      min_c = -1;
      for(j=0;j<m;j++){
        long long no_disc = prev_min + cost[i][j];
        long long disc_c = cost[i][j] - disc[i-1][j];
        if(disc_c < 0){
          disc_c = 0;
        }
        disc_c += dp[i-1][j];
        dp[i][j] = min(no_disc, disc_c);
        if(min_c == -1){
          min_c = dp[i][j];
        }
        else{
          min_c = min(min_c, dp[i][j]);
        }
      }
      ans = min_c;
      prev_min = min_c;
    }
    cout <<ans<<endl;;
  }
  return 0;
}
