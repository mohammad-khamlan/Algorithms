#include <iostream>
#include "string"
#include <vector>
#include <algorithm>
using namespace std;

void longestCommonSubsequence(string text1, string text2) {
	int t1 = text1.length(), t2 = text2.length();
	vector<vector<int>> lcs(t1+1, vector<int>(t2+1));
	
	for (int i = 0; i <= t1; i++)
	{
		for (int j = 0; j <= t2; j++)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;

			else if (text1[i - 1] == text2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;

			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout<< lcs[t1][t2];
}

int main() {
	longestCommonSubsequence("JAVABLOG","ABLGOUTPUT");
}
