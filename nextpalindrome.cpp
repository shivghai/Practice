#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


void copyLeft(string &str) {
	for(int l = 0, r = str.size() - 1; l < r; ++l, --r)
		str[r] = str[l];
}

void increment(string &str, int pos) {
	if(str[pos] == '9') {
		while(pos != -1 && str[pos] == '9')
			str[pos--] = '0';
		if(pos == -1)
			str = "1" + str;
	}
	if(pos >= 0)
		++str[pos];
}

string& nextPalin(string &str) {
	int size = str.size();
	int l = size/2 + size%2 - 1, r = size/2;
	while(l != 0 && str[l] == str[r]) {
		--l;
		++r;
	}
	if(l == 0 && str[l] == str[r]) {
		increment(str, size/2 + size%2 - 1);
		copyLeft(str);
		return str;
	}

	if(str[l] > str[r]) {
		copyLeft(str);
		return str;
	}

	increment(str, size/2 + size%2 - 1);
	copyLeft(str);
	return str;
}

int main() {
	int T;
	string str;
	cin >> T;
	while (T--) {
		cin >> str;
		cout << nextPalin(str) << "\n";
	}
	return 0;
}
