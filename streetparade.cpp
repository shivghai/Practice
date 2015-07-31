#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
int main() {
	int N;
	deque<int> list;
	cin >> N;

	while(N) {
		stack<int> street;
		stack<int> side_street;
		list.resize(N);
		int counter = 1;

		for(int i = 0; i < N; ++i)
			cin >> list[i];

		for(int i = N - 1; i > -1; --i)
			street.push(list[i]);
		
		while(counter < N) {

			if(!street.empty() && street.top() == counter) {
				++counter;
				street.pop();
			}

			else if(!side_street.empty() && side_street.top() == counter) {
				++counter;
				side_street.pop();
			}

			else if(!street.empty()) {
				side_street.push(street.top());
				street.pop();
			}

			else {
				cout << "no\n";
				counter = N + 1;
			}

		}

		if(counter == N)
			cout << "yes\n";

		cin >> N;
	}

	return 0;
}
