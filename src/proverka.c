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
