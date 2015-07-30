#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

long long findMax(long long N, map<long long, long long> &memo) {

	if(memo.find(N) != memo.end())
		return memo[N];
	memo[N] = max(N, findMax(N/2, memo) + findMax(N/3, memo) + findMax(N/4, memo));
	return memo[N];
}

int main() {
	long long N;
	map<long long, long long> memo;
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;
	while(cin >> N) {
		cout << findMax(N, memo) << "\n";
	}
	return 0;
}
