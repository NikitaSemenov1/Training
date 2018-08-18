#include <iostream>
#include <cstring>

#define N 1000

using namespace std;

void char2int(char* s, int* n, int len_n) {
	for (int i = 0, j = len_n - 1; i < len_n; i++, j--) {
		n[j] = s[i] - '0';
	}
}

void sum(int* a, int a_len, int* b, int b_len, int* c, int &c_len) {
	c_len = a_len > b_len ? a_len : b_len;
	int r = 0;
	for (int i = 0; i < c_len; i++) {
		c[i] = (a[i] + b[i] + r) ;
		r = c[i] / 10;
		c[i] %= 10;
	}
	if (r > 0) {
		c[c_len] = r;
		c_len++;
	}  
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char n1[N];
	char n2[N];

	cin >> n1;
	cin >> n2;
	
	int a[N];
	int b[N];
	int c[N];
	
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	
	int a_len = strlen(n1), b_len = strlen(n2), c_len = 1;

	char2int(n1, a, a_len);
	char2int(n2, b, b_len);

	sum(a, a_len, b, b_len, c, c_len);

	for (int i = c_len - 1; i >= 0; i--) {
		cout << c[i];
	}
	
	return 0;
}
