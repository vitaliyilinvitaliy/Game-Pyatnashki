#include "libconio/conio.c"
#include "libconio/conio.h"
#include "pyatnashki.h"

extern void print(int (*)[4], int);
extern void check(int (*)[4], int, bool&);
extern void zapolnenie(vector<int>&, int (*)[4], int);
extern void position(int (*)[4], int, int&, int&);

int main() {
	int ik, jk, temp;
	bool flag;
	vector<int> a(16);
	int pyat[4][4];
	zapolnenie(a, pyat, 5);
	position(pyat, 4, ik, jk);
	return 0;
}
