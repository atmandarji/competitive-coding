// https://codeforces.com/group/FLVn1Sc504/contest/274506/problem/H
#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m,i,j;
  cin >>n;
  vector<long long> v(n+1);
  v[0]=0;
  for(i=1;i<=n;i++){
    cin >>v[i];
    v[i]+=v[i-1];
  }
  cin >>m;
  vector<long long> ships(n+1,0), dp(n+1,0), finish(n+1,0);
  for(i=0;i<m;i++){
    long long b,d;
    cin >>b>>d;
    ships[b]=d;
  }
  int s_pt=-1;
  int ship_ind=0;
  long long len=-1;
  for(i=1;i<=n;i++){
    dp[i]=dp[i-1];
    finish[i]=finish[i-1];
    if(ships[i]!=0){
      s_pt=i;
      len=ships[i];
      ship_ind++;
    }
    if(s_pt!=-1 && i-s_pt<len){
      if(i-len>=0 && finish[i-len]==ship_ind-1){
        long long prev=dp[i-len];
        long long fishes=v[i]-v[i-len];
        if(dp[i]<=prev+fishes){
          dp[i]=prev+fishes;
          finish[i]=ship_ind;
        }
      }
    }
  }
  cout <<dp[n]<<endl;
  return 0;
}