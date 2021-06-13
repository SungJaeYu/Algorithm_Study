#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double> v_w(n);
  for(int i=0; i<n; i++){
	  if(capacity==0)
		  return value;
	  double max=0;
	  int max_i=0;
	  for(int j=0; j<n; j++){
		  v_w[j] =((double)values[j]/weights[j]);
		  if(v_w[j] > max){
			  max = v_w[j];
			  max_i = j;
		  }
	  }
	  int a = (weights[max_i]<capacity)?weights[max_i]:capacity;
	  value += a*max;
	  values[max_i] = 0;
	  capacity-=a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
