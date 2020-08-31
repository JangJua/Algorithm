#include <iostream>
#include <algorithm>
using namespace std;

int N, books[200000], LIS[200000];

// LIS(Longest Increasing Subsequence)
// target�� ã�� ������ ���� ��� ���� ������ ��ġ 
// �ִ� ��쿡�� ��ü�Ǿ�� �� ��ġ(ũ�ų� ���� ù ���� ��ġ) ��ȯ 
int lowerBound(int start, int end, int target) {
	while (start < end) {
		int mid = (start + end) / 2;

		//ã���� �ϴ� ������ ������ ������ �������� Ž���Ѵ�.
		if (LIS[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> books[i];
	}

	int ans = 0;
	LIS[0] = books[0];

	for (int i = 1, j = 0; i < N; i++) {
		// �����־�� �� å�� ��ȣ�� ���� ū ���, �׳� �־ �� 
		if (LIS[j] < books[i]) {
			LIS[++j] = books[i];
		}

		// ��ü�Ǿ�� �� ��ġ ���� 
		else {
			int pos = lowerBound(0, j, books[i]);
			LIS[pos] = books[i];
			ans++; //��ü Ƚ�� 
		}
	}

	cout << ans << endl;
	return 0;
}