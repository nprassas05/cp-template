#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7 + 5;
const int max_n = 1e5 + 5;

bool visited[max_n];
int parent[max_n];
int low[max_n];
int disc[max_n];
vector<vector<int>> g;
vector<pair<int, int>> br;
vector<int> art;
int n, m;
int gtime;

bool is_root(int u) {
	return parent[u] == -1;
}

void dfs(int u) {
	int children = 0;
	visited[u] = true;
	disc[u] = low[u] = ++gtime;

	bool is_art = false;

	for (int v: g[u]) {
		if (!visited[v]) {
			++children;
			parent[v] = u;
			//cout << "about to visit " << v << " who is a child of " << u << "\n";
			dfs(v);
			low[u] = min(low[u], low[v]);

			if (!is_art) {
				if (is_root(u) && children > 1) {
					is_art = true;
					art.emplace_back(u);
				}
				if (!is_root(u) && low[v] >= disc[u]) {
					//cout << u << " is an articulation vertex\n";
					is_art = true;
					art.emplace_back(u);
				}
			}
			
			if (low[v] > low[u]) {
				if (u < v) {
					br.emplace_back(make_pair(u, v));
				} else {
					br.emplace_back(make_pair(v, u));
				}
			}

		} else if (parent[u] != v) {
			low[u] = min(low[u], disc[v]);
		}
	}
}

void solve() {
	memset(visited, 0, sizeof(visited));
	fill(parent, parent + n, -1);
	fill(disc, disc + n, inf);
	fill(low, low + n, inf);
	gtime = 0;

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	sort(art.begin(), art.end());
	sort(br.begin(), br.end());

	cout << art.size() << "\n";
	for (int i = 0; i < (int) art.size(); ++i) {
		if (i > 0) cout << " ";
		cout << art[i];
	}
	cout << "\n";

	cout << br.size() << "\n";
	for (int i = 0; i < (int) br.size(); ++i) {
		cout << br[i].first << " " << br[i].second << "\n";
	}
}


int main() {
	cin >> n >> m;
	g.resize(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	solve();
	
	return 0;
}
