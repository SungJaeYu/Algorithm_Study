#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  size_t segment_size = starts.size();
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  for(int i=0; i<points.size(); i++){
	//binary search
	  size_t l_s = 0;
	  size_t r_s = segment_size;
	  size_t l_e = 0;
	  size_t r_e = segment_size;
	  int c1 = 0;
	  int c2 = 0;
	  
	  //left ends after the point
	  while(l_s!=r_s){
		  size_t m_s = (l_s+r_s)/2;
		  if(starts[m_s]<points[i])
			  l_s = m_s + 1;
		  else
			  r_s = m_s;
	  }
	  c1 = segment_size - l_s - 1;
	  
	  // right ends before point
	  while(l_e!=r_e){
		  size_t m_e = (l_e + r_e)/2;
		  if(ends[m_e] < points[i])
			  r_s = m_e;
		  else
			  l_s = m_e + 1;
	  }
	  //if(ends[l_e]<=points && ends[l_e+1]>points)
	  c2 = l_e + 1;
	  

	  cnt[i] = segment_size - c1 - c2;
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
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
