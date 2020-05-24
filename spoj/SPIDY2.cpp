// https://www.codechef.com/problems/SPIDY2
#include<bits/stdc++.h>
using namespace std;

long long minn(long long a, long long b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	long long n,i,j,k;
	cin >>n;
	long long arr[n];
	for(i=0;i<n;i++){
		cin >>arr[i];
	}
	long long dp[n];
	dp[0]=0;
	for(i=1;i<n;i++){
		long long min = -1;
		for(j=1; i-j>=0; j*=2){
			long long cost = dp[i-j] + abs(arr[i] - arr[i-j]);
			if(min==-1){
				min = cost;
			}
			else{
				min = minn(min, cost);
			}
		}
		dp[i] = min;
	}
	cout <<dp[n-1]<<endl;
	return 0;
}