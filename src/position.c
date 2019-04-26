#include "pyatnashki.h"

void position(int (*a)[4], int N, int &ik, int &jk) {
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
}
