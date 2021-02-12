#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	long long sum = 0;

	long long current = 0;
	long long next = 1;

	for (long long i = 0; i <= to; ++i) {
		if (i >= from) {
			sum += current;
		}

		long long new_current = next;
		next = next + current;
		current = new_current;
	}

	return sum % 10;
}

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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
	int result = get_fibonacci_last_digit_fast(to + 2) - get_fibonacci_last_digit_fast(from + 1);
	if (result < 0) result += 10;
	return result;
}



int main() {
	long long from, to;
	std::cin >> from >> to;
	std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
