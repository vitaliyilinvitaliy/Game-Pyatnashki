#include "conio.c"
#include "pyatnashki.h"

extern void check(int (*)[4], int, bool &);
extern void zapolnenie(vector<int> &, int (*)[4], int);
extern void position(int (*)[4], int, int &, int &);
extern void restart(vector<int> &, int (*b)[4], int, int &, int &, int &);
extern void menu();
extern void print(int (*)[4], int, int);

int main() {

  int ik, jk, temp, countt = 0;
  bool flag;
  vector<int> a(16);
  int pyat[4][4];
  zapolnenie(a, pyat, 5);
  position(pyat, 4, ik, jk);
  menu();

  while (1) {
    print(pyat, 4, countt);
    //  while(1){now = ( clock() - start ) / (double)
    //  CLOCKS_PER_SEC;cout<<now<<endl; print(pyat,4,countt,now); sleep(1);
    //  system("clear"); }
    check(pyat, 4, flag);
    // move(pyat,4,ik,jk);
    if (flag) {
	system("clear");      
	cout << "!!!!!You won!!!!!\nPress to key/n" << endl;
	getch();      
	system("clear");
	menu();
    };

    switch (getch()) {
    case 'a':
      if (jk != 0) {
        temp = pyat[ik][jk];
        pyat[ik][jk] = pyat[ik][jk - 1];
        pyat[ik][jk - 1] = temp;
        jk--;
        countt++;
        break;
      } else {
        break;
      }
    case 'w':
      if (ik != 0) {
        temp = pyat[ik][jk];
        pyat[ik][jk] = pyat[ik - 1][jk];
        pyat[ik - 1][jk] = temp;
        ik--;
        countt++;
        break;
      } else {
        break;
      }
    case 'd':
      if (jk != 3) {
        temp = pyat[ik][jk];
        pyat[ik][jk] = pyat[ik][jk + 1];
        pyat[ik][jk + 1] = temp;
        jk++;
        countt++;
        break;
      } else {
        break;
      }
    case 's':
      if (ik != 3) {
        temp = pyat[ik][jk];
        pyat[ik][jk] = pyat[ik + 1][jk];
        pyat[ik + 1][jk] = temp;
        ik++;
        countt++;
        break;
      } else {
        break;
      }
    case 'r':
      restart(a, pyat, 4, ik, jk, countt);
      break;
    case 'e':
      restart(a, pyat, 4, ik, jk, countt);
      system("clear");
      menu();
      break;
    }

    system("clear");
  }

  return 0;
}
