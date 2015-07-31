#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	string str;
	cin >> str;
	vector<int> vec(str.size() + 1, 0);
	int N = str.size() + 1;

	vec[0] = 1;
	vec[1] = 1;

	for(int i = 2; i <= N; ++i) {
		if(str[i - 1] == '1' || (str[i - 1] == '2' && 
			str[i] <= '6') ) {
			vec[i] = vec[i - 1] + vec[i - 2];
		}

		else {
			vec[i] = vec[i - 1];
			
		}
	}
	cout << vec.back() << endl;
	return 0;
}
