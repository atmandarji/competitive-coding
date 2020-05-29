// https://www.codechef.com/problems/DELISH
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >>t;
  while(t--){
    int n,i,j;
    cin>>n;
    vector<long long> arr(n),lmax(n),rmin(n),rmax(n),lmin(n);
    for(i=0;i<n;i++){
      cin >>arr[i];
    }
    lmax[0]=arr[0];
    for(i=1;i<n;i++){
      long long prev = 0;
      if(lmax[i-1]>0)
        prev = lmax[i-1];
      lmax[i] = prev + arr[i];
    }
    lmin[0]=arr[0];
    for(i=1;i<n;i++){
      long long prev = 0;
      if(lmin[i-1]<0)
        prev = lmin[i-1];
      lmin[i] = prev + arr[i];
    }
    rmin[n-1]=arr[n-1];
    for(i=n-2;i>=0;i--){
      long long prev = 0;
      if(rmin[i+1]<0)
        prev = rmin[i+1];
      rmin[i] = prev + arr[i];
    }
    rmax[n-1]=arr[n-1];
    for(i=n-2;i>=0;i--){
      long long prev = 0;
      if(rmax[i+1]>0)
        prev = rmax[i+1];
      rmax[i] = prev + arr[i];
    }
    for(i=1;i<n;i++){
      lmax[i] = max(lmax[i], lmax[i-1]);
      lmin[i] = min(lmin[i], lmin[i-1]);
    }
    for(i=n-2;i>=0;i--){
      rmax[i] = max(rmax[i], rmax[i+1]);
      rmin[i] = min(rmin[i], rmin[i+1]);
    }
    long long ans=0;
    for(i=0;i<n-1;i++){
      ans = max(ans, abs(lmax[i] - rmin[i+1]));
      ans = max(ans, abs(lmin[i] - rmax[i+1]));
    }
    cout <<ans<<endl;
  }
  return 0;
}
