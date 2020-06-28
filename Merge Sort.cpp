#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void combine(vector<int>& input, int p, int q, int r) {

	vector<int> left; vector<int> right;

	for (int i = 0; i < q - p + 1; i++)
		left.push_back(input[i + p]);

	for (int i = 0; i < r - q; i++)
		right.push_back(input[i + q + 1]);
	int k = p, lcount = 0, rcount = 0;

	while (lcount < left.size() && rcount < right.size()) {
		if (left.at(lcount) <= right.at(rcount)) {
			input.at(k) = left.at(lcount);
			lcount++;
			k++;
		}
		else {
			input.at(k) = right.at(rcount);
			rcount++;
			k++;
		}
	}

	while (lcount < left.size()) {
		input.at(k) = left.at(lcount);
		lcount++;
		k++;
	}

	while (rcount < right.size()) {
		input.at(k) = right.at(rcount);
		rcount++;
		k++;
	}
}

void merge_sort(vector<int>& input, int p, int r) {
	int q = 0;
	if (p < r) {
		q = floor((p + r) / 2);
		merge_sort(input, p, q);
		merge_sort(input, (q + 1), r);
		combine(input, p, q, r);
	}
}


void print(vector<int> const &data)
{
	for (int i = 0; i < data.size(); i++)
		cout << data.at(i) << ' ';
	cout << endl;
}

int main() {
	int size;
	cin >> size;
	vector<int> data(size);
	int counter = -1;
	int one_value = 0;
	while (++counter < size && cin >> one_value) {
		data.at(counter) = one_value;
	}

	merge_sort(data, 0, size - 1);
	print(data);
	return 0;
}