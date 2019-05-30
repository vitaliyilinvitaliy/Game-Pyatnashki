#include "pyatnashki.h"

void check(int (*a)[4], bool &flag) {
  int i, m;
  for (i = 0, flag = 1, m = 1; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (m < 16 && a[i][j] != m) {
        flag = 0;
        break;
      }
      m++;
    }
  }
}
