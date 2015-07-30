#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int minVal(int a, int b, int c) {
	int t = min(a, b);
	t = min(t, c);
	return t;
}

int edit_distance(string &A, string &B, int i, int j, vector<vector<int> > & DP) {

	if(i == A.size() || j == B.size())
		return A.size() - i + B.size() - j;
	
	if(DP[i][j])
		return DP[i][j];

	if(A[i] == B[j])
		return DP[i][j] = edit_distance(A, B, i + 1, j + 1, DP);
	else
		return DP[i][j] = minVal(1 + edit_distance(A, B, i, j + 1, DP), 1 + edit_distance(A, B, i + 1, j, DP),
		1 + edit_distance(A, B, i + 1, j + 1, DP));


}

int main() {
	string A, B;
	int T;
	cin >> T;

	while (T--) {
		cin >> A >> B;
		vector< vector<int> > DP(A.size() + 1, vector<int>(B.size() + 1, 0));
		int N = A.size();
		int M = B.size();

		for(int i = 0; i <= N; ++i) {
			for(int j = 0; j <= M; ++j) {
				if(i == 0)
					DP[i][j] = j;
				else if(j == 0)
					DP[i][j] = i;
				else if(A[i - 1] == B[j - 1])
					DP[i][j] = DP[i - 1][j - 1];
				else
					DP[i][j] = min(DP[i - 1][j - 1], 
					min(DP[i - 1][j], DP[i][j - 1])) + 1;
			}
		}
		cout << DP[N][M] << "\n";
		for(int i = 0; i <= N; ++i) {
			for(int j = 0; j <= M; ++j)
				cout << DP[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
