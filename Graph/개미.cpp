#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100010
#define MAX_STEP 17 // 2^k >= MAX�� �ּ��� k�� 16

using namespace std;

int N, ant[MAX], Next[MAX][MAX_STEP], Cost[MAX][MAX_STEP];
vector<pair<int, int>> graph[MAX];
bool visited[MAX];

//�׷��� Ž��, ���� ���� Ȯ��
void DFS(int here) {
	visited[here] = true;

	for (auto& n : graph[here]) {
		if (visited[n.first]) continue;

		Next[n.first][0] = here;
		Cost[n.first][0] = n.second;

		DFS(n.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ant[i];
	}

	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	memset(visited, false, sizeof(visited));
	memset(Next, 0, sizeof(Next));
	memset(Cost, 0, sizeof(Cost));

	DFS(1);
	Next[1][0] = 1;
	Cost[1][0] = 0;

	//��� ���̺�, Next[i][j]: i���� �����ؼ� 2^j�� �ǳ��� ���� ����
	for (int j = 1; j < MAX_STEP; j++) {
		for (int i = 1; i <= N; i++) {
			//2^j�� �̵� = 2^(j-1)��*2�� �̵�
			Next[i][j] = Next[Next[i][j - 1]][j - 1];
			Cost[i][j] = Cost[i][j - 1] + Cost[Next[i][j - 1]][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		int step = i;
		for (int j = MAX_STEP - 1; j >= 0; j--) {
			// ���� �ǳ� �� �ִ� �������� �ִ� ��쿡�� �ǳʶڴ�.
			if (Cost[step][j] > ant[i]) continue;

			ant[i] -= Cost[step][j];
			step = Next[step][j];
		}
		cout << step << "\n";
	}

	return 0;
}