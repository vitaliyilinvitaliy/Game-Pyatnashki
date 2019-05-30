#include "pyatnashki.h"

extern void zapolnenie(vector<int> &, int (*)[4], int);
extern void write_records(int, clock_t);
extern void dvig(int (*)[4], int, int, int &);
extern void check(int (*)[4], bool &);

void play_game(RenderWindow &window, bool &flag_close) {
	bool flag_upor = true;
	vector<int> a(16);
	int pyat[4][4], cou = 0;
	zapolnenie(a, pyat, 5);

	clock_t timer_start = clock();
	clock_t timer_finish = 0;

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
	sound_yes_sprite.setPosition(600, 10);

	Texture sound_no;
	sound_no.loadFromFile("../images/sound_no.png");
	Sprite sound_no_sprite(sound_no);
	sound_no_sprite.setPosition(600, 10);

	Font font;
	if (!font.loadFromFile("../font/ar2.ttf")) {
		// ошибка...
	}
	Text count;

	count.setFont(font);
	count.setCharacterSize(60);
	count.setFillColor(Color::White);
	count.setPosition(250, 113);
	Text timer;
	timer.setFont(font);
	timer.setCharacterSize(45);
	timer.setFillColor(Color::White);
	timer.setPosition(370, 230);

	Text ed;
	ed.setFont(font);
	ed.setCharacterSize(45);
	ed.setFillColor (Color::White);

	fon_gamesprite.setPosition(0, 0);
	psprite.setPosition(0, 0);

	Music music;  //создаем объект музыки
	music.openFromFile("../music/music_fon.ogg");  //загружаем файл
	music.play();  //воспроизводим музыку

	Music music_end;  //создаем объект музыки
	music_end.openFromFile("../music/music_fon_end.ogg");  //загружаем файл

	bool flag_sound = true;

	while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
		Vector2i pos = Mouse::getPosition(window);
		int x = (pos.x - 50) / 50;
		int y = (pos.y - 20) / 50;
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				flag_close = false;
				return;
			}
			if (event.type == Event::MouseButtonPressed) {
				if (Mouse::isButtonPressed(Mouse::Left)) {
					dvig(pyat, y, x, cou);
					if (y == 0 && x == 11 &&
					    flag_sound == true) {
						music.setVolume(0);
						flag_sound = false;
					} else {
						if (y == 0 && x == 11 &&
						    flag_sound == false) {
							music.setVolume(100);
							flag_sound = true;
						}
					}
				}
				/*  if (Mouse::isButtonPressed(Mouse::Right))
				  {
				    for(int i=0,qw=1;i<4;i++)
				    {
					for(int j=0;j<4;j++,qw++)
					{
					    pyat[i][j]=qw;
					}
				    }
				      pyat[3][3]=0;
				      cou=rand()%23+21;
				  }*/
			}
		}

		window.clear();

		window.draw(fon_gamesprite);
		for (int i = 0, y = 20; i < 4; i++, y += 50)
			for (int j = 0, x = 50; j < 4; j++, x += 50) {
				{
					psprite.setTextureRect(IntRect(
					    (pyat[i][j]) * 50, 0, 50, 50));
					psprite.setPosition(x, y);
					window.draw(psprite);
				}
			}
		ostringstream playercount;
		playercount << cou;
		count.setString(
		    playercount
			.str());  //задаем строку тексту и вызываем
				  //сформированную выше строку методом .str()
		count.setPosition(
		    370,
		    170);  //задаем позицию текста, отступая от центра камеры

		ostringstream time;
		timer_finish = clock();
		timer_finish -= timer_start;

		time << timer_finish / 600000;
		timer.setString(time.str() + " SEC");

		if (flag_sound) {
			window.draw(sound_yes_sprite);
		} else {
			window.draw(sound_no_sprite);
		}
		music.setLoop(true);
		window.draw(count);
		window.draw(timer);
		window.draw(ed);

		window.display();
		check(pyat, flag_upor);
		if (flag_upor) {
			write_records(cou, timer_finish / 600000);
			break;
		}
	}

	music.setVolume(0);
	Text end_play;
	end_play.setFont(font);
	end_play.setCharacterSize(60);
	end_play.setFillColor(Color::White);
	timer.setPosition(140, 53);
	count.setPosition(245, 113);
	music_end.play();  //воспроизводим музыку
	while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				flag_close = false;
				return;
			}
		}
		window.clear();
		window.draw(winsprite);
		count.setCharacterSize(45);

		window.draw(count);

		window.draw(timer);
		window.display();
	}
}
