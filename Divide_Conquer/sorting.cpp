#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l + 1 >= r) {
    return;
  }

  int k = l + rand() % (r - l);
  swap(a[l], a[k]);

  //3 Way Partition
  int x = a[l];
  int m1 = l;
  int m2 = r - 1;
  int cur = l + 1;
  int cnt;
  int cnt_max = r-l-1;
  for( cnt= 0; cnt < cnt_max; cnt++) {
	  if( x < a[cur]){
		  swap(a[m2], a[cur]);
		  m2--;
		  continue;
	  }
	  if( x > a[cur]){
		  swap(a[m1], a[cur]);
		  m1++;
		  cur++;
		  continue;
	  }
	  if( x == a[cur]){
		  cur++;
		  continue;
	  }
  }
  //3 Way Partition

  randomized_quick_sort(a, l, m1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size());
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  /* 
  //Test
  while(1){
	vector<int> test;
	srand((unsigned)time(NULL));
	int a = rand() % 100 + 1;
	for( int i = 0; i < a; i++){
		int b = rand() % 100 + 1;
		test.push_back(b);
	}
	vector<int> test_qs = test;
	sort(test.begin(), test.end());
	randomized_quick_sort(test_qs, 0, test.size());
	for(int i = 0; i < a; i++){
		if(test[i] != test_qs[i]){
			std::cout << "Error Occured!" << std::endl;
			std::cout << "Quick Sort : ";
			for(int j = 0; j < a; j++){
				std::cout << test_qs[j] << ' ';
			}
			std::cout << std::endl;
			std::cout << "Sort : ";
			for(int j =0; j<a; j++){
				std::cout << test[j] << ' ';
			}
			std::cout << std::endl;
			break;
		}
	}
	
  }
  */
	
}
