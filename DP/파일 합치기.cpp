#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 510;
int T, K;
int dp[MAX][MAX], cost[MAX], sum[MAX];

int min(int a, int b) { return a < b ? a : b; }

int dfs(int i, int j) {
	if (dp[i][j] != 0x3f3f3f3f) {
		return dp[i][j];
	}
	if (i == j) return dp[i][j] = 0;
	if (i + 1 == j) return dp[i][j] = cost[i] + cost[j]; //���� �� ���� ������ ��� 
	for (int mid = i; mid < j; mid++) {
		int left = dfs(i, mid);
		int right = dfs(mid + 1, j);
		dp[i][j] = min(dp[i][j], left + right);
	}
	//�� ������ ��ĥ �� �ʿ��� ���: i ~ j ���� ũ���� �� 
	return dp[i][j] += sum[j] - sum[i - 1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T; 
	while (T--) {
		cin >> K;
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 1; i <= K; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}
		cout << dfs(1, K) << "\n";
	}
	return 0;
}
