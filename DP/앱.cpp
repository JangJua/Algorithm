#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int memory[100], cost[100], cache[10010];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}
	
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		total += cost[i];
	}
	
	//cache[i]: cost�� i�� ��� Ȯ���� �� �ִ� �ִ� �޸�

	//������ �ۿ� ���ؼ� ������Ʈ
	for (int i = 0; i < N; i++) {
		//i��° ���� ��Ȱ��ȭ �ϰ��� ���� cost�� ���� �� ������Ʈ (j >= cost[i])
		for (int j = total; j >= cost[i]; j--) {
			//i��° ���� Ȱ��ȭ ���� ��, i��° ���� ��Ȱ��ȭ�ϰ� �޸𸮸� Ȯ������ �� ��
			cache[j] = max(cache[j], cache[j - cost[i]] + memory[i]);
		}
	}

	int ans = 0;
	while (ans < total && cache[ans] < M) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}