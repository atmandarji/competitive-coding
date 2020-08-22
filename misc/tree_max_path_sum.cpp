#include <bits/stdc++.h> 
using namespace std;

long long calc_ans(int node, vector<int> vals,
                   vector<vector<int> > &adj,
                   long long &ans, int par=-1){
  vector<long long> ch_ans;
  for(int i=0;i<adj[node].size();i++){
    if(adj[node][i]==par) continue;

    ch_ans.push_back(
      calc_ans(adj[node][i], vals, adj, ans, node)
    );
  }
  long long ret = vals[node];
  if(ch_ans.size()>0){
    sort(ch_ans.begin(), ch_ans.end());
    if(ch_ans[ch_ans.size()-1] > 0) ret+=ch_ans[ch_ans.size()-1];
    if(ch_ans.size() > 1)
      ans = max(ans, ret+ch_ans[ch_ans.size()-2]);
  }
  ans = max(ans, ret);
  return ret;
}

int main(){
  int t;
  cin >>t;
  while(t--){
    int n;
    cin >>n;
    vector<int> values(n);
    for(int i=0;i<n;i++)
      cin >>values[i];
    vector<vector<int> > adj(n);
    for(int i=0;i<n-1;i++){
      int a,b;
      cin >>a>>b;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    long long ans=0;
    calc_ans(0, values, adj, ans);
    cout <<ans<<endl;
  }
  return 0;
}
