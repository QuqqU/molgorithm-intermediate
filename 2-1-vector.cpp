#include <bits/stdc++.h>
#define FASTIO cin.sync_with_stdio(false); cin.tie(0);


#include <vector>
using namespace std;

vector<int> vec_int;
vector<char> vec_char;
vector<double> vec_double;

int main() {
	FASTIO;

	vector<int> v;
	// []

	v.push_back(5);
	// [ 5 ]

	v.push_back(3);
	// [ 5 3 ]

	v.push_back(8);
	// [ 5 3 8 ]

	v.pop_back();
	// [ 5 3 ]

	cout << v.size() << endl;
	// 2

	cout << v.empty() << endl;
	// false(0)

	cout << v[1] << endl;
	// 3 of [ 5 3 ]

	int v_size = v.size();
	for (int i = 0; i < v_size; i++)
		cout << v[i] << endl;
	// 5
	// 3

	for (int a : v)
		cout << a << endl;
	// 5
	// 3

	v.clear();
	// []

	cout << v.empty() << endl;
	// true(1)

	return 0;
}
