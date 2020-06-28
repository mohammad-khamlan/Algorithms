#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

/*int minimum(int x, int y, int z) {
	if (x < y && x < z) return x;
	else if (y < x && y < z) return y;
	else return z;
}

int minDistance(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();
	int cost = 0;

	if (m == 0) return n;
	if (n == 0) return m;

	if (word1[m - 1] == word2[n - 1])
		cost = 0;
	else cost = 1;

	return  minimum(minDistance(word1, word2.substr(0, n - 1)) + 1 ,
	                minDistance(word1.substr(0, m - 1), word2) + 1,
					minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1)) + cost);
}*/

int minDistance(string word1, string word2)
{
	int m = word1.length();
	int n = word2.length();

	vector<vector<int>> dist(m + 1, vector<int>(n + 1));

	for (int i = 1; i <= m; i++)
		dist[i][0] = i;				

	for (int j = 1; j <= n; j++)
		dist[0][j] = j;				

	int cost;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (word1[i - 1] == word2[j - 1])   			 
				cost = 0;   			
			else
				cost = 1;   			 

			dist[i][j] = min(min(dist[i - 1][j] + 1, dist[i][j - 1] + 1), dist[i - 1][j - 1] + cost); 
		}
	}

	return dist[m][n];
}


int main() {
	
	cout<< minDistance("algorithm", "altruistic");
	
}


