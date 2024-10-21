// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,c;
  cin >>t;
  for(c=1;c<=t;c++){
    int n,i,j;
    cin >>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
      cin >>v[i];
    }
    int maxx = INT_MIN;
    int ans = 0;
    for(i=0;i<n;i++){
      if(v[i]>maxx && (i==n-1 || v[i]>v[i+1])){
        ans++;
      }
      maxx = max(maxx,v[i]);
    }
    cout <<"Case #"<<c<<": "<<ans<<endl;
  }
  return 0;
}
