#include "pyatnashki.h"

int dvig(int (*a)[4], int i, int j, int &c) {
	if (a[i][j] != 0 && i < 4 && i >= 0 && j < 4 && j >= 0) {
		if (a[i][j - 1] == 0 && j != 0) {
			swap(a[i][j], a[i][j - 1]);
			c++;
			return 1;
		}

		if (a[i][j + 1] == 0 && j != 3) {
			swap(a[i][j], a[i][j + 1]);
			c++;
			return 2;
		}

		if (a[i + 1][j] == 0 && i != 3) {
			swap(a[i][j], a[i + 1][j]);
			c++;
			return 3;
		}

		if (a[i - 1][j] == 0 && i != 0) {
			swap(a[i - 1][j], a[i][j]);
			c++;
			return 4;
		}
	}
	return 0;
}

TEST_CASE("DVIG", "[DVIGENIE]") {
	const unsigned int DIM1 = 4;
	const unsigned int DIM2 = 4;

	int c;
	int a[DIM1][DIM2] = {
	    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

	REQUIRE(dvig(a, 0, 0, c) == 0);
	int b[DIM1][DIM2] = {
	    {13, 14, 15, 0}, {5, 6, 7, 8}, {1, 2, 3, 4}, {9, 10, 11, 12}};
	REQUIRE(dvig(b, 0, 2, c) == 2);
	int d[DIM1][DIM2] = {
	    {13, 14, 15, 0}, {5, 6, 7, 8}, {1, 2, 3, 4}, {9, 10, 11, 12}};
	REQUIRE(dvig(d, 1, 3, c) == 4);

	int e[DIM1][DIM2] = {
	    {13, 14, 15, 0}, {5, 6, 7, 8}, {1, 2, 3, 4}, {9, 10, 11, 12}};
	REQUIRE(dvig(e, 0, 3, c) == 0);
	int f[DIM1][DIM2] = {
	    {13, 14, 0, 15}, {5, 6, 7, 8}, {1, 2, 3, 4}, {9, 10, 11, 12}};
	REQUIRE(dvig(f, 0, 3, c) == 1);
}
