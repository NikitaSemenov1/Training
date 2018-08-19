#include <iostream>
#include <cstring>

#define N 1009

using namespace std;

void strNum2bigNum(char* str, int str_len) {
	for (int i = 0; i < str_len / 2; i++) {
		char t = str[i];
		str[i] = str[str_len - 1 - i] - '0';
		str[str_len - 1 - i] = t - '0';
	}
	if (str_len % 2 == 1) {
		str[str_len / 2] -= '0';
	}
}

void bigNum2strNum(char* str, int str_len) {
	for (int i = 0; i < str_len / 2; i++) {
		char t = str[i];
		str[i] = str[str_len - 1 - i] + '0';
		str[str_len - 1 - i] = t + '0';
	}
	if (str_len % 2 == 1) {
		str[str_len / 2] += '0';
	}
}

void sh_mult(char* a, int a_len, int m, char* c, int &c_len) {
	
	memset(c, 0, sizeof c);
	strNum2bigNum(a, a_len);
	
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
	
	bigNum2strNum(a, a_len);
	bigNum2strNum(c, c_len);
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char a[N], c[N];
	int b;
	
	memset(a, 0, sizeof a);
	
	cin >> a;
	cin >> b;
	
	int a_len = strlen(a), c_len = 1;

	sh_mult(a, a_len, b, c, c_len);

	cout << c;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
