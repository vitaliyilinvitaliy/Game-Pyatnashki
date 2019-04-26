#include "pyatnashki.h"

void print(int (*a)[4], int N, int countt, double now) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] != 0)
        printf("%3d ", a[i][j]);
      else
        printf("    ");
    }
    cout << endl;
  }
  cout << endl << endl << "COUNT: " << countt << endl;
}
