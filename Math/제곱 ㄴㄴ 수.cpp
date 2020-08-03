#include <iostream>
using namespace std;

typedef long long ll;
ll MIN, MAX;
ll numbers[1000010];

int main() {
	cin >> MIN >> MAX;

	//�����佺�׳׽��� ü: �������� ���������� 
	for (ll i = 2; i * i <= MAX; i++) {
		//���������� ������ ����, ������ �������� �ʴ´ٸ� �� ���� ���ں��� ���� 
		ll x = MIN / (i * i);
		if (MIN % (i * i)) x++;

		//�������� ������ �������� ���ڵ� üũ�ϱ� 
		while (x * (i * i) <= MAX) {
			numbers[x * (i * i) - MIN] = 1;
			x++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= MAX - MIN; i++) {
		if (numbers[i] == 0) ans++;
	}
	cout << ans;
	return 0;
}