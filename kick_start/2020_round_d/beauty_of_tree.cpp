// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int> > &adj,
         vector<int> &path, vector<long long> &ans,
         int curr, int par, int skip){
  path[curr]=node;
  curr++;
  int i;
  for(i=0;i<adj[node].size();i++){
    if(adj[node][i] == par) continue;

    dfs(adj[node][i], adj, path, ans, curr, node, skip);
  }
  ans[node]++;
  if(curr-skip-1>=0){
    ans[path[curr-skip-1]]+=ans[node];
  }
  path[curr]=-1;
  curr--;
}

void solve(){
  int n,a,b,i;
  cin >>n>>a>>b;
  vector<vector<int> > adj(n);
  for(i=1;i<n;i++){
    int p; cin >>p;
    adj[p-1].push_back(i);
    adj[i].push_back(p-1);
  }
  vector<int> path(n,-1);
  vector<long long> vis_a(n, 0), vis_b(n, 0);
  dfs(0, adj, path, vis_a, 0, -1, a);
  dfs(0, adj, path, vis_b, 0, -1, b);
  double ans;
  for(i=0;i<n;i++){
    double p1 = (vis_a[i]+0.0)/(n+0.0);
    double p2 = (vis_b[i]+0.0)/(n+0.0);
    double tot = p1 + p2 - p1*p2;
    ans += tot;
  }
  printf("%.7g\n", ans);
}

int main() {
  int t,i;
  cin >>t;
  for(i=1;i<=t;i++){
    cout <<"Case #"<<i<<": ";
    solve();
  }
}
