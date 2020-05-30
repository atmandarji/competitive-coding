// https://codeforces.com/contest/455/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N=100001;
  long long n,i;
  cin >>n;
  vector<long long> dp(N);
  vector<long long> freq(N,0);
  for(i=0;i<n;i++){
    int t;
    cin >>t;
    freq[t]++;
  }
  dp[0]=0;
  dp[1]=freq[1];
  for(i=2;i<N;i++){
    dp[i]=dp[i-1];
    if(freq[i-1]>0)
      dp[i]=max(dp[i],dp[i-2]+freq[i]*i);
    else
      dp[i]+=freq[i]*i;
  }
  cout <<dp[N-1]<<endl;
  return 0;
}
