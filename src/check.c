#include "pyatnashki.h"

void check(int (*a)[4], int N, bool& flag)
{
    int i, m, j;
    for (i = 0, flag = 1, m = 1; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            if (m < 16 && a[i][j] != m) {
                flag = 0;
                break;
            }
            m++;
        }
    }
}
