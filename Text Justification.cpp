#include <iostream>
#include "string"
#include <vector>
#include "math.h"
using namespace std;

void Fullyjustify(string words[], int width) {
	int size = sizeof(words[0]) / sizeof(words);
	vector<vector<int>> cost(size, vector<int>(size));

	for (int i = 0; i < size; i++) {
		cost[i][i] = width - words[i].length();
		for (int j = i + 1; j < size; j++) {
			cost[i][j] = cost[i][j - 1] - words[j].length() - 1;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (cost[i][j] < 0) {
				cost[i][j] = INT_MAX;
			}
			else {
				cost[i][j] = (int)pow(cost[i][j], 2);
			}
		}
	}

	int minCost[7];
	int result[7];

	for (int i = size - 1; i >= 0; i--) {
		minCost[i] = cost[i][size - 1];
		result[i] = size;
		for (int j = size - 1; j > i; j--) {
			if (cost[i][j - 1] == INT_MAX) {
				continue;
			}
			if (minCost[i] > minCost[j] + cost[i][j - 1]) {
				minCost[i] = minCost[j] + cost[i][j - 1];
				result[i] = j;
			}
		}
	}
	int i = 0;
	int j = 0;


	do {
		j = result[i];
		for (int k = i; k < j; k++) {
			cout << (words[k] + " ");
		}
		cout << ("\n");
		i = j;
	} while (j < size);

}

int main() {
	string words[7] = { "i", "want", "learn", "programming", "in", "c++", "language" };
	Fullyjustify(words, 16);
}	







