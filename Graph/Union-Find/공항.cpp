#include <iostream>
#define MAX 100010
using namespace std;

int G, P, ans;
int plane[MAX], parent[MAX];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	cin >> G >> P;
	for (int i = 0; i < P; i++) {
		cin >> plane[i];
	}
	
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < P; i++) {
		int docking = Find(plane[i]);
		//��ŷ�� ������ ���, �� ����Ʈ������ ���� ��ŷ�� �Ұ����ϰ� �� �� ��ȣ�� ����Ʈ������ ����
		if (docking) {
			ans++;
			//�� �� ����Ʈ ���� ��ŷ�� �Ϸ�� ��� Union �������� ��ŷ�� ������ �θ� ã���� 
			Union(docking, docking - 1);
		}
		//docking�� 0�� ��� ���� ��ŷ�� ������ ����Ʈ�� ���ٴ� ���� �ǹ� 
		else break;
	}
	cout << ans;
	return 0;
}