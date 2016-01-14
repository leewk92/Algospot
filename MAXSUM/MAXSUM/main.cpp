#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}

int main(){

	int T;
	cin >> T;

	while(T-- > 0){
		int N;
		cin >> N;
		vector<int> data;		
		for(int i=0; i<N; i++){
			int val;
			cin >> val;
			data.push_back(val);
		}
		int maxendinghere = 0;
		int maxsofar = 0;

		for(int i=0;i<N;i++){
			
			maxendinghere = max( maxendinghere + data[i], 0);
			maxsofar = max(maxsofar, maxendinghere);    
      
		}
		cout << maxsofar<<endl;
	}
	return 0;
}

