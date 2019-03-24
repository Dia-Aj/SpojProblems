#include<iostream>
#include<vector>
using namespace std;
vector<int> primes, factors;

void seive(int s) {
	vector<bool> mark(s, 1);
	for (int i = 2; i*i < s; i++) {
		if (mark[i]) {
			for (int j = i * 2; j < s; j += i)
				mark[j] = 0;
			primes.push_back(i);
		}
	}
}

int main() {
	seive(500000);
	int count = 0;
	for (int i = 2; i < 1e5; i++) {
		int number = i, c = 0;
		for (int j = 0; j < primes.size(); j++)
			if (number%primes[j] == 0) {
				while (number%primes[j] == 0) number /= primes[j];
				c++;
			}
		if (number == 1 && c >= 3) {
			factors.push_back(i);
			count++;
		}
		if (count >= 1000) break;
	}

	int n, x;
	cin >> n;

	while (n--) {
		cin >> x;
		cout << factors[x - 1] << endl;
	}

	system("pause");

	return 0;
}