#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
typedef vector<char> Vchar;

void print_vector(Vchar number) {
	for (int i = 0; i < number.size(); i++)
		cout << number[i];
	cout << endl;
}

bool AllNines(Vchar number, int len) {
	for (int i = 0; i < len; i++)
		if (number[i] != '9')
			return 0;
	return 1;
}

void findNextPlaindrome(Vchar &number, int len) {
	if (AllNines(number, len)) {
		cout << '1';
		for (int n = 1; n < len; n++)
			cout << '0';
		cout << '1' << endl;
		return;
	}

	int mid = len / 2;
	bool leftsmaller = 0;

	int i = mid - 1;
	int j = len % 2 != 0 ? mid + 1 : mid;

	while (i >= 0 && number[i] == number[j]) {
		i--;
		j++;
	}


	if (i < 0 || number[i] < number[j])
		leftsmaller = 1;

	while (i >= 0) {
		number[j] = number[i];
		i--;
		j++;
	}

	if (leftsmaller) {
		if (len % 2 == 0) { //even
			if (number[mid] == '9' && number[mid - 1] == '9') {
				number[mid] = '0';
				number[mid - 1] = '0';
				for (int n = mid - 2; n >= 0; n--) {
					if (number[n] != '9') {
						number[n] = char(int(number[n]) + 1);
						break;
					}
					else {
						number[n] = '0';
					}
				}
			}
			else {
				number[mid - 1] = char(int(number[mid - 1]) + 1);
			}
			for (int n = 0; n < mid; n++)
				number[len - n - 1] = number[n];
		}

		else { //odd
			if (number[mid] == '9') {
				number[mid] = '0';
				for (int n = mid - 1; n >= 0; n--)
					if (number[n] != '9') {
						number[n] = char(int(number[n]) + 1);
						break;
					}
					else {
						number[n] = '0';
					}
			}
			else { number[mid] = char(int(number[mid]) + 1); }

			for (int n = 0; n < mid; n++)
				number[len - n - 1] = number[n];
		}
	}
	print_vector(number);
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		string strnum;
		Vchar number;
		cin >> strnum;
		int len = strnum.size();
		for (int i = 0; i < len; i++)
			number.push_back(strnum[i]);

		findNextPlaindrome(number, len);
	}

	return 0;
}
