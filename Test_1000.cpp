#include<iostream>
#include<vector>
#include<set>
#include<stdlib.h>
#include<algorithm>
#include<ctime>

using namespace std;

bool increase_comp(const int a, const int b) {
	return a < b;
}

bool decrease_comp(int a, int b) {
	return a > b;
}

int main() {
	srand(time(NULL));
	int n;
	cin >> n;

	vector<vector<int>> v_arr;
	v_arr.resize(n);
	set<int> sizes;

//CREATING UNIQUE SIZES
	for (int i = 0; i < n; i++) {
		int size = rand()%1000;
		while (sizes.find(size) != sizes.end()) {
			size = rand() % 1000;
		}
		sizes.emplace(size);
		v_arr[i].resize(size);
	}

//FILLING ARRAYS (VECTORS)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v_arr[i].size(); j++) {
			v_arr[i][j] = rand();
		}
	}

//SORTING EVEN ARRAYS (0, 2, 4, ...)
	for (int i = 0; i < n; i += 2) {
		sort(v_arr[i].begin(), v_arr[i].end(), increase_comp);
	}

//SORTING ODD ARRAYS (1, 3, 5, ...)
	for (int i = 1; i < n; i += 2) {
		sort(v_arr[i].begin(), v_arr[i].end(), decrease_comp);
	}

//OUTPUT
	for (int i = 0; i < n; i++) {
		for (auto it = v_arr[i].begin(); it != v_arr[i].end(); it++) {
			cout << *it << "\t";
		}
		cout << "\n";
	}
	return 0;
}