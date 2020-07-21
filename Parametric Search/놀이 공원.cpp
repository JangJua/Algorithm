#include <iostream>
using namespace std;

typedef long long ll;
const int MAX = 10000;
ll N, M, answer, ride[MAX];

//binary search: time(��)�ȿ� N���� ���̵��� ���̱ⱸ�� ž���� �� �ִ°�?
bool isPossible(ll time) {
	ll sum = M;
	for (int i = 0; i < M; i++) {
		sum += time / ride[i];
	}
	return sum >= N;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> ride[i];
	}

	//���̱ⱸ ������ ���̵� ���� �� ���� ��� 
	if (N <= M) {
		answer = N;
	}
	else {
		ll left = 1, right = N * 30, mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (isPossible(mid)) right = mid - 1;
			else left = mid + 1;
		}

		ll mm = left;
		//mm-1 �б��� �� ���̱ⱸ�� �¿� ���̵��� �� ���ֱ�
		N -= M;
		for (int i = 0; i < M; i++) {
			N -= (mm - 1) / ride[i];
		}

		//mm��°���� ������ ���̰� ź ���̱ⱸ 
		for (int i = 0; i < M; i++) {
			if (mm % ride[i] == 0) {
				N--;
				if (N == 0) {
					answer = i + 1;
					break;
				}
			}
		}
	}
	
	cout << answer;
	return 0;
}