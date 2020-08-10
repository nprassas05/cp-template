class rmq_segtree {
private:
	size_t tree_size;
	size_t elems_size;
	
	vector<int> elems;
	vector<int> tree;
	
	void build_tree(int low, int high, int idx) {
		assert(low <= high);
		assert(0 <= idx && idx < tree.size());
		
		if (low == high) {
			tree[idx] = low;
			return;
		}
		
		int mid = low + (high - low) / 2;
		int left_child = idx * 2 + 1;
		int right_child = idx * 2 + 2;
		
		build_tree(low, mid, left_child);
		build_tree(mid + 1, high, right_child);
		
		if (elems[tree[left_child]] > elems[tree[right_child]]) {
			tree[idx] = tree[left_child];
		} else {
			tree[idx] = tree[right_child];
		}
	}
	
	/*
	 * Answer the range maximum query in the inclusive range [i,  j]
	 * [i, j] the range we are querying
	 * [low, high] the current index range we are in
	 * idx the index that corresponds to the range we are currently in
	 */
	int rmq(int i, int j, int low, int high, int idx) {
		assert(i <= j);
		assert(low <= high);
		assert(0 <= idx && idx <= tree.size());
		
		if (i == j) {
			return i;
		}
		
		// current range is completely outside the query range
		// return invalid result
		if (high < i || low > j) {
			return -1;
		}
		
		
		// current range is completely inside the query range
		// this seems to cover the case of when low == high
		if (i <= low && high <= j) {
			return tree[idx];
		}
		
		int mid = low + (high - low) / 2;
		int left_child = idx * 2 + 1;
		int right_child = idx * 2 + 2;
		
		// if we get here,  it means that part of our current range
		// contains part of the range of the query, but some of
		// our range is outside the query, so we need to further trim
		// it down.
		int left_result = rmq(i, j, low, mid, left_child);
		int right_result = rmq(i, j, mid + 1, high, right_child);
		
		assert((0 <= left_result && left_result < elems_size) || left_result ==  -1);
		assert((0 <= right_result && right_result < elems_size) || right_result == -1);
		
		if (left_result == -1) {
			return right_result;
		}
		if (right_result == -1) {
			return left_result;
		}
		if (elems[left_result] > elems[right_result]) {
			return left_result;
		} else {
			return right_result;
		}
	}
public:
	rmq_segtree(const vector<int> &vec) {
		elems = vec;
		elems_size = elems.size();
		tree.resize(4 * elems_size);
		tree_size = 4 * elems_size;
		build_tree(0, elems_size - 1, 0);
	}
	
	int max_in_range(int i, int j) {
		return elems[rmq(i, j)];
	}
	
	int rmq(int i, int j) {
		assert(i <= j);
		
		return rmq(i, j, 0, elems_size - 1, 0);
	}
};