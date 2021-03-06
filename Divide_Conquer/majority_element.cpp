#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int count_majority(vector<int> &a, int majority_number);

int get_majority_elementDC(vector<int> &a, int left, int right) {
  if(left == right) return -1;
  if(left + 1 == right) return a[left];
  int m = (left+right)/2;
  int majority_left = get_majority_elementDC(a, left, m);
  int majority_right = get_majority_elementDC(a, m+1, right);
  if(majority_left == majority_right) return majority_left;
  int count_left = count_majority(a, majority_left);
  int count_right = count_majority(a, majority_right);
  if(count_left > m) return majority_left;
  if(count_right > m) return majority_right;
  return -1;
}

int count_majority(vector<int> &a, int majority_number){
	int count = 0;
	int size = a.size();
	for(int i=0; i<size; i++){
		if(a[i] == majority_number) ++count;
	}
	return count;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_elementDC(a, 0, a.size()) != -1) << '\n';
}
