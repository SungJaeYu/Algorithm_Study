#include <iostream>

int get_fibonacci_last_digit_fast(long long n) {
	n = n % 60;
	if (n <= 1)
		return n;
	
	int x = n;
	int previous = 0;
	int current = 1;

	for (int i = 0; i < x - 1; ++i) {
		int tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		current = current % 10;
	}

	return current % 10;
}

int fibonacci_sum_fast(long long n) {
	int result = get_fibonacci_last_digit_fast(n + 2) - 1;
	if (result < 0) result += 10;
	return result;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
