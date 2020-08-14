#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
priority_queue< int, vector<int>, less<int>> pq;

int main() {
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	//��������� 1����, �Ŷ���� 2������ ���� 
	sort(v.begin(), v.end());

	int ans = 0, idx = N - 1;

	//�� ������ ��������� N ����, ������ ������� ��¥�������� ����Ʈ ����ֱ�  
	for (int i = N; i >= 1; i--) {
		while (idx >= 0 && v[idx].first == i) {
			pq.push(v[idx].second);
			idx--;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans << endl;

	return 0;
}