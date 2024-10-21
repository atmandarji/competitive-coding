// https://www.spoj.com/problems/SQRBR/
#include<bits/stdc++.h>
using namespace std;

long long dp[40][40];
bool open_bk[40];
string str;

void init_dp(){
  int i,j;
  for(i=0;i<40;i++){
    open_bk[i] = false;
    for(j=0;j<40;j++){
      dp[i][j]=-1;
    }
  }
}

bool is_valid(int e){
  return !open_bk[e];
}

long long calc_ans(int s,int e){
  if(s>=e) return 1;
  if(dp[s][e]!=-1) return dp[s][e];

  int i,j;
  long long ans = 0;
  for(i=s+1;i<=e;i+=2){
    if(is_valid(i)){
      ans += calc_ans(s+1,i-1) * calc_ans(i+1,e);
    }
  }
  dp[s][e] = ans;
  return ans;
}

int main(){
  int t;
  cin >>t;
  while(t--){
    init_dp();
    int n,k,i;
    cin >>n>>k;
    for(i=0;i<k;i++){
      int temp;
      cin >>temp;
      open_bk[temp-1]=true;
    }
    calc_ans(0,(2*n)-1);
    cout <<dp[0][(2*n)-1]<<endl;
  }
  return 0;
}
