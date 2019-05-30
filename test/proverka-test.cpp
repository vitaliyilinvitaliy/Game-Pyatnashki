#include "pyatnashki.h"

bool proverka(vector<int> &a) {
	int inv = 0;
	for (int i = 0; i < 16; ++i)
		if (a[i])
			for (int j = 0; j < i; ++j)
				if (a[j] > a[i]) ++inv;
	for (int i = 0; i < 16; ++i)
		if (a[i] == 0) inv += 1 + i / 4;
	if (inv % 2 == 0)
		return 1;
	else
		return 0;
}

TEST_CASE("TEST PROVERKA", "[PROVERKA]") {
	vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14, 0};
	REQUIRE(proverka(b) == 0);
	vector<int> n = {13, 3, 11, 1, 5, 12, 9, 4, 10, 6, 15, 2, 0, 7, 14, 8};
	REQUIRE(proverka(n) == 1);

	vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 13, 15, 14};
	REQUIRE(proverka(c) == 0);
	vector<int> d = {15, 2, 13, 10, 3, 5, 7, 9, 14, 0, 1, 4, 12, 8, 11, 6};
	REQUIRE(proverka(d) == 1);

	vector<int> e = {1, 2, 3, 0, 5, 6, 7, 4, 9, 10, 11, 8, 13, 15, 14, 12};
	REQUIRE(proverka(e) == 0);
	vector<int> f = {15, 3, 11, 13, 7, 8, 6, 14, 10, 2, 12, 0, 1, 5, 8, 4};
	REQUIRE(proverka(f) == 0);

	vector<int> g = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 0, 14};
	REQUIRE(proverka(g) == 0);
	vector<int> h = {4, 5, 12, 10, 1, 13, 6, 14, 7, 3, 11, 2, 0, 15, 9, 8};
	REQUIRE(proverka(h) == 1);
	cout << "[PROVERKA]" << endl;
}
