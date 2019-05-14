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

	Text head;
	head.setFont(font);
	head.setString("PLAYER\t\t\tCOUNT\t\t\t\t\TIME");
	head.setCharacterSize(45);
	head.setColor(Color::Green);
	head.setPosition(50, 5);

	Text del;
	del.setFont(font);
	del.setString("To clear the list of records, press the key 'Delete'");
	del.setCharacterSize(30);
	del.setColor(Color::Red);
	del.setPosition(50, 310);
}
