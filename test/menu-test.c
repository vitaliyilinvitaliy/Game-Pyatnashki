#include "pyatnashki.h"


int menu(int &flag)
{
   
       int i=flag; 
        switch (i) {
        case '1':i=flag; break;     

        case '2':i=flag; break;
 
	case '3':i=flag; break;

        case '4':i=flag; break;
        
	}
	if(i<1||i>4)
        {
                return 0;
        }
	else return i;
	

    
}

TEST_CASE("Test menu","[MENU]")
{
	int flag; 
	flag=1;
	REQUIRE(menu(flag)==1);
	flag=2;
	REQUIRE(menu(flag)==2);
	flag=3;
	REQUIRE(menu(flag)==3);
	flag=4;
	REQUIRE(menu(flag)==4);
	flag=2355;
	REQUIRE(menu(flag)==0);
	cout<<"[MENU]"<<endl;
}
