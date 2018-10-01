#include <iostream>
#include <cstring>

#define N 19

using namespace std;

int n, W;
int visit[N], maxWay[N];
int weight[N], price[N];
long long maxPrice = 0, currentPrice = 0, currentWeight = 0;
int currentN, maxN = 0;

void arrCopy(int* arr1, int* arr2, int len) {
	for (int i = 0; i < len; i++) {
		arr1[i] = arr2[i];
	}
}

void dfs(int k) {

	visit[k] = 1;
	currentN++;
	currentPrice += price[k];
	currentWeight += weight[k];
	
	if (currentPrice > maxPrice) {
		maxPrice = currentPrice;
		maxN = currentN;
		arrCopy(maxWay, visit, n);
	}
	
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && currentWeight+weight[i] <= W) {
			dfs(i);
		}
	}
	
	visit[k] = 0;
	currentPrice -= price[k];
	currentWeight -= weight[k];
	currentN--;	
}

int main() {
	
	memset(visit, 0, sizeof visit);
	
	cin >> n >> W;

	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> price[i];
	}
	
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && currentWeight+weight[i] <= W) {
			dfs(i);
		}
	}
	
	cout << maxN << " " << maxPrice << endl;
	for (int i = 0; i < n; i++) {
		if (maxWay[i] == 1) {
			cout << i + 1 << " ";
		}
	}
	
	return 0;
}
