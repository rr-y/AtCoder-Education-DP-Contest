#include<bits/stdc++.h>
using namespace std;

void cc_env(){
	#ifndef ONLINE_JUDGE
		freopen("input", "r", stdin);
		freopen("output", "w", stdout);
		// 
	#endif
}



void self_min(int &a, int b){
	a = min(a, b);
}

int main(){
	// cc_env();
	int n, k;
	cin>>n>>k;
	vector<int> height(n);
	for(int i=0;i<n;i++)
		cin>>height[i];

	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int j = i+1; j <= i+k; j++){
			if(j < n)
				self_min(dp[j], dp[i]+abs(height[j] - height[i]));
		}
	}

	cout<<dp[n-1]<<endl;
}
