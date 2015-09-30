#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	long long DP[5000];
	cin >> str;
	while(str[0] != '0') {
	
		for(int i = 0; i < 5000; ++i) {
			DP[i] = 0;
		}

		str = "X" + str;
		int N = str.size();
	
		DP[0] = 1;
		DP[1] = 1;
		for(int i = 2; i < N; ++i) {
			if(str[i - 1] == '1' && str[i] != '0') {
				if((i + 1 < N && str[i + 1] != '0') || i + 1 >= N)
					DP[i] = DP[i - 1] + DP[i - 2];
				else
					DP[i] = DP[i - 1];
			}
			else if(str[i - 1] == '2' && str[i] <= '6' && str[i] != '0') {
				if((i + 1 < N && str[i + 1] != '0') || i + 1 >= N)
					DP[i] = DP[i - 1] + DP[i - 2];
				else
					DP[i] = DP[i - 1];
			}
			else
				DP[i] = DP[i - 1];
		}
		cout << DP[N - 1] << "\n";
		cin >> str;
	}
	
	return 0;
}
