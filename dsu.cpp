class dsu {
    vector<int> ids = {};

    public:
    dsu(int n) : ids(n) {
        iota(ids.begin(), ids.end(), 0);
    }
    int find(int i) {
        if (ids[i] == i) return i;
        return ids[i] = find(ids[i]);
    }
    bool connected(int l, int r) {
        return find(l) == find(r);
    }
    void connect(int l, int r) {
        int x = find(l), y = find(r);
        ids[y] = ids[x] = min(x, y);
    }
};