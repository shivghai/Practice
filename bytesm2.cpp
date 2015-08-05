#include <iostream>
#include <vector>
#include <string>
using namespace std;

int grid[100][100];
int DP[100][100];

int findMax(int h, int w) {

	for(int i = 0; i < w; ++i)
		DP[0][i] = grid[0][i];

	for(int i = 1; i < h; ++i) {

		for(int j = 0; j < w; ++j) {
			DP[i][j] = DP[i - 1][j];
			if(j + 1 < w)
				DP[i][j] = max(DP[i][j], DP[i - 1][j + 1]);
			if(j - 1 >= 0)
				DP[i][j] = max(DP[i][j], DP[i - 1][j - 1]);
			DP[i][j] += grid[i][j];
		}
	}

	int maxVal = 0;
	for(int i = 0, j = h - 1; i < w; ++i)
		maxVal = max(maxVal, DP[j][i]);
	return maxVal;
}

int main() {

	int T;
	int h, w;
	cin >> T;

	while(T--) {
		cin >> h >> w;

		for(int i = 0; i < h; ++i)
			for(int j = 0; j < w; ++j)
				cin >> grid[i][j];

		cout << findMax(h, w) << "\n";

	}

	return 0;
}
