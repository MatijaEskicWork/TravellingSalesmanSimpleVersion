#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	int N1 = 8;
	int N2 = 12;

	float sol1 = 100000000.0, sol2 = 10000000.0;
	vector<pair<float, float>> v1{ {62.0, 58.4},{57.5, 56.0},{51.7, 56.0},{67.9, 19.6},{57.7, 42.1},
									{54.2, 29.1},{46.0, 45.1 },{34.7, 45.1} };

	vector<pair<float, float>> v2{ {62.0, 58.4},{57.5, 56.0},{51.7, 56.0},{67.9, 19.6},{57.7, 42.1},
									{54.2, 29.1},{46.0, 45.1},{34.7, 45.1},{45.7, 25.1},{34.7, 26.4},
									{28.4, 31.7},{33.4, 60.5} };
	
	vector<pair<float, float>> cpy1 = v1;
	vector<pair<float, float>> cpy2 = v2;

	vector<pair<float, float>> solV1, solV2;

	auto L1 = [](pair<float, float> x1, pair<float, float> x2) {
		float k1 = abs(x1.first - x2.first);
		float k2 = abs(x1.second - x2.second);
		return k1 + k2;
	};
	while (next_permutation(v1.begin(), v1.end())) {
		float tmp = 0.0;
		for (int i = 0; i < v1.size() - 1; i++) {
			tmp += L1(v1[i], v1[i + 1]);
		}
		if (tmp < sol1) {
			solV1 = v1;
			sol1 = tmp;
		}
	}


	while (next_permutation(v2.begin(), v2.end())) {
		float tmp = 0.0;
		for (int i = 0; i < v2.size() - 1; i++) {
			tmp += L1(v2[i], v2[i + 1]);
		}
		if (tmp < sol2) {
			solV2 = v2;
			sol2 = tmp;
		}
	}



	cout << "Cost for a) assignment: " << sol1 << endl;
	float x = 0;
	cout << "Path for a) assignment: ";
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N1; j++) {
			if (solV1[i] == cpy1[j]) {
				cout << j + 1 << " ";
				break;
			}
		}
		if (i != N1 - 1) {
			cout << "-> ";
		}
	}
	cout << endl;

	cout << endl;

	cout << "Cost for b) assignment: " << sol2 << endl;
	cout << "Path for b) assignment: ";
	x = 0.0;
	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < N2; j++) {
			if (solV2[i] == cpy2[j]) {
				cout << j + 1 << " ";
				break;
			}
		}
		if (i != N2 - 1) {
			cout << "-> ";
		}
	}
	cout << endl;
	return 0;
}