#include "pyatnashki.h"

void play_game(RenderWindow &window, bool &flag_close) {
  bool flag_upor = true;
  vector<int> a(16);
  int pyat[4][4],cou=0;

   Texture fon_game;
   fon_game.loadFromFile("../images/fon_game.jpg");
   Sprite fon_gamesprite(fon_game);

   Texture p;
   p.loadFromFile("../images/p2.jpg");
   Sprite psprite(p);

   Texture win;
   win.loadFromFile("../images/win2.jpg");
   Sprite winsprite(win);

   Texture sound_yes;
   sound_yes.loadFromFile("../images/sound_yes.png");
   Sprite sound_yes_sprite(sound_yes);
   sound_yes_sprite.setPosition(600,10);

   Texture sound_no;
   sound_no.loadFromFile("../images/sound_no.png");
   Sprite sound_no_sprite(sound_no);
   sound_no_sprite.setPosition(600,10);

   Font font;
        if (!font.loadFromFile("ar2.ttf"))
        {
         // ошибка...
        }
        Text count;

        count.setFont(font);
        count.setCharacterSize(60);
        count.setColor(Color::White);
        count.setPosition(250,113);
        Text timer;
        timer.setFont(font);
        timer.setCharacterSize(45);
        timer.setColor(Color::White);
         timer.setPosition(370,230);
        


        Text ed;
        ed.setFont(font);
        ed.setCharacterSize(45);
        ed.setColor(Color::White);



        fon_gamesprite.setPosition(0,0);
        psprite.setPosition(0,0);
 
   while (!Keyboard::isKeyPressed(Keyboard::Escape)) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        flag_close = false;
        return;
      }
    }

    window.clear();
    window.draw(fon_gamesprite);
    window.display();
  }
}
