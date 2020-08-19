#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,c;
  cin >>t;
  for(c=1;c<=t;c++){
    int k,i,j;
    cin >>k;
    vector<int> v(k);
    for(i=0;i<k;i++){
      cin >>v[i];
    }
    vector<int> arr;
    arr.push_back(v[0]);
    for(i=1;i<k;i++){
      if(arr[arr.size()-1] != v[i])
        arr.push_back(v[i]);
    }
    int n=arr.size(), ans=0;
    bool inc;
    if(n==1)
      ans=0;
    else
      inc=arr[1]>arr[0];
    int count=1;
    for(i=2;i<n;i++){
      if(arr[i]>arr[i-1]){
        if(inc)
          count++;
        else{
          int rounds = (count+1)/4;
          if((count+1)%4)
            rounds++;
          ans += rounds - 1;
          count = 1;
          inc=true;
        }
      }
      else{
        if(!inc)
          count++;
        else{
          int rounds = (count+1)/4;
          if((count+1)%4)
            rounds++;
          ans += rounds - 1;
          count = 1;
          inc=false;
        }
      }
      //cout <<count<<" "<<inc<<" "<<arr[i]<<" "<<arr[i-1]<<endl;
    }
    int rounds = (count+1)/4;
    if((count+1)%4)
      rounds++;
    ans += rounds - 1;
    cout <<"Case #"<<c<<": "<<ans<<endl;
  }
  return 0;
}
