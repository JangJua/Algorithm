#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10010;
const int INF = 0x3f3f3f3f;
int N, x, y, cache[MAX];

int main() {
	cin >> N;
	vector<pair<int, int>> v(N + 1);
	for (int i = 1; i <= N; i++) { 
		cin >> v[i].first >> v[i].second;
		if (v[i].second < 0) {
			v[i].second *= -1;
		}
	}

	sort(v.begin() + 1, v.end());

	//cache[n]: n��° ���������� ������ ���� �ּڰ�
	for (int i = 1; i <= N; i++) {
		cache[i] = INF;
	}
	cache[0] = 0;
	
	for (int i = 1; i <= N; i++) {
		int maxHeight = 0;
		//i��° �������� ������, �� ���� �������� ��� ��� 
		for (int j = i; j >= 1; j--) { 

			//j��° ������ ~ i��° ������ �� �ִ� ���� 
			maxHeight = max(maxHeight, v[j].second);

			//���簢�� �����̹Ƿ� ��ǥ�� Ŀ���� �� �ִ� ���簢���� �ʺ� ���ϱ� 
			int square = max(v[i].first - v[j].first, maxHeight * 2);
			cache[i] = min(cache[i], cache[j - 1] + square);
		}
	}
	
	cout << cache[N] << endl;
	return 0;
}