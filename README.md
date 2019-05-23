# Game-Pyatnashki

![alt text](https://pp.userapi.com/c851332/v851332731/128b64/TL0o-G8mpZ0.jpg)

Сборка: [![Build Status](https://travis-ci.org/vitaliyilinvitaliy/Game-Pyatnashki.svg?branch=Beta_version)](https://travis-ci.org/vitaliyilinvitaliy/Game-Pyatnashki)

Лицензия:  [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
## **Сборка последней версии**

```
$ git clone https://github.com/vitaliyilinvitaliy/Game-Pyatnashki.git
$ cd Game-Pyatnashki/
$ make 
```
### *Запуск*
```
cd bin/
./pyatnashki.exe
```
## **Сборка тестовой версии**

```
$ git clone https://github.com/vitaliyilinvitaliy/Game-Pyatnashki.git
$ cd Game-Pyatnashki/
$ git checkout testing_issue-15
$ make all
$ make bin/pyatnashki-test.exe
```
### *Запуск*

```
cd bin/
./pyatnashki-test.exe
```
## **Проблемы сборки**

На этапе сборки вы можете столкнуться с такой проблемой:

![alt text](https://cdn1.savepice.ru/uploads/2019/5/18/87bacc3f223de2bbf81fd706df604c7e-full.jpg)
### Решение:
```
sudo apt-get install libsfml-dev
```
## Системные требования:
 
 ### Операционная система: 
 Linux Ubuntu
### Дополнительно:
Наличие библиотеки SFML
