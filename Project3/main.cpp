#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int N = 5, M = 5;
const int T = 3;

struct Point {
	int x, y;

	bool operator<(const Point &rhs) const {
		return x < rhs.x || (!(rhs.x < x) && y < rhs.y);
	}
};

bool isOkToGoThere(const Point &P, const int V) {
	return P.x >= 0 && P.x < N && P.y >= 0 && P.y < M && V > T;
}

int main() {
	int m[N][M] = {
		{5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5},
		{5, 5, 5, 5, 5},
		{5, 2, 5, 2, 2}, // {5, 2, 2, 2, 2}, // <- nie dziala
		{5, 2, 5, 5, 5}
	};

	int neumann[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

	Point start{ 0, 0 };
	Point end{ 4, 4 };

	set <Point> S;
	queue <Point> Q;
	Q.push(start);

	while (!Q.empty()) {
		Point P = Q.front();
		Q.pop();
		S.insert(P);

		for (int i = 0; i < 4; ++i) {
			Point R{ P.x + neumann[i][0], P.y + neumann[i][1] };

			if (S.find(R) == S.end()) {
				if (isOkToGoThere(R, m[R.x][R.y])) {
					if (R.x == end.x && R.y == end.y) {
						cout << "da sie!!!" << endl;
						getchar();
						return 0;
					}
					Q.push(R);
				}
			}
		}
	}

	cout << "nie da sie!!!" << endl;

	getchar();

	return 0;
}