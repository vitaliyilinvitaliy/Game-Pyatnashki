#include "pyatnashki.h"

extern void records(RenderWindow &, bool &);
extern void play_game(RenderWindow &, bool &);

void menu(RenderWindow &window) {
  
  Texture fon;
  fon.loadFromFile("../images/fon.jpg");
  Sprite fonsprite(fon);

  fonsprite.setPosition(0, 0);

  Texture rul;
  rul.loadFromFile("../images/rules.jpg");
  Sprite rulsprite(rul);

  rulsprite.setPosition(0, 0);

  Font font;
  if (!font.loadFromFile("../font/ar2.ttf")) {
    // ошибка...
  }
  Text text1;
  Text text2;
  Text text3;
  Text text4;
  // start
  text1.setFont(font);
  text1.setString("START");
  text1.setCharacterSize(60);
  text1.setFillColor(Color::White);

  // rules
  text2.setFont(font);
  text2.setString("RULES");
  text2.setCharacterSize(60);
  text2.setFillColor(Color::White);

  // records
  text3.setFont(font);
  text3.setString("RECORDS");
  text3.setCharacterSize(60);
  text3.setFillColor(Color::White);

  // exit
  text4.setFont(font);
  text4.setString("EXIT");
  text4.setCharacterSize(60);
  text4.setFillColor(Color::White);

  bool isMenu = 1;
  int menuNum = 0;
  text1.setPosition(150, 5);
  text2.setPosition(150, 55);
  text3.setPosition(150, 105);
  text4.setPosition(150, 160);

  //////////////////////////////МЕНЮ///////////////////
  while (isMenu) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        isMenu = false;
      }
    }
    text1.setFillColor(Color::White);
    text2.setFillColor(Color::White);
    text3.setFillColor(Color::White);
    text4.setFillColor(Color::White);
    menuNum = 0;
    window.clear();

    if (IntRect(150, 30, 170, 45).contains(Mouse::getPosition(window))) {
      text1.setFillColor(Color(0, 202, 0));
      menuNum = 1;
    }
    if (IntRect(150, 82, 170, 45).contains(Mouse::getPosition(window))) {
      text2.setFillColor(Color(0, 202, 0));
      menuNum = 2;
    }
    if (IntRect(150, 135, 170, 45).contains(Mouse::getPosition(window))) {
      text3.setFillColor(Color(0, 202, 0));
      menuNum = 3;
    }
    if (IntRect(150, 180, 170, 45).contains(Mouse::getPosition(window))) {
      text4.setFillColor(Color(0, 202, 0));
      menuNum = 4;
    }

    if (Mouse::isButtonPressed(Mouse::Left)) {
      if (menuNum == 1) {
        play_game(window, isMenu);
      }
      if (menuNum == 2) {
        window.draw(rulsprite);
        window.display();
        while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
          while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
              window.close();
              return;
            }
          }
        }
      }
      if (menuNum == 3) {
        records(window, isMenu);
      }
      if (menuNum == 4) {
        window.close();
        isMenu = false;
      }
    }

    window.draw(fonsprite);
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);

    window.display();
  }
}
