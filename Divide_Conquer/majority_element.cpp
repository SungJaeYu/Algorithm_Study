#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int count_majority(vector<int> &a, int left, int right, int majority_number);

int get_majority_elementDC(vector<int> &a, int left, int right) {
  if(left == right) return -1;
  if(left + 1 == right) return a[left];
  int m = (left+right)/2;
  int count_m = (right-left)/2.0;
  int majority_left = get_majority_elementDC(a, left, m);
  int majority_right = get_majority_elementDC(a, m, right);
  
  if(majority_left == majority_right) return majority_left;
  
  int count_left = count_majority(a, left, right,  majority_left);
  int count_right = count_majority(a, left, right, majority_right);
  
  if(count_left > count_m) return majority_left;
  if(count_right > count_m) return majority_right;
  return -1;
}

int count_majority(vector<int> &a, int left, int right, int majority_number){
	int count = 0;
	for(int i=left; i<right; i++){
		if(a[i] == majority_number) ++count;
	}
	return count;
}

int get_majority_element(vector<int> &a){
	int size = a.size();
	vector<int> count(size);
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(a[j] == a[i]) count[i]++;
		}
	}
	int m = size/2;
	for(int i = 0; i < size; i++){
		if(count[i]>m)
			return 1;
	}
	return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_elementDC(a, 0, a.size()) != -1) << '\n';
  /*
  //Test
	while(1){
		vector<int> test;
		srand((unsigned)time(NULL));
		int a = rand()%1000 + 1;
		for(int i = 0; i < a; i++){
			int b = rand() % 1000 + 1;
		    test.push_back(b);
	    }
		int naive_result = (get_majority_element(test) != -1);
		int dc_result = (get_majority_elementDC(test, 0, test.size()) != -1);
		if(naive_result != dc_result){
			std::cout << "Error occured! " << std::endl;
			std::cout << "Naive result : " << naive_result << " DC result : " << dc_result << std::endl;
			std::cout << "Test Case" << std::endl;
			for( int i = 0; i < a; i++){
				std::cout << test[i] << ' ';
			}
			std::cout << std::endl;
		}
	}*/
}
