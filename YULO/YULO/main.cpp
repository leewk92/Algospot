#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
using namespace std;

double solve(deque<double> scores){
	sort(scores.begin(),scores.end());
	double avgval = 0;
	while(scores.size() >= 2){

		double minval = scores.front();
		double maxval = scores.back();
		double curAvgval = (minval + maxval)/2;
		scores.pop_front();
		scores.pop_back();
		if(avgval < curAvgval )
			avgval = curAvgval;

		if(scores.size() == 1){			
			if(avgval < scores.front())
				avgval = scores.front();		
		}
	}
	return avgval;
}


int main(){

	int T;
	cin >> T;
	while(T-- >0){
		int N;
		cin >> N;
		deque<double> scores;
		for(int i=0; i<N; i++){
			double tmpScore;
			cin >> tmpScore;
			scores.push_back(tmpScore);
		}
		printf("%.1lf\n",solve(scores));

	}
	return 0;
}