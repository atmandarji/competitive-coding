// https://www.spoj.com/problems/WACHOVIA/
#include<bits/stdc++.h>
using namespace std;

int weights[51];
int values[51];
long long dp[1001][51];

void init_dp(int w,int n){
  int i,j;
  for(i=0;i<=w;i++){
    for(j=0;j<n;j++){
      dp[i][j]=-1;
      if(i==0)
        dp[i][j]=0;
      if(j==0 && i>=weights[j])
        dp[i][j]=values[j];
      else if(j==0)
        dp[i][j]=0;
    }
  }
}

long long calc_ans(int w, int n){
  if(dp[w][n]!=-1) return dp[w][n];

  long long ans=calc_ans(w,n-1);;
  if(weights[n]<=w){
    ans = max(ans, calc_ans(w-weights[n],n-1) + values[n]);
  }
  dp[w][n]=ans;
  return ans;
}

int main(){
  int t;
  cin >>t;
  while(t--){
    int w, n;
    cin >>w>>n;
    int i;
    for(i=0;i<n;i++)
      cin >>weights[i]>>values[i];
    init_dp(w,n);
    int j;
    cout <<"Hey stupid robber, you can get "<<calc_ans(w,n-1)<<"."<<endl;
  }
  return 0;
}
