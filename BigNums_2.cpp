#include <iostream>
#include <cstring>

#define N 1000

using namespace std;

void char2int(char* s, int* n, int len_n) {
	for (int i = 0, j = len_n - 1; i < len_n; i++, j--) {
		n[j] = s[i] - '0';
	}
}

void sh_mult(int* a, int a_len, int m, int* c, int &c_len) {
	c_len = a_len;
	long long r = 0;
	long long t;
		
	for (int i = 0; i < a_len; i++) {
		t = a[i] * m + r;
		c[i] = t % 10;
		r = t / 10; 
	}
	
	while (r != 0) {
		c[c_len] = r % 10;
		c_len++;
		r /= 10;
	}

	if (m == 0) {
		c_len = 1;
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char n1[N];
	
	int b;
	
	cin >> n1;
	cin >> b;
	
	int a[2500];
	int c[2500];
	
	memset(a, 0, sizeof a);
	memset(c, 0, sizeof c);
	
	int a_len = strlen(n1), c_len = 1;

	char2int(n1, a, a_len);

	sh_mult(a, a_len, b, c, c_len);

	for (int i = c_len - 1; i >= 0; i--) {
		cout << c[i];
	}
	
	return 0;
}
