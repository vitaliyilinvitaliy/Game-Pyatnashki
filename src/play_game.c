#include "pyatnashki.h"

void play_game(RenderWindow &window, bool &flag_close) {
  bool flag_upor = true;
  vector<int> a(16);
  int pyat[4][4];

  Texture fon_game;
  fon_game.loadFromFile("../images/fon_game.jpg");
  Sprite fon_gamesprite(fon_game);

  Texture p;
  p.loadFromFile("../images/p2.jpg");
  Sprite psprite(p);

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
