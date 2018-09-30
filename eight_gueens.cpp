/* 
Решение представляет собой перебор всех расположений до первого верного с помощью dfs.
Так как ферзь бьёт на доске горизонтальную и вертикальную, а также две диагонали,
причем на одной такой линии может только один ферзь, то заведем массивы "занятости" 
вертикальных, горизонтальных и диагональных линий. На каждой итерации будем проверять
возможность поставить ферзя в клетку, используя эти массивы. 
Если мы дошли i = 7, то это значит, что мы расставили все 8 ферзей и задача решена
*/

#include <iostream>
#include <cstring>

using namespace std;

//Массив пути, где way[i] -  координаты ферзя на i-ой линии
int way[8];
//Массивы "занятости" линий
int hor_lines[8];
int vert_lines[8];
//Два "вида" диагоналей
int diags1[15];
int diags2[15];

bool f = true; //false если решение найдено

void dfs(int i) {
	for(int j = 0; j < 8 && f; j++) {
		if (hor_lines[i] != 1 && vert_lines[j] != 1 && diags1[i+j] != 1 && diags2[7-i + j] != 1) {
		 	//"занимаем" линии
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
