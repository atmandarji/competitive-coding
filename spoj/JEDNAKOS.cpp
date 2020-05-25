// https://www.spoj.com/problems/JEDNAKOS/
#include<bits/stdc++.h>
using namespace std;

int nums[5010];
long long dp[5010][5010];
int num;

long long minn(long long a, long long b){
  if(a<b){
    return a;
  }
  return b;
}

string reduce(string str){
  string r_str = "";
  int i;
  int count=0;
  for(i=0;i<str.size();i++){
    if(str[i]=='0'){
      count++;
      if(count<=3){
        r_str.push_back(str[i]);
      }
    }
    else{
      count=0;
      r_str.push_back(str[i]);
    }
  }
  return r_str;
}

vector<string> split(string str, char sap_char){
  vector<string> ans;
  string curr = "";
  int i, n=str.size();
  for(i=0;i<n;i++){
    if(str[i]==sap_char){
      ans.push_back(curr);
      curr = "";
    }
    else{
      curr.push_back(str[i]);
    }
  }
  if(curr != ""){
    ans.push_back(curr);
  }
  return ans;
}

void init_nums(string arr_str, string num_str){
  int i,n=arr_str.size(),j;
  for(i=0;i<n;i++){
    nums[i] = arr_str[i] - '0';
  }
  num = 0;
  n = num_str.size();
  for(i=0;i<n;i++){
    num = num*10 + num_str[i] - '0';
  }
  for(i=0;i<5010;i++){
    for(j=0;j<5010;j++){
      dp[i][j]=-2;
    }
  }
  dp[0][nums[0]] = 0;
}

long long calc_ans(int e, int n){
  if(dp[e][n]!=-2) return dp[e][n];

  int curr = nums[e];
  int mul = 10;
  int ind = 1;
  long long ans = -1;
  while(curr<n && e-ind>=0){
    long long temp = calc_ans(e-ind, n-curr);
    if(temp!=-1){
      if(ans==-1){
        ans = 1+temp;
      }
      else{
        ans = minn(ans, 1+temp);
      }
    }
    curr = curr + mul*nums[e-ind];
    mul *= 10;
    ind++;
  }
  if(curr==n && e-ind==-1){
    ans=0;
  }
  dp[e][n] = ans;
  return ans;
}

int main(){
  string str;
  cin >>str;
  vector<string> strs = split(str, '=');
  strs[0] = reduce(strs[0]);
  init_nums(strs[0], strs[1]);
  cout <<calc_ans(strs[0].size()-1, num)<<endl;
  return 0;
}
