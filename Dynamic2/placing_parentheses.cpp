#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

//Dynamic Table
//3 Dimensional
//[][][0] <- Max
//[][][1] <- Min
long long value[30][30][2];
void set_min_max_value(size_t i, size_t j, vector<char> &op);

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
	//string to two vectors(Numbers, Operations)
	vector<char> op;
	vector<int> num;
	for(int i = 0; i < exp.size(); ++i){
		if(exp[i] <'0' || exp[i] > '9'){
			op.push_back(exp[i]);
		}
		else{
			num.push_back(exp[i]-'0');
		}
	}

	//Initialize
	for(int i = 0; i < num.size(); ++i){
		value[i][i][0] = (long long)num[i];
		value[i][i][1] = (long long)num[i];
	}

	//Fill the value table
	//sequence like below
	//0-1 1-2 2-3 ... (N-1)-N
	//0-2 1-3 2-4 ... (N-2)-N
	//...
	//0-N
	for(int s = 1; s < num.size(); ++s){
		for(int i = 0; i < num.size() - s; ++i){
			int j = i + s;
			set_min_max_value(i, j, op);
		}
	}

	//return 0-N
	return value[0][num.size()-1][0];
}

void set_min_max_value(size_t i, size_t j, vector<char> &op){
	long long min_val = 1000000;
	long long max_val = -1000000;
	//Calculate Min Max value
	for(int k = i; k < j; ++k){
		long long MM = eval(value[i][k][0], value[k+1][j][0], op[k]);
		long long Mm = eval(value[i][k][0], value[k+1][j][1], op[k]);
		long long mM = eval(value[i][k][1], value[k+1][j][0], op[k]);
		long long mm = eval(value[i][k][1], value[k+1][j][1], op[k]);
		min_val = min(min(min(min(min_val, MM), Mm), mM), mm);
		max_val = max(max(max(max(max_val, MM), Mm), mM), mm);
	}
	value[i][j][0] = max_val;
	value[i][j][1] = min_val;
	return;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
