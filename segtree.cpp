template<typename T>
struct segtree {
	int n;
	vector<T> tree;

    const T dummy_val = 0;

    T unite(T left_val, T right_val) {
        return std::gcd(left_val, right_val);
    }
	void recalc(int p) {
		tree[p] = unite(tree[p * 2], tree[p * 2 + 1]);
	}

	void build(const vector<T> & elems) {
		this->n = 1;

		while (n < (int) elems.size()) {
			n *= 2;
		}

        tree.assign(2 * n, dummy_val);
        for (int i = 0; i < (int) elems.size(); ++i) {
            tree[n + i] = elems[i];
        }
        for (int i = n - 1; i >= 1; --i) {
            recalc(i);
        }
	}

	T query(int qlow, int qhigh, int rlow, int rhigh, int tree_idx) {
         // inside
        if (qlow <= rlow && rhigh <= qhigh) {
            return tree[tree_idx];
        }
        // disjoint
        if (rlow > qhigh || rhigh < qlow) {
            return dummy_val;
        }

        int left_child = tree_idx * 2;
        int right_child = tree_idx * 2 + 1;
        int mid = (rlow + rhigh) / 2;
 
        return unite(query(qlow, qhigh, rlow, mid, left_child),
                     query(qlow, qhigh, mid + 1, rhigh, right_child));
	}

	T query(const int low, const int high) {
        return query(low, high, 0, this->n - 1, 1);
    }

	void update(int idx, int val) {
        tree[n + idx] = val;
        for (int p = (n + idx) / 2; p > 0; p /= 2) {
            recalc(p);
        }
	}
};
