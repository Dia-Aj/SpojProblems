#include <bits/stdc++.h>
using namespace std;

int T, n, answer;
long long P, A[1001];

int BinarySearch(int left, int right, long long auxSum) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] == auxSum) return 1;
		else if (A[mid] < auxSum) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main() {
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d\n", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld\n", &A[i]);

		scanf("%lld", &P);
		sort(A + 0, A + n);
		answer = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				long long auxSum = P - (A[i] + A[j]);
				if (BinarySearch(j + 1, n, auxSum) == 1)
					answer = 1;
			}
		}
		if (answer == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}