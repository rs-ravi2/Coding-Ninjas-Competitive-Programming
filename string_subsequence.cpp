#include <bits/stdc++.h>
using namespace std;

void subsequence(string ip, string op) {
	if (ip.empty()) {
		cout << op << "\n";
		return;
	}

	subsequence(ip.substr(1), op);
	subsequence(ip.substr(1), op + ip[0]);
}

int main() {
/*
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
*/
	//input
	string ip;
	cin >> ip;
	string op = "";
	subsequence(ip, op);
	return 0;
}
