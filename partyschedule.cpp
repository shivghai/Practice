#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct partyType {
	int fun, cost;
	partyType():fun(0),cost(0){}
};


int knapsack(vector<partyType> &parties, int n, int budget) {
	vector< vector<int> > DP(budget + 1, vector<int>(n, 0));
	
	for(int i = 0; i <= budget; ++i)
		for(int j = 0; j < n; ++j) 
			if(i - parties[j].cost >= 0)
				DP[i][j] = j==0?parties[j].fun:max(DP[i][j - 1], parties[j].fun + DP[i - parties[j].cost][j - 1]);
			else
				DP[i][j] = j==0?0:DP[i][j-1];

	for(int i = budget; i >= 1; --i)
		if(DP[i][n - 1] != DP[i - 1][n - 1]){
			cout << i << " ";
			i = 0;
		}

	return DP[budget][n - 1];

}


int main() {
	int budget, n;
	vector<partyType> parties;
	cin >> budget >> n;

	while(!(budget == 0 && n == 0)) {
		parties.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> parties[i].cost >> parties[i].fun;

		cout << knapsack(parties, n, budget) << "\n";
		cin >> budget >> n;

	}

	return 0;
}
