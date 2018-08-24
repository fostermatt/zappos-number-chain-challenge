/*
Matt Foster
fostermatt.com
*/	


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class queueNode {
public:
	queueNode(int val, int passedCurrVal = -1, int passedVal1 = -1, int passedVal2 = -1, char passedOp = 'N', int parentIndex = -1){
		initVal = val;
		if (passedCurrVal == -1){
			currVal = initVal;
		}
		else {
			currVal = passedCurrVal;
		}
		val1 = passedVal1;
		val2 = passedVal2;
		operation = passedOp;
		parentNode = parentIndex;
	}
	int initVal, currVal, val1, val2, parentNode;
	char operation;
	// 'N' none
	// 'A' add
	// 'M' multiply
	// 'B' bit swap
};

const int MAX = 1000001;
bool found = false;

void doneInit(bool array[MAX]){
	for(int i = 0; i < MAX; i++){
		array[i] = false;
	}
}

void addSub(vector<queueNode>& processingList, bool doneArray[], int end, int &index){
	int num = processingList.at(index).currVal, x;
	vector<int> subList;

	queueNode *currentNode;
	currentNode = &processingList.at(index);

	string numString = to_string(num);
	int length = numString.length(), length2 = length;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length2; j++){
			x = stoi(numString.substr(i, length-j));
			if (x > 0){
				subList.push_back(x);
			}
		}
		length2--;
	}

	while(subList.size() > 0){
		x = subList.at(0);
		subList.erase(subList.begin());
		if(num + x < MAX && doneArray[num + x] == false){
			doneArray[num + x] = true;
			queueNode *newNode = new queueNode(num, num + x, num, x, 'A', index);
			processingList.push_back(*newNode);
			if(num + x == end){
				found = true;
				break;
			}
		}
	}
	// processingList.erase(processingList.begin());
	// index++;
}

void multSplit(vector<queueNode>& processingList, bool doneArray[], int end, int &index){
	int num = processingList.at(index).currVal;
	int v1, v2, vProd;
	vector<int> splitList;

	string numString = to_string(num);
	for(int i = 1; i < numString.size(); i++){
		v1 = stoi(numString.substr(0,i));
		v2 = stoi(numString.substr(i));
		vProd = v1 * v2;
		if(vProd > 0 && vProd < MAX && doneArray[vProd] == false) {
			doneArray[vProd] = true;
			queueNode *newNode = new queueNode(num, vProd, v1, v2, 'M', index);
			processingList.push_back(*newNode);
			if(vProd == end){
				found = true;
				break;
			}
		}
	}
}

void bitSwap(vector<queueNode>& processingList, bool doneArray[], int end, int &index){
	int num = processingList.at(index).currVal, b1, b2, bsNum;

	string s = bitset<32>(num).to_string();
	

	for(int i = 0; i < s.size()-1; i++){
		string newString = s;
		swap(newString[i],newString[i+1]);
		if (newString != s){
			b1 = 31-i;
			b2 = 31-(i+1);
			bsNum = stoi(newString, nullptr, 2);
			// b1 = 32-i, b2 = 32-(i+1), bsNum = x
			if(bsNum < MAX && doneArray[bsNum] == false) {
				doneArray[bsNum] = true;
				queueNode *newNode = new queueNode(num, bsNum, b1, b2, 'B', index);
				processingList.push_back(*newNode);
				if(bsNum == end){
					found = true;
					break;
				}
			}
		}
		// if(bsNum < MAX) cout << "bit swap " << num << " to " << bsNum << endl;
	}
}

int main(){
	int start, end, chainLength, currIndex = 0, crashCounter = 0;
	int i = 0;
	bool doneArray[MAX];
	vector<queueNode> processingList;
	vector<string> resultOutput;

	cin >> start;
	while(cin){ // read input loop
		cin >> end;
		// cout << start << " to " << end << endl;
		found = false;
		doneInit(doneArray);
		processingList.clear();
		resultOutput.clear();
		chainLength = 1;
		currIndex = 0;

		queueNode *currentNode = new queueNode(start);
		doneArray[currentNode->currVal] = true;
		processingList.push_back(*currentNode);

		while(currIndex < processingList.size()){
			// cout << "working on currIndex " << currIndex << " - " << processingList.size()-1 << " is last index" << endl;
			
			
			
			if(!found){
				multSplit(processingList, doneArray, end, currIndex);
			}
			if(!found){
				bitSwap(processingList, doneArray, end, currIndex);
			}
			if(!found){
				addSub(processingList, doneArray, end, currIndex);
			}

			
			if(found){
				int myIndex = processingList.size()-1;
				queueNode *tailNode;
				
				while(myIndex > -1){
					tailNode = &processingList.at(myIndex);
					if(tailNode->operation == 'A' || tailNode->operation == 'M' || tailNode->operation == 'B')
					resultOutput.push_back("Value: " + to_string(tailNode->currVal));
					switch(tailNode->operation){
						case 'A':
							resultOutput.push_back("Added " + to_string(tailNode->val2));
							chainLength++;
							break;
						case 'M':
							resultOutput.push_back("Multiplied " + to_string(tailNode->val1) + " and " + to_string(tailNode->val2));
							chainLength++;
							break;
						case 'B':
							resultOutput.push_back("Swapped bits " + to_string(tailNode->val2) + " and " + to_string(tailNode->val1));
							chainLength++;
							break;
					}
					// cout << tailNode->val1 << " " << tailNode->operation << " " << tailNode->val2 << " = " << tailNode->currVal << endl;
					myIndex = tailNode->parentNode;
				}
				resultOutput.push_back("Initial Value: " + to_string(start));
				while(resultOutput.size() > 0){
					cout << resultOutput.back() << endl;
					resultOutput.pop_back();
				}
				cout << "Chain length: " << chainLength << endl;
				break;
			}
			currIndex++;
			// crashCounter++;
			// if(crashCounter > 5){
			// 	cout << "crashCounter break" << endl;
			// 	break;
			// }
		}
		if(!found){
			cout << "No solution" << endl;
		}		
		// i++;
		cin >> start;
	}
	
	return 0;
}
