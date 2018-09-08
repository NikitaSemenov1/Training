#include <iostream>
#include <cstring>
#include <fstream>

#define N 1001

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

void sum(char* a, int a_len, char* b, int b_len, char* c, int &c_len) {
	
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
	
	ifstream fin("input.txt");
	ofstream fout("output.txt");
		
	char a[N];
	char b[N];
	char c[N];

	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);

	fin >> a;
	fin >> b;
	
	int a_len = strlen(a), b_len = strlen(b), c_len = 1;

	strNum2bigNum(a, a_len);
	strNum2bigNum(b, b_len);
	
	sum(a, a_len, b, b_len, c, c_len);
	
	bigNum2strNum(a, a_len);
	bigNum2strNum(b, b_len);
	bigNum2strNum(c, c_len);

	fout << c;
	
	fin.close();
	fout.close();
	
	return 0;
}
