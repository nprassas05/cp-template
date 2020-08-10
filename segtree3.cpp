#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using ull = unsigned long long;

string to_string(bool b) {
    return b ? "true" : "false";
}

struct segtree {
	int size;
	vector<int> vals;

	void recalc(int p) {
		vals[p] = vals[p * 2 + 1] | vals[p * 2 + 2];
	}

	void build(vector<int> &elems, int p, int lc, int rc) {
		if (rc - lc == 1) {
            if (lc < (int) elems.size()) {
                vals[p] = elems[lc];
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
		vals.assign(size * 2, 0);
		build(elems, 0, 0, size);
	}

	int calc(int l, int r, int p, int lc, int rc) {
		if (lc >= r || rc <= l) {
			return 0;
		}
		if (l <= lc && rc <= r) {
			return vals[p];
		}

		int m = (lc + rc) / 2;
		return calc(l, r, p * 2 + 1, lc, m) | calc(l, r, p * 2 + 2, m, rc);
	}

	int calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}

	void update(const int idx, const int v, int p, int lc, int rc) {
		int m = (lc + rc) / 2;
		if (rc - lc == 1) {
			vals[p] = v;
			return;
		}
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

	return 0;
}
