#include <iostream>
#include <vector>

using std::vector;

int value[10000][10000];

int optimal_weight(int W, const vector<int> &w) {
    for (size_t i = 1; i < w.size(); ++i) {
		for(size_t j = 1; j <= W; ++j){
			value[j][i] = value[j][i-1];
			if(w[i] <= j){
				int val = value[j-w[i]][i-1] + w[i];
				if(value[j][i] < val)
					value[j][i] = val;
			}
		}
    }
    return value[W][w.size()-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n+1);
  for (int i = 1; i <= n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
