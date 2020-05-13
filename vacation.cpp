#include<bits/stdc++.h>
using namespace std;

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
	int N;
	cin>>N;
	vector<int > temp(3), local_dp(3, 0), global_dp(3, 0);

	// output part also started

	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++)
			cin>>temp[j];

		// processng

		for(int k=0;k<3;k++){
			for(int l=0;l<3;l++){
				if(k != l){
					self_max(local_dp[k], global_dp[l]+temp[k]);
				}
			}
		}
		

		global_dp.swap(local_dp);
		// for(int m =0;m<3;m++)
		// 	cout<<global_dp[m]<<" ";
		// cout<<endl;
		local_dp = vector<int>(3, 0);
	}

	int maxVal = *max_element(global_dp.begin(), global_dp.end());
	cout<<maxVal<<endl;
}
