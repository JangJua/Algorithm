#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;
int N, start, fin;

vector<p> lesson;
priority_queue<int, vector<int>, greater<int>> room;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> fin;
		lesson.push_back({ start,fin });
	}
	
	sort(lesson.begin(), lesson.end());
	//���� ���� ������ ������ ���ǽǿ� �߰�  
	room.push(lesson[0].second);

	for(int i = 1; i < N; i++){
		start = lesson[i].first;
		fin = lesson[i].second;
		//���� ���� ���� ������ ������ ���ǽǿ��� ���� ������ ��� 
		cout << room.top() << "\n";
		if (room.top() <= start) {
			printf("%d %d �̾\n", start, fin);
			room.pop();
			room.push(fin);
		}
		//�ƴ϶�� ���ǽ� �߰� 
		else {
			printf("%d %d �߰�\n", start, fin);
			room.push(fin);
		}
	}
	cout << room.size();
	return 0;
}