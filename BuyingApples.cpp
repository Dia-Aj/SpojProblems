#include<bits/stdc++.h>
using namespace std;
int q, n, k, ans;
int wi[1000], dp[1000][1000];

int rec(int w, int ind) {
	if (w == 0) return 0;
	if (w < 0 || ind == 0) return 1e6;

	int res;
	if (dp[w][ind] != 0) res = dp[w][ind];
	else if (wi[ind] == -1) res = rec(w, ind - 1);
	else
		res = min(wi[ind] + rec(w - ind, ind), rec(w, ind - 1));
	dp[w][ind] = res;
	return res;
}

int main() {
	cin >> q;
	while (q--) {
		cin >> n >> k;
		memset(wi, 0, sizeof(wi)), memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= k; i++) cin >> wi[i];
		int result = rec(k, k);
		if (result >= 1e6) cout << -1 << endl;
		else
			cout << result << endl;
	}
	return 0;
}