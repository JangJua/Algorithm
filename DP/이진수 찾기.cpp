#include <iostream>
#include <string.h>
typedef long long ll;
using namespace std;

int N, L;
string ans = "";
ll I, cache[35][35];

// ���̰� n�̰� ���� 1�� ������ l ������ �������� ���� 
ll getBinaryCount(int n, int l) {
	ll& ret = cache[n][l];

	if (ret != -1) return ret;
	if (n == 0 || l == 0) return ret = 1;

	// 1�� ��Ʈ�� ������� �ʰ� �Ѿ�� 
	ret = getBinaryCount(n - 1, l);
	// 1�� ��Ʈ�� �����ִ� ���, ��Ʈ ���
	if (l > 0) ret += getBinaryCount(n - 1, l - 1);

	return ret;
}

// ���̰� n�̰� ����� 1�� ��Ʈ�� ������ l���� �� i��° ������ ã�Ƴ��� 
void findIthNumber(int n, int l, ll i) {
	if (n == 0) return;
	
	// n�� ���������� ��� ������ ��Ʈ�� ���� ���, �������� 0���� ä��� 
	if (l == 0) {
		for (int i = 0; i < n; i++) {
			ans += '0';
		}
		return;
	}

	ll pivot = getBinaryCount(n - 1, l);
	
	// ������ n-1���� �ڸ��������� i��°�� ū ���� ����� ���� �� �ִ�.
	if (pivot >= i) {
		ans += '0';
		findIthNumber(n - 1, l, i);
	}

	// ������ n-1�� �ڸ��������� i��°�� ū ���� ���� �� ����.
	else {
		ans += '1';
		findIthNumber(n - 1, l - 1, i - pivot);
	}
}

int main() {
	cin >> N >> L >> I;

	memset(cache, -1, sizeof(cache));

	findIthNumber(N, L, I);
	cout << ans << endl;

	return 0;
}