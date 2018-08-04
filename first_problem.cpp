#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	
	int n, s;
	vector <int> arr;
	
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	cin >> s;
	
	map<int, bool> mp;
	
	bool ans = false;
	
	for (int i = 0; i < n; i++) {
		if (mp.find(s - arr[i]) != mp.end()) {
			ans = true;
			break;
		} else {
			mp[arr[i]] = true;
		}
	}
	
	if (ans) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	
	return 0;
}
