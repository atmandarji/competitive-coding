// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,i;
  long long d;
  cin >>n>>d;
  vector<long long> v(n);
  for(i=0;i<n;i++)
    cin >>v[i];
  long long ans=d;
  for(i=n-1;i>=0;i--)
    ans -= ans%v[i];
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
