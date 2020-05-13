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



void self_max(ll &a, ll b){
	a = max(a, b);
}


int main(){
	cc_env();
	// input part;
	int N, W, w, v;
	cin>>N>>W;

	// maintaining output array
	vector<ll> dp(W+1, 0);
	for(int i=0;i<N;i++){
		cin>>w>>v;

		// processing
		for(int weight_already = W-w; weight_already >=0; --weight_already){
			// cout<<dp[weight_already+w]<<" "<<dp[weight_already]+v<<endl;
			self_max(dp[weight_already+w], dp[weight_already]+v);
		}

		// for(int i=0;i<dp.size();i++)
		// 	cout<<dp[i]<<" ";
		// cout<<endl;

	}
	// find max among weight array
	ll maxVal = *max_element(dp.begin(), dp.end());
	cout<<maxVal<<endl;
	return 0;

}
