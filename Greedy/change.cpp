#include <iostream>

int get_change(int m) {
  int coin[3] = {10, 5, 1};
  int i=0;
  int n=0;
  while(m>0){
	  if(m<coin[i]){
		  ++i;
		  continue;
	  }
	  n+=(m/coin[i]);
	  m=m%coin[i];
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
