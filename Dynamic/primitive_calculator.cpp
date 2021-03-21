#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  int opertation[3] = {1, 3, 4};
  int table[n+1][2];
  memset(table, 0, sizeof(table));
  int edge[3];
  for(int i = 2; i < n+1; i++){
	  for(int k = 0; k < 3; k++){
		  edge[k] = 1000000;
	  }
	  if(i%3 == 0){
		  edge[2] = table[i/3][0] + 1;
	  }
	  if(i%2 == 0){
		  edge[1] = table[i/2][0] + 1;
	  }
	  edge[0] = table[i-1][0] + 1;
	  int min = edge[0];
	  int min_i = 0;
	  for(int j = 1; j < 3; j++){
		  if(edge[j] < min){
			  min = edge[j];
			  min_i = j;
		  }
	  }
	  table[i][0] = min;
	  table[i][1] = min_i;
  }

  while(n >= 1){
	  sequence.push_back(n);
	  int case_back = table[n][1];
	  switch(case_back){
		  case 0:
			  n = n-1;
			  break;
		  case 1:
			  n = n/2;
			  break;
		  case 2:
			  n = n/3;
			  break;
	  }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
