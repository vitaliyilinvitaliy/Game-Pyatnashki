#include "pyatnashki.h"

void zapolnenie(vector<int>& a, int (*b)[4], int N)
{
    for (int i = 0; i < 16; i++) {
        a[i] = i;
    }
    srand(unsigned(time(0)));
    random_shuffle(a.begin(), a.end());

    for (int i = 0, k = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            b[i][j] = a[k];
            k++;
        }
    }
}
