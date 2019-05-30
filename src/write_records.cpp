#include "pyatnashki.h"

extern record rec;

void write_records(int count, clock_t time_finish) {
  FILE *tf;
  rec.count = count;
  rec.timer = time_finish;
  tf = fopen("records.dat", "ab");
  fwrite(&rec, sizeof(rec), 1, tf);
  fclose(tf);
}
