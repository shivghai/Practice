/*
ID: shivsin1
PROG: namenum
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin("namenum.in");
	ifstream entries("dict.txt");
	ofstream fout("namenum.out");
	string numstring, entry;
	string Arr[10] = {"", "", "ABC", "DEF", "GHI",
					"JKL", "MNO", "PRS", "TUV", "WXY"
	};
	char temp;
	bool found = false;

	fin >> numstring;
	while(entries >> entry){
		if(entry.size() == numstring.size()){
			for(size_t i = 0; i < numstring.size(); ++i){
				temp = entry[i];
				if(temp != Arr[numstring[i] - '0'][0] && temp != Arr[numstring[i] - '0'][1] &&
					temp != Arr[numstring[i] - '0'][2])
					break;
				if(i == numstring.size() - 1){
					fout << entry << "\n";
					found = true;
				}

			}
		}
	}

	if(!found)
		fout << "NONE\n";

	return 0;
}
