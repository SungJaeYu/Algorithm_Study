#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fibonacci_sum_squares_fast(long long n) {
	int result = get_fibonacci_last_digit_fast(n + 1)*get_fibonacci_last_digit_fast(n);
	result = result % 10;
	return result;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
