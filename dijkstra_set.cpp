template<typename T>
void dijkstra(int s, const vector<vector<pair<int, T>>> &adj,
              vector<T> &dist, vector<int> &parent) {
    int n = (int) adj.size();
    dist.assign(n, numeric_limits<T>::max());
    parent.assign(n, -1);

    dist[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int u = q.begin()->second;
        q.erase(q.begin());

        for (const auto &e: adj[u]) {
            int to = e.first;
            int cost = e.second;

            if (dist[u] + cost < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[u] + cost;
                parent[to] = u;
                q.insert({dist[to], to});
            }
        }
    }
}

