#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
	if (n <= 1) return n;
	vector<int> Fibo(n+1);
	Fibo[0] = 0;
	Fibo[1] = 1;
	for (int i = 2; i < n+1; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}
    return Fibo[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 30; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    cin >> n;
    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
