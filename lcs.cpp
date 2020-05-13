#include<bits/stdc++.h>
using namespace std;
#define ll long long


void cc_env(){
	#ifndef ONLINE_JUDGE
		freopen("input", "r", stdin);
		freopen("output", "w", stdout);
		// 
	#endif
}


void self_max(int &a, int b){
	a = max(a, b);
}

int main(){
	cc_env();
	// input part
	string s, t;
	cin>>s;
	cin>>t;

	//processing part
	vector<vector<int> > dp(s.length()+1, vector<int>(t.length()+1, 0));
	for(int i=1;i<=s.length();i++){
		for(int j=1;j<=t.length();j++){
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1] +1;
			else{
				self_max(dp[i][j], dp[i-1][j]);
				self_max(dp[i][j], dp[i][j-1]);
			}
		}
	}

	string ans = "";
	int i = s.length(), j = t.length();
	// cout<<dp[i][j]<<endl;
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i-1][j]) i--;

		else if(dp[i][j] == dp[i][j-1]) j--;

		else{
			ans = s[i-1]+ans;
			i--;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
