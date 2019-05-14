#ifndef PYATNASHKI_H
#define PYATNASHKI_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

struct record {
  int count;
  clock_t timer;
};

#endif // PYATNASHKI_H
