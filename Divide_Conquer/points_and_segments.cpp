#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  size_t size_p = points.size();
  vector<int> cnt(size_p);
  size_t size_s = starts.size();
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  for(int i=0; i<size_p; i++){
	//binary search
	  size_t l_s = 0;
	  size_t r_s = size_s;
	  size_t l_e = 0;
	  size_t r_e = size_s;
	  int c1 = 0;
	  int c2 = 0;
	  
	  //left ends after the point
	  while(l_s < r_s){
		  size_t m_s = (l_s+r_s)/2;
		  if(starts[m_s]<=points[i])
			  l_s = m_s + 1;
		  else
			  r_s = m_s;
	  }
	  c1 = size_s - l_s;
	  
	  // right ends before point
	  while(l_e < r_e){
		  size_t m_e = (l_e + r_e)/2;
		  if(ends[m_e] < points[i])
			  l_e = m_e + 1;
		  else
			  r_e = m_e;
	  }
	  c2 = l_e;
	  

	  cnt[i] = size_s - c1 - c2;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
/*
   //Test
  while(1){
	  srand((unsigned)time(NULL));
	  int size = rand()%100 + 1;
	  vector<int> starts(size);
	  vector<int> ends(size);
	  vector<int> points(size);
	  for(int i = 0; i < size; i++){
		  int a = rand() % 100;
		  int b = rand() % 100 + 1;
		  int c = rand() % 100;
		  starts[i] = a;
		  ends[i] = starts[i] + b;
		  points[i] = c;
	  }
	  vector<int> cnt_fast = fast_count_segments(starts, ends, points);
	  vector<int> cnt_naive = naive_count_segments(starts, ends, points);
	  if(cnt_fast != cnt_naive){
		  std::cout << "Error Occured!" << std::endl;
		  std::cout << "Segment" << std::endl;
		  for(int i = 0; i < size; i++){
			  std::cout << starts[i] << ' ' << ends[i] << std::endl;
		  }
		  std::cout << "Points" << std::endl;
		  for(int i = 0; i < size; i ++){
			  std::cout << points[i] << ' ';
		  }
		  std::cout << std::endl;
		  std::cout << "Fast Count : ";
		  for(int i = 0; i< size; i++){
			  std::cout << cnt_fast[i] << ' ';
		  }
		  std::cout << std::endl;
		  std::cout << "Naive Count : ";
		  for(int i = 0; i < size; i++){
			  std::cout << cnt_naive[i] << ' ';
		  }
		  std::cout << std::endl;
	  }
  }
  */
}
