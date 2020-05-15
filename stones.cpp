#include<bits/stdc++.h>
using namespace std;
#define ll long long


void cc_env() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
#endif
}

int recursive(int k, vector<int> &inputArr, vector<int> &dp) {
	// base case

	if (dp[k] != -1)
		return dp[k];

	// recursive case
	int ans = 0;
	for (int i = 0; i < (int)inputArr.size(); i++) {
		if (k - inputArr[i] < 0)
			break;
		bool temp = recursive(k - inputArr[i], inputArr, dp);
		ans = 1 - temp;
		if (ans == 1)
			break;
	}
	dp[k] = ans;
	return dp[k];
}


void iterative(int K, vector<int> &inputArr, vector<int> &dp) {
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < (int)inputArr.size(); j++) {
			if (i - inputArr[j] < 0) break;

			else if (dp[i - inputArr[j]] == false) {
				dp[i] = true;
				break;
			}
		}
	}
}



int main() {
	// cc_env();
	// input part
	int N, K;
	cin >> N >> K;

	vector<int> inputArr(N);
	for (int i = 0; i < N; i++)
		cin >> inputArr[i];

	// procssing part;
	sort(inputArr.begin(), inputArr.end());
	vector<int> dp(K + 1, -1);
	dp[0] = 0;
	recursive(K, inputArr, dp);
	string ans = dp[K] == 1 ? "First" : "Second";
	cout << ans << endl;
	return 0;
}