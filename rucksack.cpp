//������� ������������� ������� ���� ���������� ������� ���������
//������������ ��������

#include <iostream>

using namespace std;

int main() {
	
	int n, W;
	cin >> n >> W;
	int weight[19], price[19]; //������� ���� � ���� ���������
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> price[i];
	}
	
	int N = 1 << n; //����� ����������
	
	long long maxPrice = 0; //������������ ���������
	int maxK = 0, maxN = 0; //����������, ������ ������������ ��������� � ����� ��������� � ���
	for (int k = 0; k < N; k++) {
		long long p = 0, w = 0; //���� � ��� ������� ����������
		int objN = 0; //���������� ��������� ������ ����������
		for (int i = 0; i < n; i++) {
			//���� ��� ����� 1 ��������� ��������
			if ((k >> i) % 2 == 1) {
				w += weight[i];
				//�������� �� ������������
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
	
	//����� ������� ���������	
	for (int i = 0; i < n; i++) {
		if ((maxK >> i) % 2 == 1) {
			cout << i+1 << " ";
		}
	}
	
	return 0;
}
