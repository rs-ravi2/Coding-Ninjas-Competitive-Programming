#include <bits/stdc++.h>
using namespace std;

bool check(int *a, int n, int k, int count) {
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i] / count;
		if (sum >= k)
			return true;
	}
	return false;
}

int BinarySearch(int *a, int n, int k, int l, int r) {
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(a, n, k, mid)) {
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	return ans;
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//input
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k; int *a = new int[n + 1];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int l = 0, r = a[n - 1];
		int ans = BinarySearch(a, n, k, l, r);
		cout << ans << "\n";
		delete []a;
	}
	return 0;
}
