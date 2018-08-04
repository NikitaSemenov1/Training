#include <iostream>
#include <map>

#define N 1000

using namespace std;

int main() {
	
	int n, s, arr[N];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> s;
	
	map<int, bool> mp;
	
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		if (mp.find(arr[i]) != mp.end()) {
			ans = 1;
			break;
		} else {
			mp[s - arr[i]] = 1;
		}
	}
	
	if (ans) cout << "Yes";
	else cout << "No";
	
	return 0;
}
