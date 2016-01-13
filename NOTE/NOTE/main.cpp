#include <iostream>
using namespace std;

const char* ascending = "ascending";
const char* descending = "descending";
const char* mixed = "mixed";

int main(){
	int size = 8;
	bool isAsc = true;
	bool isDsc = true;

	int last = 0;
	int current = 0;
	cin >> last;
	for(int i=1; i<size; i++){
		cin >> current;
		if(last < current)
			isDsc = false;
		if(last > current)
			isAsc = false;
		last = current;
	}

	if(isAsc == true)
		cout << ascending;
	else if(isDsc == true)
		cout << descending;
	else
		cout << mixed;

	return 0;
}