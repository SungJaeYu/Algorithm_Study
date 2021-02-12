#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
	if (n <= 1)
		return n;
	bool pattern_flag = false;
	long long pattern_size = 0;
	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		current = current % m;
		if (previous == 0 && current == 1) {
			pattern_size = i + 1;
			pattern_flag = true;
			break;
		}
	}
	if (pattern_flag == false)
		return current;
	previous = 0;
	current = 1;
	n = n%pattern_size;
	if (n <= 1)
		return n;
	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		current = current % m;
	}
	return current;
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
