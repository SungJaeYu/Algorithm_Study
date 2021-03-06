#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = (left + right) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  size_t i_left = left;
  size_t i_right = ave;
  size_t i_b = left;
  while(i_left < ave && i_right < right){
	  if(a[i_left] <= a[i_right]){
		  b[i_b] = a[i_left];
		  i_b++;
		  i_left++;
	  }
	  else{
		  b[i_b] = a[i_right];
		  i_b++;
		  i_right++;
		  number_of_inversions += (ave - i_left);
	  }
  }

  if(i_left >= ave){
	  for(int j=i_right; j<right; j++){
		  b[i_b] = a[j];
		  i_b++;
	  }
  }
  else{
	  for(int j=i_left; j<ave; j++){
		  b[i_b] = a[j];
		  i_b++;
	  }
  }
  for ( size_t i = left; i<right; i++){
	  a[i] = b[i];
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

}
