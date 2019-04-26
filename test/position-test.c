#include "pyatnashki.h"

int position(int (*a)[4], int N, int& ik, int& jk)
{
    bool f = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) {
                ik = i;
                jk = j;
                f = true;
                break;
            }
            if (f == true)
                break;
        }
    }
    return ik+jk;
}

TEST_CASE("Poisk pozicii","[POSITION]")
{
	int a[4][4]={
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,0}
	};
	int ik=0,jk=0;
	REQUIRE(position(a,4,ik,jk)==6);
	a[4][4]={
        {0,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,1}
        };
	ik=0;jk=0;
	REQUIRE(position(a,4,ik,jk)==0);
	a[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,0,11,12},
        {13,14,15,10}
        };
	ik=0;jk=0;
	REQUIRE(position(a,4,ik,jk)==3);
	cout<<"[POSITION]"<<endl;
}
