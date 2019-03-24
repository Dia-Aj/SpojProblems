#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef vector<int> vec;
int main() {
	int n, e;
	scanf("%d", &n);
	//f>>n;
	vec v;
	while (n--) {
		scanf("%d", &e);
		//f>>e;
		v.push_back(e);
	}
	int k;
	scanf("%d", &k);
	//f>>k;
	for (int i = 0; i <= v.size() - k; i++) {
		//g<<*max_element(it, it2)<<" ";
		printf("%d ", *max_element(v.begin() + i, v.begin() + k + i));
	}
	return 0;
}