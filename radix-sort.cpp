#include <bits/stdc++.h>
using namespace std;

void printarray(const vector<int> &v) {
	for (int i = 0; i < (int) v.size(); ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << v[i];
	}
	cout << "\n";
}

void radix_sort(vector<int> &v) {
	int max_elem = *max_element(v.begin(), v.end());
	int len = v.size();
	vector<int> tmp(len);
	vector<vector<int>> buckets(10);

	int div = 1;
	while (max_elem) {

		for (int i = 0; i < len; ++i) {
			int e = v[i];
			int b = (e / div) % 10;
			assert(0 <= b && b <= 9);
			buckets[b].emplace_back(e);
		}

		int idx = 0;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < (int) buckets[i].size(); ++j) {
				tmp[idx++] = buckets[i][j];
			}
		}

		buckets.assign(10, vector<int>());
		copy(tmp.begin(), tmp.end(), v.begin());
		div *= 10;
		max_elem /= 10;
		printarray(v);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	radix_sort(v);
	return 0;
}