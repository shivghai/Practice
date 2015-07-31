#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int dist, int C, vector<int> & distances) {

	int countC = 1, currentPos = distances[0];
	
	for(int i = 0, size = distances.size(); i < size; ++i) {

		if(distances[i] - currentPos >= dist) {
			++countC;
			if(countC == C)
				return true;
			currentPos = distances[i];
		}
	}
	return false;
}

// 0 1 2 4 1
int main() {
	int T;
	cin >> T;

	for(int i = 0; i < T; ++i) {
		int N, C;
		cin >> N >> C;
		vector<int> stables(N, 0);
		vector<int> distances(N, 0);

		for(int j = 0; j < N; ++j)
			cin >> stables[j];

		sort(stables.begin(), stables.end());

		for(int j = 1; j < N; ++j)
			distances[j] = distances[j - 1] + stables[j] - stables[j - 1];

		int lower = 0;
		int upper = stables[N - 1] - stables[0];

		for(int mid = lower + (upper - lower)/2; lower < upper;
					mid = lower + (upper - lower)/2)
			if(isPossible(mid, C, distances))
				lower = mid + 1;
			else
				upper = mid;

		if(isPossible(lower, C, distances))
			cout << lower << "\n";
		else
			cout << lower - 1 << "\n";

	}

	return 0;
}
