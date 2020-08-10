#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7 + 5;
const int max_n = 1e5 + 5;

bool visited[max_n];
int parent[max_n];
int low[max_n];
int disc[max_n];
vector<vector<int>> g;
int n, m;
int gtime;
stack<pair<int, int>> st;
vector<set<int>> components;

bool is_root(int u) {
	return parent[u] == -1;
}

void add_component(pair<int, int> target) {
	if (st.empty()) {
		return;
	}

	set<int> comp;
	while (!st.empty()) {
		pair<int, int> e = st.top();
		st.pop();
		comp.insert(e.first);
		comp.insert(e.second);
		if (e == target) {
			break;
		}
	}
	components.emplace_back(comp);
}

void dfs(int u) {
	int children = 0;
	visited[u] = true;
	disc[u] = low[u] = ++gtime;

	for (int v: g[u]) {
		if (!visited[v]) {
			++children;
			parent[v] = u;
			pair<int, int> curr_e = make_pair(u, v);

			st.push(curr_e);
			dfs(v);
			low[u] = min(low[u], low[v]);

			if (is_root(u) && children > 1) {
				add_component(curr_e);
			}
			if (!is_root(u) && low[v] >= disc[u]) {
				add_component(curr_e);
			}

		} else if (parent[u] != v && disc[v] < low[u]) {
			low[u] = disc[v];
			st.push(make_pair(u, v));
		}
	}
}

void solve() {
	memset(visited, 0, sizeof(visited));
	fill(parent, parent + n, -1);
	fill(disc, disc + n, inf);
	fill(low, low + n, inf);
	gtime = 0;

	pair<int, int> fake = make_pair(-1, -1);

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
			add_component(fake);
		}
	}

	// find bi-connected components with even and odd numbers of vertices in them
	int odd = 0;
	int even = 0;

	for (const auto &c: components) {
		if (c.size() & 1) {
			++odd;
		} else {
			++even;
		}
	}

	cout << odd << " " << even << "\n";

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