#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

inline
	long long max3(long long x, long long y, long long z){
		return max(max(x,y),z);
	}
inline
	int leftC(int cur){
		return (cur+1)*2 - 1;
	}
inline
	int rightC(int cur){
		return (cur+1)*2;
	}

struct Node {
	int l, r;
	long long maxLeft;
	/*maxLeft: maximum starting from the left*/
	long long maxRight;
	/*maxRight: maximum ending in the right*/
	long long intervalSum;
	/*intervalSum: sum of the whole interval*/
	long long maxOverall;
	/*maxOverall: maximum sum overall*/

	Node():l(0),maxLeft(0),maxRight(0),intervalSum(0),maxOverall(0){}

	void node_merge(Node &a, Node &b);

};

void Node::node_merge(Node &a, Node &b) {
	l = a.l;
	r = b.r;
	maxOverall = max3(a.maxRight + b.maxLeft, a.maxOverall, b.maxOverall);
	maxRight = max(b.maxRight, a.maxRight + b.intervalSum);
	maxLeft = max(a.maxLeft, a.intervalSum + b.maxLeft);
}

enum POS{ LEFT, RIGHT, CENTER, WHOLE };

Node query(int x, int y, vector<Node> &tree, int curpos) {
	/* Contained fully in current interval */
	if(tree[curpos].l == x && tree[curpos].r == y) {
		return tree[curpos];
	}

	int L = leftC(curpos);
	int R = rightC(curpos);

	/* Contained entirely in the left child interval of the current interval */
	if(tree[L].l <= x && tree[L].r >= y) {
		return query(x, y, tree, L);
	}
	
	/* Contained entirely in the right child interval of the current interval */
	if(tree[R].l <= x && tree[R].r >= y) {
		return query(x, y, tree, R);
	}
	
	/* Contained in both child intervals of the current interval */
	Node leftRight, rightRight;
	leftRight = query(x, tree[L].r, tree, L);
	rightRight = query(tree[R].l, y, tree, R);
	
	Node temp;
	temp.node_merge(leftRight, rightRight);
	
	return temp;
	
}

int get_size(int N) {
	int counter = 0;
	int temp = N;
	int prod = 1;

	while(N != 1) {
		N /= 2;
		++counter;
	}

	while(counter--)
		prod *= 2;
	if(temp > prod)
		prod *= 2;
	return prod*2 - 1;

}

int main() {
	int N, M;
	int x, y;
	int treeSize;
	vector<Node> tree;
	
	scanf("%d",&N);
	treeSize = get_size(N);
	tree.resize(treeSize, Node());
	
	for(int i = treeSize/2, j = 0; j < N; ++i, ++j) {
		scanf("%lld", &tree[i].maxLeft);
		tree[i].maxOverall = tree[i].maxRight = tree[i].intervalSum = tree[i].maxLeft;
	}
	for(int i = treeSize/2, j = 0; i < treeSize; ++i, ++j) {
		tree[i].l = j;
		tree[i].r = j;
		if(j >= N) {
			tree[i].maxOverall = tree[i].maxLeft = tree[i].maxRight = tree[i].intervalSum = -1;
		}
	}

	for(int i = treeSize - 1; i >= 2; i -= 2) {
		
		tree[(i - 1)/2].intervalSum = tree[i - 1].intervalSum + tree[i].intervalSum;

		tree[(i - 1)/2].maxLeft = max(tree[i - 1].maxLeft, tree[i - 1].intervalSum + tree[i].maxLeft);

		tree[(i - 1)/2].maxRight = max(tree[i].maxRight, tree[i - 1].maxRight + tree[i].intervalSum);

		tree[(i - 1)/2].maxOverall = max3(tree[i - 1].maxRight + tree[i].maxLeft,
										  tree[i - 1].maxOverall, tree[i].maxOverall);

		tree[(i - 1)/2].l = tree[i - 1].l;
		tree[(i - 1)/2].r = tree[i].r;

	}


	scanf("%d", &M);

	for(int i = 0; i < M; ++i) {
		scanf("%d %d", &x, &y);
		--x;
		--y;
		printf("%d\n", query(x, y, tree, 0).maxOverall);
	}

	return 0;
}
