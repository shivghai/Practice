/*
ID: shivsin1
PROG: transform
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool check90(char grid[11][11], char transformed[11][11], int N){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(grid[i][j] != transformed[j][N - 1 - i])
				return false;
	return true;
}

bool check180(char grid[11][11], char transformed[11][11], int N){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(grid[i][j] != transformed[N - 1 - i][N - 1 - j])
				return false;
	return true;
}

bool check270(char grid[11][11], char transformed[11][11], int N){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(grid[i][j] != transformed[N - 1 - j][i])
				return false;
	return true;
}

bool checkRef(char grid[11][11], char transformed[11][11], int N, int &retval){
	char reflected[11][11];
	
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			reflected[i][j] = grid[i][N - 1 - j];

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(reflected[i][j] != transformed[i][j]){
				i = N;
				j = N;
				break;
			}
			else if(i == N - 1 && j == N - 1){
				retval = 4;
				return true;
			}

	if(check90(reflected, transformed, N) || check180(reflected, transformed, N) ||
		check270(reflected, transformed, N)){
		retval = 5;
		return true;
	}

	return false;
}

bool checkNoChange(char grid[11][11], char transformed[11][11], int N){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(grid[i][j] != transformed[i][j])
				return false;
	return true;
}

int main(){
	int N;
	
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	
	char grid[11][11];
	char transformed[11][11];
	int retval = 0;
	fin >> N;

	for(int i = 0; i < N; ++i)
		fin >> grid[i];
	for(int i = 0; i < N; ++i)
		fin >> transformed[i];

	if(check90(grid, transformed, N))
		retval = 1;
	else if(check180(grid, transformed, N))
		retval = 2;
	else if(check270(grid, transformed, N))
		retval = 3;
	else if(checkRef(grid, transformed, N, retval))
		retval = retval;
	else if(checkNoChange(grid, transformed, N))
		retval = 6;
	else
		retval = 7;
	fout << retval << "\n";
	return 0;
}
