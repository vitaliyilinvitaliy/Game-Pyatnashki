#include "pyatnashki.h"

void view(FILE* tf)
{
    int i = 1;
    tf = fopen("../Records/records.dat", "rb");
    if (tf == NULL) {
        puts("File not found");
        exit(1);
    }
    // fread(&t,sizeof(t),1,tf);

    //	while(!feof(tf))
    //	{
    printf("\tRECORDS");

    //	}
    cout << endl << "Press ENTER to exit " << endl;
    cin.get();
    fclose(tf);
}
