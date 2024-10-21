// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc
#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;

void solve(){
  string s;
  int i;
  cin>>s;
  stack<int> st;
  long long mul=1;
  st.push(mul);
  long long r=0,d=0;
  for(i=0;i<s.size();i++){
    if(s[i]=='E')
      r=(r+mul)%MOD;
    else if(s[i]=='W')
      r=(r-mul+MOD)%MOD;
    else if(s[i]=='N')
      d=(d-mul+MOD)%MOD;
    else if(s[i]=='S')
      d=(d+mul)%MOD;
    else{
      if(s[i]>='1' && s[i]<='9'){
        mul = (mul * int(s[i]-'0'))%MOD;
        st.push(mul);
      }
      else if(s[i]==')'){
        st.pop();
        mul = st.top();
      }
    }
  }
  cout <<r+1<<" "<<d+1;
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
