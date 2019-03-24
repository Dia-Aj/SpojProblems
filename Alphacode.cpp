#include<bits/stdc++.h>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
#define init_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string str;
vector<ll> dp;

ll decode(int ind) {
	if (dp[ind] != -1) return dp[ind];
	ll result;
	if (str[ind] == '0') result = 0;
	else if (ind >= str.size() - 1) result = 1;
	else if (str[ind] <= '2' && str[ind + 1] == '0') result = decode(ind + 2);
	else if (str[ind] <= '2' && str[ind + 2] == '0' && ind + 2 < str.size())
		result = decode(ind + 1);
	else if ((str[ind] <= '2' && str[ind + 1] <= '6') ||
		(str[ind] == '1' && str[ind + 1] <= '9') &&
		ind + 1 < str.size())
		result = decode(ind + 1) + decode(ind + 2);
	else
		result = decode(ind + 1);

	dp[ind] = result;
	return result;
}

int main() {
	init_io
		cin >> str;
	while (str != "0") {
		dp.resize(str.size() + 5, -1);
		ll value = decode(0);
		cout << value << endl;
		//DEBUG(value)
		cin >> str;
		dp.clear();
	}

	return 0;
}
