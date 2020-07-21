#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> p;
int TC, N, M, W;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> TC;
	while (TC--) {
		vector<p> G[501];
		int res[501];

		cin >> N >> M >> W;
		int S, E, T;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			//���δ� ������ ����, ����� ���� 
			G[S].push_back({ E,T });
			G[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++) {
			//��Ȧ�� �ܹ��� 
			cin >> S >> E >> T;
			G[S].push_back({ E,-T });
		}

		for (int i = 1; i <= N; i++) {
			res[i] = INF;
		}
		res[1] = 0;
		bool check = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < G[j].size(); k++) {
					int next = G[j][k].first;
					int nextCost = G[j][k].second;
					//����Ŭ ������ �Ǿ������� �˸� �Ǳ� ������ ���������κ��� ������ �� ���� ������ �Ÿ��� ������Ʈ
					if (res[next] > res[j] + nextCost) {
						res[next] = res[j] + nextCost;
						//N��°���� ���� ���� -> ���� ����Ŭ ����, �ð��� �ǵ��� �� �� ������ �ǹ� 
						if (i == N) {
							check = true;
							break;
						}
					}
				}
			}
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}