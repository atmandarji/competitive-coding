// https://www.codechef.com/problems/FROGV/
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,p,i,j;
  cin >>n>>k>>p;
  vector<pair<int,int> > arr;
  for(i=0;i<n;i++){
    int t;
    cin >>t;
    arr.push_back(make_pair(t,i));
  }
  sort(arr.begin(),arr.end());
  vector<int> dp(n);
  int group = 0;
  dp[arr[0].second] = group;
  int prev = arr[0].first;
  for(i=1;i<n;i++){
    if(arr[i].first-prev>k){
      group++;
    }
    dp[arr[i].second] = group;
    prev=arr[i].first;
  }
  for(i=0;i<p;i++){
    int a,b;
    cin >>a>>b;
    if(dp[a-1]==dp[b-1]){
      cout <<"Yes"<<endl;
    }
    else{
      cout <<"No"<<endl;
    }
  }
  return 0;
}
