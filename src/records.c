#include "pyatnashki.h"

void records(RenderWindow& app, bool& flag_close) {
	Font font;
	font.loadFromFile("../image/ar2.ttf");

	Texture fon;
	fon.loadFromFile("../image/fon.jpg");
	Sprite fonsprite(fon);

	Text rec_;
	rec_.setFont(font);
	rec_.setCharacterSize(45);
	rec_.setColor(Color::White);
}
