/* 
������� ������������ ����� ������� ���� ������������ �� ������� ������� � ������� dfs.
��� ��� ����� ���� �� ����� �������������� � ������������, � ����� ��� ���������,
������ �� ����� ����� ����� ����� ������ ���� �����, �� ������� ������� "���������" 
������������, �������������� � ������������ �����. �� ������ �������� ����� ���������
����������� ��������� ����� � ������, ��������� ��� �������. 
���� �� ����� i = 7, �� ��� ������, ��� �� ���������� ��� 8 ������ � ������ ������
*/

#include <iostream>
#include <cstring>

using namespace std;

//������ ����, ��� way[i] -  ���������� ����� �� i-�� �����
int way[8];
//������� "���������" �����
int hor_lines[8];
int vert_lines[8];
//��� "����" ����������
int diags1[15];
int diags2[15];

bool f = true; //false ���� ������� �������

void dfs(int i) {
	for(int j = 0; j < 8 && f; j++) {
		if (hor_lines[i] != 1 && vert_lines[j] != 1 && diags1[i+j] != 1 && diags2[7-i + j] != 1) {
		 	//"��������" �����
			hor_lines[i] = 1;
		 	vert_lines[j] = 1;
		 	diags1[i+j] = 1;
		 	diags2[7-i + j] = 1;
		 	
			if (f) {
				way[i] = j;
			}

		 	if (i == 7) {
		 		f = false;
			}
			if (i != 7) {
		 		dfs(i+1);
		 	}

		 	hor_lines[i] = 0;
		 	vert_lines[j] = 0;
		 	diags1[i+j] = 0;
		 	diags2[7-i + j] = 0;
		}
	}
}

int main() {
	
	memset(vert_lines, 0, sizeof vert_lines);
	memset(hor_lines, 0, sizeof hor_lines);
	memset(diags1, 0, sizeof diags1);
	memset(diags2, 0, sizeof diags2);
	
	dfs(0);

	for (int i = 0; i < 8; i++) {
		cout << (char) ('a'+i) << way[i]+1 << endl;
	}
	
	return 0;
}
