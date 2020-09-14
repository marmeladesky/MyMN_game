#include "gboard.h"
#include <ncurses.h>

Gboard::Gboard()
{
  vecBoard.resize(BoardSize * BoardSize, 'N'); // init Game Board

  initscr();            /* Start curses mode 		*/
  raw();                /* Line buffering disabled	*/
  keypad(stdscr, TRUE); /* We get F1, F2 etc..		*/
  noecho();             /* Don't echo() while we do getch */
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
}

Gboard::~Gboard()
{
  getch();
  endwin();
}

void
Gboard::DrowBoard()
{
  auto it = vecBoard.begin();

  move(0, 0);
  for (size_t i = 0; i < BoardSize; ++i) {
    printw("\n");
    for (size_t j = 0; j < BoardSize; ++j) {
      if (vecBoard.at(i * 3 + j) == firstP) { // convert bidimensional to arra
        attron(COLOR_PAIR(1) | A_BOLD);
      }
      if (vecBoard.at(i * 3 + j) == secondP) {
        attron(COLOR_PAIR(2) | A_BOLD);
      }
      addch(*it++);
      addch(' ');

      attroff(COLOR_PAIR(1) | A_BOLD);
      attroff(COLOR_PAIR(2) | A_BOLD);
    }
  }
  refresh();
}

bool
Gboard::isCopy(size_t _cord)
{
  if (vecBoard.at(_cord - 1) == firstP || vecBoard.at(_cord - 1) == secondP) {
    return true;
  }
  return false;
}

bool
Gboard::SetGB_ch(bool player, const size_t _cord)
{
  if (_cord <= vecBoard.size() && _cord) {
    if (isCopy(_cord)) {
      return false;
    }

    auto it = vecBoard.begin();
    if (player) {
      *(it + _cord - 1) = secondP;
      return true;
    } else {
      *(it + _cord - 1) = firstP;
      return true;
    }
  }
  return false;
}

bool
Gboard::isValid()
{
  // orinzontal is valid

  size_t isvalidF{};
  size_t isvalidS{};

  auto it = vecBoard.begin();
  //-----------------------------------------------------------------------------------
  for (size_t i = 0; i < BoardSize; ++i) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  isvalidF = 0;
  if (isvalidS == BoardSize)
    return true;
  isvalidS = 0;
  //-----------------------------------------------------------------------------------
  for (size_t i = BoardSize; i < BoardSize * 2; ++i) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidS = 0;
  isvalidF = 0;
  //-----------------------------------------------------------------------------------
  for (size_t i = BoardSize * 2; i < BoardSize * 3; ++i) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidS = 0;
  isvalidF = 0;
  //-----------------------------------------------------------------------------------
  for (int i = 2; i < 7; i += 2) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidF = 0;
  isvalidS = 0;
  //-----------------------------------------------------------------------------------
  for (int i = 0; i <= 9; i += 4) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidF = 0;
  isvalidS = 0;
  //-----------------------------------------------------------------------------------
  for (int i = 0; i < 7; i += 3) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidF = 0;
  isvalidS = 0;
  //-----------------------------------------------------------------------------------
  for (int i = 2; i <= 9; i += 3) {
    if (*(it + i) == firstP) {
      ++isvalidF;
    }
    if (*(it + i) == secondP) {
      ++isvalidS;
    }
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidF = 0;
  isvalidS = 0;
  //-----------------------------------------------------------------------------------
  if (*(it + 1) == firstP) {
    ++isvalidF;
  }
  if (*(it + 1) == secondP) {
    ++isvalidS;
  }
  if (*(it + 4) == firstP) {
    ++isvalidF;
  }
  if (*(it + 4) == secondP) {
    ++isvalidS;
  }
  if (*(it + 7) == firstP) {
    ++isvalidF;
  }
  if (*(it + 7) == secondP) {
    ++isvalidS;
  }
  if (isvalidF == BoardSize)
    return true;
  if (isvalidS == BoardSize)
    return true;
  isvalidF = 0;
  isvalidS = 0;
  //-----------------------------------------------------------------------------------

  return false;
}
