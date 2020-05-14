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



int main() {
	cc_env();
	// input part
	int N;
	cin >> N;
	vector<double> inputArr(N);
	for (int i = 0; i < N; i++)
		cin >> inputArr[i];

	// processing part
	vector<vector<double> > dp(N + 1, vector<double>(N + 1, 0.0));

	// base case
	dp[0][0] = 1.0;
	for (int j = 1; j <= N; j++)
		dp[j][0] = dp[j - 1][0] * (1.0 - inputArr[j - 1]);

	for (int i = 0; i < N + 1; i++) { // turn
		for (int j = 1; j < N + 1; j++) { // number of head
			if (j <= i) {
				dp[i][j] = (dp[i - 1][j - 1] * inputArr[i - 1]) + dp[i - 1][j] * (1.0 - inputArr[i - 1]);
			}
		}
	}

	double ans = 0;
	for (int i = N / 2 + 1; i <= N; i++)
		ans += dp[N][i];
	cout << setprecision(10) << ans << endl;

}
