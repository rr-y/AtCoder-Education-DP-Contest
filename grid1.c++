#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


void cc_env() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//
#endif
}



int main() {
	// cc_env();
	// input part
	int H, W;
	cin >> H >> W;
	vector<vector<char> > inputArr(H, vector<char>(W));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> inputArr[i][j];
	}

	// processing
	// dp[i][j] -> no of ways to reach at (i, j)
	vector<vector<int> > dp(H, vector<int>(W, 0));
	dp[0][0] = 1;

	// Base Cases
	for (int i = 1; i < H; i++) {
		if (inputArr[i][0] == '#')
			dp[i][0] = 0;
		else
			dp[i][0] = dp[i - 1][0];
	}

	// Base Case 2
	for (int j = 1; j < W; j++) {
		if (inputArr[0][j] == '#')
			dp[0][j] = 0;
		else
			dp[0][j] = dp[0][j - 1];
	}

	// Solution building
	for (int i = 1; i < H; i++) {
		for (int j = 1; j < W; j++) {
			if (inputArr[i][j] == '#')
				dp[i][j] = 0;
			else
				dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}

	cout << dp[H - 1][W - 1] << endl;

}
