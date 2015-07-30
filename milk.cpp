/*
ID: shivsin1
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Compare{
	public:
	bool operator() (pair<int, int> &a, pair<int, int> &b){
	    return b.second < a.second;
    }
}X;


int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int N, M;
	int num_milk, milk_cost;
	int total_cost = 0;
	fin >> N >> M;

	priority_queue< pair<int, int>, vector< pair<int, int> >, Compare > farmers;
	
	for(int i = 0; i < M; ++i){
		fin >> milk_cost >> num_milk;
		farmers.emplace(make_pair(num_milk, milk_cost));
	}

	int cur_cost, cur_num;

	while(N > 0){
		cur_num = farmers.top().first;
		cur_cost = farmers.top().second;
		farmers.pop();
		if(N - cur_num < 0)
			total_cost += N*cur_cost;
		else
			total_cost += cur_num*cur_cost;
		N -= cur_num;
	}

	fout << total_cost << "\n";
	return 0;
}
