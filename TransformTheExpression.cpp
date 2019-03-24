#include <bits/stdc++.h>
#include <string>
using namespace std;

char expr[400], S1[400], S2[400];
int ind1 = 0, ind2 = 0;

void push(char Stack[], int &ind, char val) { ++ind; Stack[ind] = val; }
void pop(char Stack[], int &ind) { Stack[ind] = 0; ind--; }
char top(char Stack[], int &ind) { return(Stack[ind]); }
bool isEmpty(int ind) { return(ind == 0); }
// +, -, *, /, ^
int main() {
	int q; cin >> q;
	for (int n = 0; n < q; n++) {
		cin >> expr;
		string rpnExpr;
		for (int i = 0; i < strlen(expr); i++) {
			if (expr[i] == '(') push(S1, ind1, expr[i]);
			else if (expr[i] == ')') {
				pop(S1, ind1);
				rpnExpr += top(S2, ind2);
				pop(S2, ind2);
			}
			else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' ||
				expr[i] == '/' || expr[i] == '^') {
				push(S2, ind2, expr[i]);
			}
			else rpnExpr += expr[i];
		}
		cout << rpnExpr << endl;
	}
	return 0;
}