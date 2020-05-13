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



void self_min(ll &a, ll b){
	a = min({a,b});
}


int main(){
	cc_env();
	// input part;
	int N, W, w, v, V=0;
	cin>>N>>W;

	vector<vector<int> > inputArr(N, vector<int>(2, 0));
	for(int i=0;i<N;i++){
		cin>>inputArr[i][0]>>inputArr[i][1];
		V += inputArr[i][1];

	}

	// deciding size of dp array
	vector<ll> dp(V+1, INT_MAX);
	dp[0] = 0;
	for(int i=0;i<N;i++){
		w = inputArr[i][0];
		v = inputArr[i][1];
		
		// processing
		for(int value_already = V-v; value_already >=0; --value_already){
			// cout<<dp[weight_already+w]<<" "<<dp[weight_already]+v<<endl;
			self_min(dp[value_already+v], (dp[value_already]+w));
		}

		// for(int i=0;i<dp.size();i++)
		// 	cout<<dp[i]<<" ";
		// cout<<endl;

	}
	
	// find max among value array
	int maxVal = 0;
	for(int i=dp.size()-1;i>=0;i--){
		// cout<<dp[i]<<" ";
		if(dp[i] <= W)
			maxVal = max(maxVal, i);
	}
	cout<<endl;
	cout<<maxVal<<endl;
	return 0;

}
