#include "pyatnashki.h"

extern void menu(RenderWindow &);

int main() {
  RenderWindow window(VideoMode(660, 371), "PYATNASHKI-GAME");

  Image icon;
  if (!icon.loadFromFile("../images/15.jpg")) {
    return 1;
  }
  window.setIcon(62, 55, icon.getPixelsPtr());
  menu(window);
}
