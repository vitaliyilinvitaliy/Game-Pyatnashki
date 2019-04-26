#include "pyatnashki.h"

bool proverka(vector<int> &a) {
  int inv = 0;
  for (int i = 0; i < 16; ++i)
    if (a[i])
      for (int j = 0; j < i; ++j)
        if (a[j] > a[i])
          ++inv;
  for (int i = 0; i < 16; ++i)
    if (a[i] == 0)
      inv += 1 + i / 4;
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
}
