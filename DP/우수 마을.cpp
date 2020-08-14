#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 10010;
int N, pop[MAX], cache[2][MAX];
vector<int> G[MAX];

int DP(int now, int prev, bool isSelected) {
	int& ret = cache[isSelected][now];
	if (ret != -1) return ret;

	ret = isSelected ? pop[now] : 0;

	for (auto& next : G[now]) {
		//tree �ڷᱸ��: ������ �Ծ��� �������δ� X 
		if (next == prev) continue;

		//���� ������ ��� ������ ���, ������ ������ ��� ������ �ƴ� 
		if (isSelected) {
			ret += DP(next, now, false);
		}

		//���� ������ �Ϲ� ������ ���, ������ ������ ��� �����̰ų� �Ϲ� ����
		else {
			ret += max(DP(next, now, true), DP(next, now, false));
		}
	}
	return ret; 
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pop[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	memset(cache, -1, sizeof(cache));

	int ans = max(DP(1, 1, true), DP(1, 1, false));
	cout << ans << endl;

	return 0;
}