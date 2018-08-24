#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	int num = 13;

	string s = bitset<32>(num).to_string();
	
	int value = stoi(s, nullptr, 2);
	cout << value << endl;

	for(int i = 0; i < s.size()-1; i++){
		string newString = s;
		swap(newString[i],newString[i+1]);
		if (newString != s){
			int x = stoi(newString, nullptr, 2);
			cout << "swap " << 32-i << " and " << 32-(i+1) << " to make " << x << endl;
			// b1 = 32-i, b2 = 32-(i+1), bsNum = x
		}
	}

	return 0;
}