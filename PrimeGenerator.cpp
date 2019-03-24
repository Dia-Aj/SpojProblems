#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int limit, vector<int> &prime, int range) {
	bool mark[limit + 1];
	memset(mark, true, sizeof(mark));

	for (int i = 2; i*i < limit; i++) {
		if (mark[i])
			for (int p = i * 2; p < limit; p += i)
				mark[p] = false;
	}

	for (int i = 2; i < limit; i++)
		if (mark[i]) {
			prime.push_back(i);
			if (i >= range)
				cout << i << "\n";
		}
}

void segmentedSieve(int n, int m) {
	int limit = floor(sqrt(m)) + 1;
	vector<int> prime;
	simpleSieve(limit, prime, n);

	int low = n;
	int high = n + limit;

	while (low < m) {
		if (high >= m)
			high = m;

		bool mark[limit + 1];
		memset(mark, true, sizeof(mark));

		for (int i = 0; i < prime.size(); i++) {
			int lolim = floor(low / prime[i]) * prime[i];
			if (lolim < low)
				lolim += prime[i];

			for (int j = lolim; j < high; j += prime[i])
				mark[j - low] = false;
		}

		for (int i = low; i < high; i++)
			if (mark[i - low] & i != 1) cout << i << "\n";

		low = low + limit;
		high = high + limit;
	}
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n, m;
		cin >> n >> m;
		cout << "\n";
		segmentedSieve(n, m + 1);
	}
	return 0;
}
