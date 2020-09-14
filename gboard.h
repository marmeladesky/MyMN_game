#ifndef GBOARD_H
#define GBOARD_H

#include <ncurses.h>

#include <iostream>
#include <vector>

class Gboard {
public:
  Gboard();
  ~Gboard();
  void DrowBoard();
  bool SetGB_ch(bool player, const size_t _cord = -1);
  bool isValid();
  bool isCopy(size_t _cord);

private:
  const char firstP = 'O';
  const char secondP = 'X';
  char Board_str_up;
  const size_t BoardSize = 3;
  std::vector<char> vecBoard;
};

class Gbaord1 {
  Gbaord1();
};

#endif // GBOARD_H
