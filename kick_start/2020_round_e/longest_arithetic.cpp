// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed
#include<bits/stdc++.h>
using namespace std;

void solve(){
  int n,i;
  cin >>n;
  vector<int> v(n);
  for(i=0;i<n;i++){
    cin >>v[i];
  }
  int prev=v[1]-v[0];
  int count=2,mx=2;
  for(i=2;i<n;i++){
    if(v[i]-v[i-1]==prev){
      count++;
      mx=max(mx,count);
    }
    else{
      count=2;
      prev=v[i]-v[i-1];
      mx=max(mx,count);
    }
  }
  cout <<mx<<endl;;
}

int main() {
  int t,i;
  cin >>t;
  for(i=1;i<=t;i++){
    cout <<"Case #"<<i<<": ";
    solve();
  }
}
