// https://community.topcoder.com/stat?c=problem_statement&pm=1259
#include<bits/stdc++.h>
using namespace std;
class ZigZag{
public:
  long long dp[50][2];
  vector<int> nums;
  void init_dp(vector<int> v){
    int i;
    nums = v;
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(i=1;i<50;i++){
      dp[i][0]=-1;
      dp[i][1]=-1;
    }
  }
  long long calc_ans(int n,int inc){
    if(dp[n][inc]!=-1) return dp[n][inc];

    int i;
    long long ans=0;
    for(i=0;i<n;i++){
      if(inc==0){
        if(nums[i]>nums[n]){
          ans = max(ans, calc_ans(i,(inc+1)%2)+1);
        }
      }
      else{
        if(nums[i]<nums[n]){
          ans = max(ans, calc_ans(i,(inc+1)%2)+1);
        }
      }
    }
    dp[n][inc] = ans;
    return ans;
  }
  int longestZigZag(vector<int> v){
    init_dp(v);
    int n=v.size();
    int ans = max(calc_ans(n-1,0), calc_ans(n-1,1));
    return ans;
  }
};

int main(){
  int n,i;
  cin >>n;
  vector<int> v(n);
  for(i=0;i<n;i++){
    cin >>v[i];
  }
  ZigZag zz;
  cout <<zz.longestZigZag(v)<<endl;
}
