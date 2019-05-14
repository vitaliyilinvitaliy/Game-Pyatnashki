#include "pyatnashki.h"

void play_game(RenderWindow & window,bool &flag_close)
{
	Texture fon_game;
        fon_game.loadFromFile("../images/fon_game.jpg");
        Sprite fon_gamesprite(fon_game);

        Texture p;
        p.loadFromFile("../images/p2.jpg");
        Sprite psprite(p);
}
