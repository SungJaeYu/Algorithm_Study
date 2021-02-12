#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b) {
	int R;
	while ((a%b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}

long long lcm_fast(int a, int b) {
	long long lcm = (long long)a * b / (long long)gcd_fast(a, b);
	return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
