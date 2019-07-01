#include "pyatnashki.h"

record rec;
extern void sort_dat(vector<vector<int> /**/> &);

void records(RenderWindow &app, bool &flag_close) {
  vector<vector<int> /**/> s;
  sort_dat(s);
  FILE *tf;

  Font font;
  font.loadFromFile("../font/ar2.ttf");

  Texture fon;
  fon.loadFromFile("../images/fon.jpg");
  Sprite fonsprite(fon);

  Text rec_;
  rec_.setFont(font);
  rec_.setCharacterSize(45);
  rec_.setFillColor(Color::White);

  Text head;
  head.setFont(font);
  head.setString("PLAYER\t\t\tCOUNT\t\t\t\tTIME");
  head.setCharacterSize(45);
  head.setFillColor(Color::Green);
  head.setPosition(50, 5);

  Text del;
  del.setFont(font);
  del.setString("To clear the list of records, press the key 'Delete'");
  del.setCharacterSize(30);
  del.setFillColor(Color::Red);
  del.setPosition(50, 310);

  while (!Keyboard::isKeyPressed(Keyboard::Escape)) {
    Event event;
    while (app.pollEvent(event)) {
      if (event.type == Event::Closed) {
        app.close();
        flag_close = false;
        return;
      }
    }

    if (Keyboard::isKeyPressed(Keyboard::Delete)) {
      FILE *t2f;
      tf = fopen("records.dat", "rb");
      t2f = fopen("delete.dat", "wb");
      int i = 1;
      fread(&rec, sizeof(rec), 1, tf);
      while (!feof(tf)) {
        if (i <= 0) {
          fwrite(&rec, sizeof(rec), 1, t2f);
        }
        i++;
        fread(&rec, sizeof(rec), 1, tf);
      }
      fclose(tf);
      remove("records.dat");
      fclose(t2f);
      rename("delete.dat", "records.dat");
      s.clear();
    }
    app.clear();
    app.draw(fonsprite);
    app.draw(head);
    app.draw(del);

    int x = 50, y = 50;
    for (size_t i = 0; i < s.size(); i++) {
      ostringstream playerrec_i, playerrec_count, playerrec_timer;
      playerrec_i << i + 1;
      playerrec_count << s[i][0];
      playerrec_timer << s[i][1];
      rec_.setString(playerrec_i.str() + "\t\t\t\t\t\t" +
                     playerrec_count.str() + "\t\t\t\t\t\t" +
                     playerrec_timer.str());

      rec_.setPosition(x, y);

      app.draw(rec_);
      y += 30;
    }
    app.display();
  }
}
