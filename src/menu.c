#include "pyatnashki.h"




void menu()
{
    int i;
    bool flag = 0;
    cout << "1.Start\n2.Rules\n3.Records\n4.Exit\n";
    while(1)
    {

        switch(getch())
        {
            case '1':{flag = 1; system("clear"); break ;}
            case '2': ;
            case '3': ;
            case '4': exit(1);
        }
        if(flag) break;
    }
}
