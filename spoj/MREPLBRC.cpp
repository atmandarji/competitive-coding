// https://www.spoj.com/problems/MREPLBRC/
#include<bits/stdc++.h>
using namespace std;

long long dp[201][201];
int md = 100000;
string str;
bool f;

void init_dp(){
  f=false;
  int i,j;
  for(i=0;i<200;i++){
    for(j=0;j<200;j++){
      dp[i][j]=-1;
    }
  }
}

bool is_valid(int s, int e){
  bool ans = false;
  ans = ans || (str[s]=='(' && str[e]==')');
  ans = ans || (str[s]=='{' && str[e]=='}');
  ans = ans || (str[s]=='[' && str[e]==']');

  ans = ans || (str[s]=='?' && str[e]==')');
  ans = ans || (str[s]=='?' && str[e]=='}');
  ans = ans || (str[s]=='?' && str[e]==']');

  ans = ans || (str[s]=='(' && str[e]=='?');
  ans = ans || (str[s]=='{' && str[e]=='?');
  ans = ans || (str[s]=='[' && str[e]=='?');
  return ans;
}

bool is_both_unknown(int s,int e){
  return str[s]=='?' && str[e]=='?';
}

long long calc_ans(int s,int e){
  if(s>=e) return 1;
  if(dp[s][e]!=-1) return dp[s][e];

  int i,j;
  long long ans = 0;
  for(i=s+1;i<=e;i+=2){
    if(is_valid(s,i)){
      ans += calc_ans(s+1,i-1) * calc_ans(i+1,e);
      if(ans > md){
        f=true;
        ans = ans%md;
      }
    }
    else if(is_both_unknown(s,i)){
      ans += 3 * calc_ans(s+1,i-1) * calc_ans(i+1,e);
      if(ans > md){
        f=true;
        ans = ans%md;
      }
    }
  }
  dp[s][e] = ans%md;
  return ans;
}

int main(){
  int n;
  cin >>n>>str;
  init_dp();
  calc_ans(0,n-1);
  // If the answer is less then 5 digits then,
  // We need to add more 0s.
  printf(f?"%05d\n":"%d\n",dp[0][n-1]);
  return 0;
}
