#include <iostream>
#include <vector>

using std::vector;

int dist[1001][1001][1001];
int ptr[1001][1001][1001];

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  for(int i = 1; i < a.size(); i++){
	  dist[i][0][0] = i;
	  ptr[i][0] = 2;
  return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
