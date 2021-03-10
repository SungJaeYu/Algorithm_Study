#include <iostream>
#include <vector>

using std::vector;

int dist[1001][1001];
int ptr[1001][1001];
int lcs2(vector<int> &a, vector<int> &b) {
  for(int i = 1; i <= a.size(); i++){
	  dist[i][0] = i;
	  ptr[i][0] = 2;
  }
  for(int j =1; j <= b.size(); j++){
	  dist[0][j] = j;
	  ptr[0][j] = 1;
  }
  
  for(int j = 1; j <= b.size(); j++){
	  for(int i = 1; i <= a.size(); i++){
		  if(a[i-1] == b[j-1]){
			  dist[i][j] = dist[i-1][j-1];
			  ptr[i][j] = -1; //SAME = -1
		  }
		  else{
			  int diag0 = dist[i-1][j-1] + 2;
			  int left1 = dist[i][j-1] + 1;
			  int down2 = dist[i-1][j] + 1;
		      if(diag0 <= left1 && diag0 <= down2){
				  dist[i][j] = diag0;
				  ptr[i][j] = 0;//DIAG = 0
			  }
			  else if(left1 <= diag0 && left1 <= down2){
				  dist[i][j] = left1;
				  ptr[i][j] = 1;//LEFT = 1
			  }
			  else{
				  dist[i][j] = down2;
				  ptr[i][j] = 2;//DOWN = 2
			  }
		  }
	  }
  }
  int i = a.size();
  int j = b.size();
  int num = 0;
  while(i != 0 || j != 0){
	  int case_i = ptr[i][j];
	  switch(case_i){
		  case -1:
			  num++;
			  i = i -1;
			  j = j -1;
			  break;
		  case 0:
			  i = i - 1;
			  j = j - 1;
			  break;
		  case 1:
			  j = j - 1;
			  break;
		  case 2:
			  i = i - 1;
			  break;
	  }
  }
  return num;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
