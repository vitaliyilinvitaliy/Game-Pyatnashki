#include "pyatnashki.h"

extern record rec;

void sort_dat(vector<vector<int> /**/> &s) {
  FILE *tf;

  tf = fopen("records.dat", "ab+");

  fread(&rec, sizeof(rec), 1, tf);
  while (!feof(tf)) {
    vector<int> row;
    row.push_back(rec.count);
    row.push_back(rec.timer);
    s.push_back(row);
    fread(&rec, sizeof(rec), 1, tf);
  }
  fclose(tf);
  sort(s.begin(), s.end());
  if (s.size() > 8) {
    s.erase(s.begin() + 8, s.end());
  }
}
