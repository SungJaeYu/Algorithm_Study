#include <iostream>
#include <vector>
#include <memory.h>

using std::vector;


int value[1000][1000];
//Dynamic Table
int backtrace[1000][1000];
//Backtrace 
//0 : ith number not used, 1 : ith number used

int partition3(vector<int> &A) {
    int sum=0;
	for(int i=1; i<A.size(); ++i){
		sum+=A[i];
	}
	//Knapsack Weight == (sum of numbers)/3
	const int W = sum/3;
	
	for(int k = 0; k < 3; ++k){
		memset(value, 0, sizeof(value));
		memset(backtrace, 0, sizeof(backtrace));
		//Knapsack Algorithm
		for(int i = 1; i<A.size(); ++i){
			for(int w = 1; w <= W; ++w){
				value[w][i] = value[w][i-1];
				backtrace[w][i] = 0;
				if(A[i] <= w){
					int val = value[w-A[i]][i-1] + A[i];
					if(value[w][i] < val){
						value[w][i] = val;
						backtrace[w][i] = 1;
					}

				}
			}
		}
		if(value[W][A.size()-1] != W)
			return 0;

		//Backtrace to Remove used Numbers
		//Members in the Knapsack -> vector B
		vector<int> B;
		int cur_w = W;
		int cur_i = A.size() - 1;
		while(cur_w != 0 || cur_i != 0){
			if(backtrace[cur_w][cur_i] == 0)
				cur_i = cur_i - 1;
			else{
				B.push_back(cur_i);
				cur_w = cur_w - A[cur_i];
				cur_i = cur_i - 1;
			}
		}
		
		//Remove Used Numbers
		for(int i = 0; i < B.size(); i++){
			A.erase(A.begin() + B[i]);
		}
	}
	return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n+1);
  for (size_t i = 1; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
