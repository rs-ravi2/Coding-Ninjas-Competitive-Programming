#include <bits/stdc++.h>
using namespace std;
int main() {

// #ifndef ONLINE_JUDGE
// 	// for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif

	//input
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<pair<int, int>> intervals;
		for (int i = 0; i < n; i++)
		{
			int start, end;
			cin >> start >> end;
			intervals.push_back(make_pair(start, end));
		}
		sort(intervals.begin(), intervals.end());
		int a[m + 1];
		for (int i = 0; i < m; ++i)
			cin >> a[i];

		for (int i = 0; i < m; ++i)
		{
			int curr_time = a[i];
			int pos = lower_bound(intervals.begin(), intervals.end(), make_pair(curr_time, 0))
			          - intervals.begin();
			if (pos == 0) {
				int ans = intervals[0].first - curr_time;
				//alt: ans=intervals[0].first-curr_time;
				cout << ans;
			}
			else {
				int ans = -1;
				if (intervals[pos - 1].second > curr_time)
					ans = 0;
				else if (pos < intervals.size())
					ans = intervals[pos].first - curr_time;
				cout << ans;
			}
			cout << "\n";
		}
	}
	return 0;
}