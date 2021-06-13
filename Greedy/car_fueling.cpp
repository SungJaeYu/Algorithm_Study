#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefills = 0;
    int currentRefill = 0;
    int n = stops.size();
    while(currentRefill<=n)
    {
        int lastRefill = currentRefill;
        while(currentRefill <= n && (stops[currentRefill+1]-stops[lastRefill]) <= tank)
        {
            ++currentRefill;
        }
        if(currentRefill == lastRefill)
        {
            return -1;
        }
        if(currentRefill <= n)
        {
            ++numRefills;
        }
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops[0] = 0;
    stops[n+1] = d;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
