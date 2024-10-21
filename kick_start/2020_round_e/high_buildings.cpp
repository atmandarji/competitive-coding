// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bef73
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,a,b,c,i;
  cin >>n>>a>>b>>c;
  if(n==1){
    if(a==1 && b==1 && c==1){
      cout <<1<<endl;
    }
    else{
      cout <<"IMPOSSIBLE"<<endl;
    }
    return;
  }
  if(a+b-c>n && n>1){
    cout <<"IMPOSSIBLE"<<endl;
    return;
  }
  int r_g=a-1, l_g=b-1;
  if(r_g==0 && l_g==0 && n>1){
    cout <<"IMPOSSIBLE"<<endl;
    return;
  }
  vector<int> ans(n,1);
  int sp=2;
  if(n==2) sp=1;
  for(i=0;i<a-c;i++){
    ans[i]=sp;
  }
  for(i=n-1;i>n-1-(b-c);i--){
    ans[i]=sp;
  }
  if(a-c==0){
    for(i=0;i<c-1;i++)
      ans[i]=n;
    if(b-c==0)
      ans[n-1]=n;
    else
      ans[c-1]=n;
  }
  else if(b-c==0){
    for(i=n-1;i>n-1-c;i--)
      ans[i]=n;
  }
  else{
    for(i=a-c;i<a;i++)
      ans[i]=n;
  }
  for(i=0;i<n;i++)
    cout <<ans[i]<<" ";
  cout <<endl;
}

int main() {
  int t,i;
  cin >>t;
  for(i=1;i<=t;i++){
    cout <<"Case #"<<i<<": ";
    solve();
  }
}
