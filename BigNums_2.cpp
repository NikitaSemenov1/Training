#include <iostream>
#include <cstring>
#include <fstream>

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
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	char a[N], c[N];
	int b;
	
	memset(a, 0, sizeof a);
	memset(c, 0, sizeof c);
	
	fin >> a;
	fin >> b;
	
	int a_len = strlen(a), c_len = 1;
	
	strNum2bigNum(a, a_len);
	
	sh_mult(a, a_len, b, c, c_len);

	bigNum2strNum(a, a_len);
	bigNum2strNum(c, c_len);
	
	fout << c;
	
	fin.close();
	fout.close();
	
	return 0;
}
