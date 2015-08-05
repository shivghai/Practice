#include <iostream>
#include <vector>
#include <string>
using namespace std;

int DP[102][102][102];

int maxSubstring(string A, string B, int K) {

	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			for(int k = 0; k < 100; ++k)
				DP[i][j][k] = 0;

	int Asize = A.size(), Bsize = B.size();

	for(int i = 1; i <= K; ++i) {

		for(int j = Asize; j >= 0; --j) {

			for(int k = Bsize; k >= 0; --k) {
				
				if(j == Asize || k == Bsize)
					DP[i][j][k] = 0;
				else if(A[j] != B[k])
					DP[i][j][k] = max(DP[i][j + 1][k], DP[i][j][k + 1]);
				else if(A[j] == B[k]) {
					DP[i][j][k] = max(A[j] + DP[i - 1][j + 1][k + 1], max(DP[i][j + 1][k], DP[i][j][k + 1]));
				}

			}

		}

	}

	if(DP[K - 1][0][0] == DP[K][0][0])
		return 0;

	return DP[K][0][0];

}

int main() {

	int T;
	string A, B;
	int K;
	cin >> T;
	while(T--) {
		cin >> A >> B >> K;

		cout << maxSubstring(A, B, K) << "\n";
	}
	return 0;
}
