// https://www.codechef.com/problems/LEPAINT
#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >>t;
  while(t--){
    int n,c,k,i,j,l;
    cin >>n>>c>>k;
    double dp[k][c],exp[n+1];
    double fraq=1.0/(2*c+0.0);
    for(i=0;i<c;i++){
      dp[0][i]=fraq;
    }
    dp[0][1]+=(0.5);
    for(i=1;i<k;i++){
      for(j=0;j<c;j++)
        dp[i][j]=dp[i-1][j]*0.5;
      for(j=0;j<c;j++){
        for(l=0;l<c;l++){
          int prod=(j*l)%c;
          dp[i][prod]+=(fraq*dp[i-1][j]);
        }
      }
    }
    exp[0]=1;
    for(i=0;i<k;i++){
      exp[i+1]=0.0;
      for(j=0;j<c;j++){
        exp[i+1]+=((j+0.0)*dp[i][j]);
      }
    }
    vector<int> v(n+1,0);
    for(i=0;i<k;i++){
      int a,b;
      cin >>a>>b;
      for(j=a;j<=b;j++)
        v[j]++;
    }
    double ans=0.0;
    for(i=1;i<=n;i++)
      ans+=exp[v[i]];
    printf("%.7f\n",ans);
  }
  return 0;
}
