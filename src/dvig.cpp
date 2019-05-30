#include "pyatnashki.h"

void dvig(int (*a)[4], int i, int j, int &c) {
  if (a[i][j] != 0 && i < 4 && i >= 0 && j < 4 && j >= 0) {
    if (a[i][j - 1] == 0 && j != 0) {
      swap(a[i][j], a[i][j - 1]);
      c++;
      return;
    }

    if (a[i][j + 1] == 0 && j != 3) {
      swap(a[i][j], a[i][j + 1]);
      c++;
      return;
    }

    if (a[i + 1][j] == 0 && i != 3) {
      swap(a[i][j], a[i + 1][j]);
      c++;
      return;
    }

    if (a[i - 1][j] == 0 && i != 0) {
      swap(a[i - 1][j], a[i][j]);
      c++;
      return;
    }
  }
}
