#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct segtree {
	int size;
	vector<pair<int, int>> values;

	void recalc(int p) {
		pair<int, int> lp = values[p * 2 + 1];
		pair<int, int> rp = values[p * 2 + 2];
		if (lp.first < rp.first) {
			values[p] = lp;
		} else if (rp.first < lp.first) {
			values[p] = rp;
		} else {
			values[p] = {lp.first, lp.second + rp.second};
		}
	}

	void build(vector<int> &elems, int p, int lc, int rc) {
		if (rc - lc == 1) {
            if (lc < (int) elems.size()) {
                values[p] = {elems[lc], 1};
            }
			return;
		}
		int m = (lc + rc) / 2;
		build(elems, p * 2 + 1, lc, m);
		build(elems, p * 2 + 2, m, rc);
		recalc(p);
	}

	void build(vector<int> & elems) {
		size = 1;
		while (size < (int) elems.size()) {
			size *= 2;
		}
		values.assign(size * 2, {0, 0});
		build(elems, 0, 0, size);
	}

	pair<int, int> calc(int l, int r, int p, int lc, int rc) {
		if (lc >= r || rc <= l) {
			return {INT_MAX, 0};
		}
		if (l <= lc && rc <= r) {
			return values[p];
		}

		int m = (lc + rc) / 2;
		pair<int, int> lp = calc(l, r, p * 2 + 1, lc, m);
		pair<int, int> rp = calc(l, r, p * 2 + 2, m, rc);
		if (lp.first < rp.first) {
			return lp;
		} else if (rp.first < lp.first) {
			return rp;
		} else {
			return {lp.first, lp.second + rp.second};
		}
	}

	pair<int, int> calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}

	void update(const int idx, const int v, int p, int lc, int rc) {
		if (rc - lc == 1) {
			values[p] = {v, 1};
			return;
		}
		int m = (lc + rc) / 2;
		if (idx < m) {
			update(idx, v, p * 2 + 1, lc, m);
		} else {
			update(idx, v, p * 2 + 2, m, rc);
		}
		recalc(p);
	}

	void update(int idx, int v) {
		update(idx, v, 0, 0, size);
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> elems(n);
	for (int i = 0; i < n; ++i) {
		cin >> elems[i];
	}
	segtree st;
	st.build(elems);

	for (int i = 0; i < m; ++i) {
		int op;
		cin >> op;
		if (op == 1) {
			int idx, v;
			cin >> idx >> v;
			st.update(idx, v);

		} else {
			int l, r;
			cin >> l >> r;
			pair<int, int> pv = st.calc(l, r);
			cout << pv.first << " " << pv.second << "\n";
		}

	}
	return 0;
}

