/*
Asked in BookMyShow

https://i.imgur.com/bfwOY7c.png

Throttling Gateway – given the arrival time of the packets and the number of packets if the number of
packets were more than 3 discard the packets and at given any 10 seconds slot the packets must not exceed
20 and similarly for 60 seconds the packets must not exceed 60. Return the count of discarded packets.

Sample:
  Input
    21
    1 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6 6 7 7
  Output:
    2
*/

#include <bits/stdc++.h>
using namespace std;
int droppedRequests(vector<int> arr) {
    int i,j,k,l,n=arr.size();
    int ans=0;
    i=0;
    j=0;
    k=0;
    l=0;
    while(i<n){
        while(arr[i]!=arr[l])
          l++;
        if(i-l+1>3){
            ans++;
            i++;
            continue;
        }
        while(arr[i]-arr[j]+1>10){
            j++;
        }
        if(i-j+1>20){
            ans++;
            i++;
            continue;
        }
        while(arr[i]-arr[k]+1>60){
            k++;
        }
        if(i-k+1>60){
            ans++;
        }
        i++;
    }
    return ans;
}

int main()
{
    int n,i;
    cin >>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
      cin >>v[i];
    cout <<droppedRequests(v)<<endl;
}
