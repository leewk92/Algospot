#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int INF = 100000000;


struct comp { 
  bool operator() (const int& left, const int& right) const 
  {return left>right;} 
}; 


int main(){

	int C;
	cin >> C;
	while(C-- >0){
		int bookN;
		int storeN;
		cin >> bookN;
		cin >> storeN;
		vector<int> store;
		vector<int> saleV;
		map<int,int,comp> *data = new map<int,int,comp>[storeN];
		
		
		for(int i=0; i<storeN; i++){
			store.push_back(0);
			saleV.push_back(0);
		}

		
		for(int i=0; i<bookN; i++){
			for(int j=0; j<storeN; j++){
				int price;
				int sale;
				cin >> price;
				cin >> sale;
				
				data[j][sale] =  price;
			}
		}
	

		for(int i=0; i<storeN; i++){
			for (map<int,int>::iterator it = data[i].begin(); it != data[i].end(); it++){
	
				int price = it->second;
				int sale = it->first;
				cout << price << ", " << sale;
				if(i==0){
					it->second += price;
					saleV[i] = sale;
				}
				else{
					if(saleV[i] - price >= 0){
						saleV[i] = saleV[i] - price;
					}else{
						store[i] += price - saleV[i];
						saleV[i] = 0;
					}
				}
				
			}cout << endl;
		}
		int minIndex = 0;
		int minPrice = store[0];
		for(int i=1; i<store.size(); i++){
			if(minPrice > store[i]){
				minPrice = store[i];
				minIndex = i;
			}
		}
		cout << minPrice <<endl;
	}

}