#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long long merge(vector<int> &A, int L1, int R1, int L2, int R2) {

	vector<int> temp((R1 - L1 + 1) + (R2 - L2 + 1));
	long long inv_count = 0;
	int i, j, k;

	for(i = L1, j = L2, k = 0; i <= R1 && j <= R2;) {
		if(A[i] > A[j]) {
			temp[k++] = A[j++];
			inv_count += R1 + 1 - i;
		}
		else
			temp[k++] = A[i++];
	}
	
	while(i <= R1) {
		temp[k++] = A[i++];
	}
	
	while(j <= R2) {
		temp[k++] = A[j++];
	}

	for(int it = L1; it <= R2; ++it)
		A[it] = temp[it - L1];

	return inv_count;

}

long long merge_sort(vector<int> &A, int L, int R) {
	if(L >= R)
		return 0;
	int M = L + (R - L)/2;
	long long LeftSum = merge_sort(A, L, M);
	long long RightSum = merge_sort(A, M + 1, R);
	
	return LeftSum + RightSum + merge(A, L, M, M + 1, R);
}

int main() {
	int T;
	int N;
	vector<int> A;
	cin >> T;

	while (T--) {

		cin >> N;
		A.resize(N);
		
		for(int i = 0; i < N; ++i)
			cin >> A[i];

		cout << merge_sort(A, 0, N - 1) << "\n";

	}

	return 0;
}
