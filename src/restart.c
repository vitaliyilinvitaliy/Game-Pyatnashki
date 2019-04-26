#include "pyatnashki.h"

extern void zapolnenie(vector<int> &, int (*)[4], int);

extern void position(int (*)[4], int, int &, int &);

void restart(vector<int> &a, int (*b)[4], int N, int &ik, int &jk,
             int &countt) {
  zapolnenie(a, b, 5);
  position(b, 4, ik, jk);
  countt = 0;
}
