#include <iostream>
#include <algorithm>
#define MAX 510
using namespace std;

string str;
char DNA[MAX];
int cache[MAX][MAX];

int main() {
	cin >> str;
	int N = str.length();
	for (int i = 1; i <= N; i++) {
		DNA[i] = str[i - 1];
	}
	
	//�ܾ��� ���� 2���� ��ü ���̱��� 
	for (int size = 1; size < N; size++) {

		//��ü ���ڿ� �� �ش� ������ ��� ���ڿ� Ȯ�� 
		for (int start = 1; size + start <= N; start++) {
			int end = size + start;

			//� X�� KOI �����ڶ��, aXt�� gXc�� KOI �������̴�.
			if ((DNA[start] == 'a' && DNA[end] == 't') || (DNA[start] == 'g' && DNA[end] == 'c')) {
				cache[start][end] = cache[start + 1][end - 1] + 2;
			}

			//� X�� Y�� KOI �����ڶ��, �� ���� ������ XY�� KOI �������̴�.
			for (int mid = start; mid < end; mid++) {
				cache[start][end] = max(cache[start][end], cache[start][mid] + cache[mid + 1][end]);
			}
		}
	}

	cout << cache[1][N] << endl;
	return 0;
}