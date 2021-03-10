#include <iostream>

int get_change(int m) {

	int demo[3] = {1, 3, 4};
	int table[m+1];
	memset(table, 0, sizeof(table));
	
	table[0] = 0;
	table[1] = 1;
	table[2] = 2;
	table[3] = 1;
	for(int i = 4; i <m+1; i++){
		int min = 1000000;
		for(int j = 0; j<3; j++){
			if(table[i-demo[j]] < min){
				min = table[i-demo[j]];
			}
		}
		table[i] = min+1;
	}
		
	return table[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
