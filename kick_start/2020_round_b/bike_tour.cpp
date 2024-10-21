// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,i;
  cin >>n;
  vector<int> v(n);
  for(i=0;i<n;i++)
    cin >>v[i];
  long long ans=0;
  for(i=1;i<n-1;i++)
    if(v[i]>v[i+1] && v[i]>v[i-1]) ans++;
  cout <<ans;
}

int main(){
  int t;
  cin >>t;
  for(int i=1;i<=t;i++){
    cout <<"Case #"<<i<<": ";
    solve();
    cout <<endl;
  }
  return 0;
}
