#include "pyatnashki.h"

extern void view(FILE*);

void menu()
{
    int i;
    bool flag = 0;
    FILE* tf;
    fstream rules;
    string buff;
    while (1) {
        cout << "1.Start\n2.Rules\n3.Records\n4.Exit\n";
        switch (getch()) {
        case '1':
            flag = 1;
            system("clear");
            break;

        case '2':
            system("clear");
            rules.open("../Rul/Rules.txt");
            if (!rules.is_open()) {
                cout << "error" << endl;
                ;
                exit(1);
            }
            while (!rules.eof())
                rules >> buff;
            cout << buff << " ";

            rules.close();
            cout << "\n\t...Press to key...\n";
            if (getch())
                system("clear");

            break;

        case '3':
            system("clear");
            view(tf);
            system("clear");
            break;

        case '4':
            exit(1);
        }

        if (flag)
            break;
        system("clear");
    }
}
