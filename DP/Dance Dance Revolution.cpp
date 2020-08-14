#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int ans = INF;
int input, len, command[100000];
int cache[5][5][100000];

int DFS(int leftPos, int rightPos, int idx) {
	if (idx >= len) return 0;

	int& ret = cache[leftPos][rightPos][idx];
	if (ret != -1) return ret;

	//�� ���� �߾ӿ� �ִ� ��� 
	if (leftPos == 0 && rightPos == 0) {
		return ret = DFS(command[idx], rightPos, idx + 1) + 2;
	}

	//���� Ŀ�ǵ�� ��ġ�� ��� 
	if (leftPos == command[idx]) {
		return ret = DFS(command[idx], rightPos, idx + 1) + 1;
	}
	if (rightPos == command[idx]) {
		return ret = DFS(leftPos, command[idx], idx + 1) + 1;
	}

	ret = INF;

	//���� Ŀ�ǵ�� ��ġ�� �ʰ�, �߾ӿ� �־��� ���
	if (leftPos == 0) {
		ret = min(ret, DFS(command[idx], rightPos, idx + 1) + 2);
	}
	//���� Ŀ�ǵ�� ��ġ�� �ʰ�, �ݴ������� �����̴� ��� 
	if (abs(leftPos - command[idx]) == 2) {
		ret = min(ret, DFS(command[idx], rightPos, idx + 1) + 4);
	}
	//���� Ŀ�ǵ�� ��ġ�� �ʰ�, ������ �������� �����̴� ���
	else {
		ret = min(ret, DFS(command[idx], rightPos, idx + 1) + 3);
	}

	if (rightPos == 0) {
		ret = min(ret, DFS(leftPos, command[idx], idx + 1) + 2);
	}
	if (abs(rightPos - command[idx]) == 2) {
		ret = min(ret, DFS(leftPos, command[idx], idx + 1) + 4);
	}
	else {
		ret = min(ret, DFS(leftPos, command[idx], idx + 1) + 3);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	len = 0;
	cin >> input;
	while (input != 0) {
		command[len++] = input;
		cin >> input;
	}

	memset(cache, -1, sizeof(cache));

	int ans = DFS(0, 0, 0);
	cout << ans << endl;

	return 0;
}