#include "pyatnashki.h"

int position(int (*a)[4], int N, int &ik, int &jk) {
  bool f = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] == 0) {
        ik = i;
        jk = j;
        f = true;
        break;
      }
      if (f == true)
        break;
    }
  }
  return ik + jk;
}

TEST_CASE("Poisk pozicii", "[POSITION]") {
  const unsigned int DIM1 = 4;
  const unsigned int DIM2 = 4;
  int N = 4, ik = 0, jk = 0;
  int b[DIM1][DIM2] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

  REQUIRE(position(b, N, ik, jk) == 6);

  int v[4][4] = {{0, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 1}};

  REQUIRE(position(v, N, ik, jk) == 0);

  int p[4][4] = {{2, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 0, 12}, {13, 14, 15, 0}};

  REQUIRE(position(p, N, ik, jk) == 4);

  cout << "[POSITION]" << endl;	
}
