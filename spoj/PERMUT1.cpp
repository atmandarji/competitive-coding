// https://www.spoj.com/problems/PERMUT1/
#include<bits/stdc++.h>
using namespace std;

int main(){
	long long dp[21][200];
	int i,j,k;
	for(i=0;i<21;i++){
		for(j=0;j<200;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	for(i=0;i<21;i++){
		for(j=0;j<=(i*(i - 1))/2;j++){
			if(j>=200) break;
			for(k=0;k<i && j-k>=0;k++){
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	int t;
	cin >>t;
	while(t--){
		int a,b;
		cin >>a>>b;
		cout <<dp[a][b]<<endl;
	}
	return 0;
}
/*

12 0
21 1

123 0
132 1
213 1
231 2
312 2
321 3
*/
