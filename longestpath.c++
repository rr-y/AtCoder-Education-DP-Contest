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

void dfs(int st, vector<int> &visited, vector<int> &inDegree, vector<int> &distance, vector<vector<int> > &graph) {
	if (visited[st] == 0) {
		// cout << st << " " << endl;
		visited[st] = 1;
		for (auto e : graph[st]) {
			distance[e] = max(distance[e], distance[st] + 1);
			--inDegree[e];
			if (inDegree[e] == 0)
				dfs(e, visited, inDegree, distance, graph);
		}
	}

	// for (auto e : distance)
	// 	cout << e << " ";
	// cout << endl;
}


int main() {
	cc_env();
	// input part
	int N, M, n1, n2;
	cin >> N >> M;

	vector<vector<int> > graph(N + 1);
	vector<int> inDegree(N + 1, 0), visited(N + 1, 0), distance(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		++inDegree[n2];
	}

	// for (auto e : inDegree)
	// 	cout << e << " ";
	// cout << endl;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0 && inDegree[i] == 0)
			dfs(i, visited, inDegree, distance, graph);
	}

	int maxVal = *max_element(distance.begin(), distance.end());
	cout << maxVal << endl;
}
