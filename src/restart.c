#include "pyatnashki.h"

void restart(vector<int> &a,int (*b)[4],int N,int& ik,int& jk,int &countt)
{
    zapolnenie(a,b,5);
    position(b,4,ik,jk);
    countt = 0;
}
