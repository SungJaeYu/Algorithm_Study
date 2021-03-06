#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<long long> &a, long long x) {
  int left = 0, right = (int)a.size(); 
  while(left<right)
  {
	  int median = (left+right)/2;
	  if(a[median] == x) return median;
	  if(a[median] < x)
	  {
		  left = median + 1;
	  }
	  else
	  {
		  right = median;
	  }
  }
  return -1;
}

int linear_search(const vector<long long> &a, int x) {
	for(size_t i = 0; i < a.size(); i++){
		if ( a[i] == x) return i;
	}
	return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
	/*
	//Test
	int test_count = 0;
	while(1){
		vector<long long> test_array1;
		vector<long long> test_array2;
		srand((unsigned)time(NULL));
		int a = rand() % 1000 + 1;
		for (int i = 0; i < a; i++){
			int b = rand() % 1000 + 1;
			int c = rand() % 1000 + 1;
			test_array1.push_back(b);
			test_array2.push_back(c);
		}
		sort(test_array1.begin(), test_array1.end());
		for(int i = 0; i < a; i++){
			long long test_num = test_array2[i];
			long long lin_result = linear_search(test_array1, test_num);
			long long bin_result = binary_search(test_array1, test_num);
			if( test_array1[lin_result] != test_array1[bin_result]){
				std::cout << "Error Occured!" << std::endl;
				std::cout << "Test Number : " << test_num << std::endl;
				std::cout << "Test Case : ";
				for(int j = 0; j < a; j++){
					std::cout << test_array1[j] << ' ';
				}
				std::cout << std::endl;
				std::cout << "Linear Result : " << lin_result << std::endl;
				std::cout << "Binary Result : " << bin_result << std::endl;
				break;
			}
		}
		std::cout << "Test Case #" << test_count << " Clear" << std::endl;
		++test_count;
	}
	*/
}
