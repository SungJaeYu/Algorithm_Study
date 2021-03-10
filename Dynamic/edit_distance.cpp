#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using std::string;
int dist[1001][1001];

int edit_distance(const string &str1, const string &str2) {
  for(int i = 1; i<=str1.length(); i++)
	  dist[i][0] = i;
  for(int j = 1; j<=str2.length(); j++)
	  dist[0][j] = j;

  for(int j=1; j<=str2.length(); j++){
	  for(int i=1; i<=str1.length(); i++){
		  if(str1[i-1] == str2[j-1])
			  dist[i][j] = dist[i-1][j-1];
		  else
			  dist[i][j] = min(dist[i-1][j-1]+1, min(dist[i][j-1]+1, dist[i-1][j]+1));
	  }
  }
  return dist[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
