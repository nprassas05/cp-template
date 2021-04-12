template <typename T>
class graph {
public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    vector<vector<edge>> adj;
    int N;

    graph(int _n) : N(_n) {
        adj.resize(_n);
    }

    void add_edge(int from, int to, T cost = 1) {
        edge e = {from, to, cost};
        adj[from].push_back(e);
    }
};

template<typename T>
void dijkstra(int s, const graph<T> &g, vector<T>&dist, vector<int> &parent) {
    dist.assign(g.N, numeric_limits<T>::max());
    parent.assign(g.N, -1);

    dist[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int u = q.begin()->second;
        q.erase(q.begin());

        for (const auto &e: g.adj[u]) {
            int to = e.to;
            int cost = e.cost;

            if (dist[u] + cost < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[u] + cost;
                parent[to] = u;
                q.insert({dist[to], to});
            }
        }
    }
}
