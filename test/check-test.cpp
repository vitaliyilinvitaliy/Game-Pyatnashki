#include "pyatnashki.h"

int check(int (*a)[4], int N, int &flag) {
	int i, m, j;
	for (i = 0, flag = 1, m = 1; i < N; i++) {
		for (j = 0; j < 4; j++) {
			if (m < 16 && a[i][j] != m) {
				flag = 0;
				break;
			}
			m++;
		}
	}
	return flag;
}

TEST_CASE("Proverka yporyadochennsti", "[CHECK]") {
	const unsigned int DIM1 = 4;
	const unsigned int DIM2 = 4;

	int b[DIM1][DIM2] = {
	    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

	int flag = 0;
	REQUIRE(check(b, 4, flag) == 1);

	int a[4][4] = {
	    {1, 4, 5, 6}, {12, 15, 13, 2}, {3, 7, 8, 9}, {10, 11, 14, 0}};
	REQUIRE(check(a, 4, flag) == 0);

	int c[4][4] = {
	    {1, 4, 5, 6}, {15, 0, 13, 2}, {12, 7, 8, 9}, {3, 10, 11, 14}};
	REQUIRE(check(c, 4, flag) == 0);

	int d[4][4] = {
	    {0, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
	REQUIRE(check(d, 4, flag) == 0);

	int f[4][4] = {
	    {6, 5, 4, 1}, {2, 13, 15, 12}, {9, 8, 7, 3}, {0, 14, 11, 10}};
	REQUIRE(check(f, 4, flag) == 0);

	int g[4][4] = {
	    {4, 1, 6, 5}, {15, 12, 2, 13}, {7, 3, 9, 8}, {11, 10, 0, 14}};
	REQUIRE(check(g, 4, flag) == 0);

	cout << "[CHECK]" << endl;
}
