//Решение подразумевает перебор всех комбинаций наборов предметов
//Используются битмаски

#include <iostream>

using namespace std;

int main() {
	
	int n, W;
	cin >> n >> W;
	int weight[19], price[19]; //Массивы веса и цены предметов
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> price[i];
	}
	
	int N = 1 << n; //Число комбинаций
	
	long long maxPrice = 0; //Максимальная стоимость
	int maxK = 0, maxN = 0; //Комбинация, дающая максимальную стоимость и число предметов в ней
	for (int k = 0; k < N; k++) {
		long long p = 0, w = 0; //Цена и вес текущей комбинации
		int objN = 0; //Количество предметов данной комбинации
		for (int i = 0; i < n; i++) {
			//Если бит равен 1 обновляем значения
			if ((k >> i) % 2 == 1) {
				w += weight[i];
				//Проверка на переполнение
				if (w > W){ 
					break;
				}
				objN++;
				p += price[i];
			}
		}
		if (maxPrice < p) {
			maxPrice = p;
			maxK = k;
			maxN = objN;
		}
	}
	
	cout << maxN << " " << maxPrice << endl;
	
	//Вывод номеров предметов	
	for (int i = 0; i < n; i++) {
		if ((maxK >> i) % 2 == 1) {
			cout << i+1 << " ";
		}
	}
	
	return 0;
}
