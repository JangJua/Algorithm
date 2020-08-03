#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;
int a, b, c, d;
map <p, bool> M;
queue<p> Q;

int main() {
	cin >> a >> b >> c >> d;
	Q.push({ 0,0 });
	M[{ 0, 0 }] = true;
	int step = 0;

	while(!Q.empty()) {
		int qsize = Q.size();
		bool fin = false;

		for (int i = 0; i < qsize; i++) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			
			//���� ���� 
			if (x == c && y == d) {
				cout << step << endl;
				return 0;
			}

			//���뿡 �� ���� ä��� 
			if (M[{a, y}] == false) {
				M[{ a, y }] = true;
				Q.push({ a, y });
			}
			if (M[{x, b}] == false) {
				M[{ x, b }] = true;
				Q.push({ x, b });
			}

			//���� ���� 
			if (M[{0, y}] == false) {
				M[{ 0, y }] = true;
				Q.push({ 0, y });
			}
			if (M[{x, 0}] == false) {
				M[{ x, 0 }] = true;
				Q.push({ x, 0 });
			}

			//���� x�� ���� ���� y�� �ױ� 
			if (x <= (b - y)) {
				if (M[{0, x + y}] == false) {
					M[{ 0, x + y }] = true;
					Q.push({ 0, x + y });
				}
			}
			else {
				int left = x - (b - y);
				if (M[{ left, b}] == false) {
					M[{ left, b }] = true;
					Q.push({ left, b });
				}
			}
			//���� y�� ���� ���� x�� �ױ� 
			if (y <= (a - x)) {
				if (M[{x + y, 0}] == false) {
					M[{ x + y, 0 }] = true;
					Q.push({ x + y, 0 });
				}
			}
			else {
				int left = y - (a - x);
				if (M[{a, left}] == false) {
					M[{ a, left }] = true;
					Q.push({ a, left});
				}
			}
		}
		if (fin) break;
		step++;
	}
	
	cout << -1 << endl;

	return 0;
}