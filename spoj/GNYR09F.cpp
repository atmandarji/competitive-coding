// https://www.spoj.com/problems/GNYR09F/
#include<bits/stdc++.h>
using namespace std;

long long minn(long long a, long long b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	long long N = 100;
	long long dp[N+1][N+1][2];
	int i,j,k;
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++){
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	}
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for(i=2;i<=N;i++){
		for(j=0;j<i;j++){
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			if(j==0){
				dp[i][j][1] = dp[i-1][j][0];
			}
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
		}
	}
	long long t;
	cin >>t;
	while(t--){
		long long tn,n,k;
		cin >>tn>>n>>k;
		cout <<tn<<" "<<(dp[n][k][0] + dp[n][k][1])<<endl;
	}
	return 0;
}
