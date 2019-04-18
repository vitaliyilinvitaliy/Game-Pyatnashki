#include "pyatnashki.h"

extern void print(int (*)[4], int);
extern void check(int (*)[4], int, bool&);
extern void zapolnenie(vector<int>&, int (*)[4], int);
extern void position(int (*)[4], int, int&, int&);

int main()
{
    int ik, jk, temp;
    bool flag;
    vector<int> a(16);
    int pyat[4][4];
    zapolnenie(a, pyat, 5);
    position(pyat, 4, ik, jk);

    while (1) {
        print(pyat, 4);
        check(pyat, 4, flag);

        switch (getch()) {
        case 'a':
            if (jk != 0) {
                temp = pyat[ik][jk];
                pyat[ik][jk] = pyat[ik][jk - 1];
                pyat[ik][jk - 1] = temp;
                jk--;
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
                break;
            } else {
                break;
            }
        }
        system("clear");
        if (flag) {
            cout << "You won!!!!!" << endl;
            break;
        };
    }
    return 0;
}
