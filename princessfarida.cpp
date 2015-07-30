#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

inline
	long long maxL(long long a, long long b){return a > b?a:b;}

long long DP(vector<long long> &monsters, int N) { 

	vector< vector<long long> > total(N, vector<long long>(2));
	
	if(N == 0)
		return 0;
	if(N == 1)
		return monsters[0];
	if(N == 2)
		return maxL(monsters[0], monsters[1]);

	total[0][0] = monsters[0];
	total[0][1] = 0;
	total[1][0] = monsters[1];
	total[1][1] = monsters[0];


	for(int i = 2; i < N; ++i) {
		
		total[i][1] = maxL(total[i - 1][0], total[i - 2][0]);
		total[i][0] = total[i - 1][1] + monsters[i];

	}

	return maxL(total[N - 1][0], total[N - 1][1]);
}

int main() {
	int T;
	int N;
	vector<long long> monsters;
	cin >> T;

	for(int counter = 1; counter <= T; ++counter) {
		cin >> N;
		monsters.resize(N);
		
		for(int i = 0; i < N; ++i)
			cin >> monsters[i];

		cout << "Case " << counter << ": " << DP(monsters, N) << "\n";
	}

	return 0;
}
