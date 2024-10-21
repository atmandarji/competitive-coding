#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int getIndex(char c){
	return (int)(c - 'a');
}

long long solve(vector<string> strs, string target){
	vector<vector<long long> > freq(strs[0].size(), vector<long long>(26, 0));
	for(int i=0;i<strs.size(); i++){
		for(int j=0; j<strs[i].size(); j++){
			freq[j][getIndex(strs[i][j])]++;
		}
	}

	vector<vector<long long> > dp(target.size(), vector<long long>(strs[0].size(), 0));
	dp[0][0] = freq[0][target[0]-'a'];
	for(int j=1;j<strs[0].size(); j++){
		dp[0][j] = (dp[0][j-1] + freq[j][getIndex(target[0])])%MOD;
	}
	for(int i=1;i<target.size(); i++){
		for(int j=i; j<strs[0].size(); j++){
			dp[i][j] = (dp[i][j-1] + (dp[i-1][j-1]*(freq[j][getIndex(target[i])]%MOD))%MOD )%MOD;
		}
	}
	return dp[target.size()-1][strs[0].size()-1];
}

int main(){
	int n;
	cin >>n;
	vector<string> strs;
	for(int i=0;i<n;i++){
		string st;
		cin >>st;
		strs.push_back(st);
	}
	string target;
	cin >> target;
	cout <<solve(strs, target)<<endl;
	return 0;
}
