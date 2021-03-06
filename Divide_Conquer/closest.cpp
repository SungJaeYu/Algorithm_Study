#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using std::vector;
using std::string;
using std::pair;
using std::min;

typedef struct Point{
	int x;
	int y;
} Point;

double dist(Point a, Point b){
	return sqrt(((a.x - b.x)*(a.x - b.x))+((a.y - b.y)*(a.y - b.y)));
}

bool compare_strip(Point a, Point b){
	return a.y < b.y;
}

double stripClosest(vector<Point> strip, size_t size, double d){
	double min = d;
	sort(strip.begin(), strip.end(), compare_strip);
	for(size_t i = 0; i < size; i++){
		for(size_t j = (i+1); j < size && ((strip[j].y - strip[i].y) < min); j++){
			double dist_result = dist(strip[i], strip[j]);
			if(dist_result < min){
				min = dist_result;
			}
		}
	}
	return min;
}

bool compare(Point a, Point b){
	return a.x < b.x;
}

double bruteForce(vector<Point> p, size_t left, size_t right){
	double min = std::numeric_limits<double>::max();
	for(size_t i=left; i < right; i++){
		for(size_t j= i + 1; j < right; j++){
			double dist_result = dist(p[i], p[j]);
			if(dist_result < min)
				min = dist_result;
		}
	}
	return min;
}

double minimal_distance(vector<Point> p, size_t left, size_t right) {
	size_t size = right - left;
	if(size <= 3)
		return bruteForce(p, left, right);

	size_t mid = (left+right)/2;
	Point midPoint = p[mid];

	double dl = minimal_distance(p, left, mid);
	double dr = minimal_distance(p, mid, right);

	double d = min(dl, dr);

	vector<Point> strip(size);
	size_t j = 0;
	for(size_t i = left; i < right; i++){
		if(abs(p[i].x - midPoint.x) < d){
			strip[j] = p[i];
			j++;
		}
	}
	strip.resize(j);
	double d_s = stripClosest(strip, j, d);
	return min(d, d_s);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<Point> p(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y;
  }
  sort(p.begin(), p.end(), compare);
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(p, 0, n) << "\n";
}
