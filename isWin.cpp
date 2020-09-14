#include <widget.h>
#include <algorithm>
#include <QDebug>

bool Widget::isWin() {

  bool retValue = false;
  int t = 0;
  //------------------------------------------------------------------------------------------------------------
  // Diagonal S-D
  std::vector<int> SinD = {0, 4, 8};
  // Player 1
  for (auto i : SinD) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(SinD);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : SinD) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(SinD);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  //Diagonal D-S
  std::vector<int> DesS = {2, 4, 6};
  // Player 1
  for (auto i : DesS) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(DesS);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : DesS) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(DesS);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  // Row 0
  std::vector<int> Row0 = {0, 3, 6};
  // Player 1
  for (auto i : Row0) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Row0);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : Row0) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Row0);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  //Row 1
  std::vector<int> Row1 = {1, 4, 7};
  // Player 1
  for (auto i : Row1) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Row1);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : Row1) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Row1);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  //Row 2
  std::vector<int> Row2 = {2, 5, 8};
  // Player 1
  for (auto i : Row2) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Row2);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : Row2) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Row2);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  // Column 0
  std::vector<int> Col0 = {0, 1, 2};
  // Player 1
  for (auto i : Col0) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Col0);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : Col0) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Col0);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  //Column 1
  std::vector<int> Col1 = {3, 4, 5};
  // Player 1
  for (auto i : Col1) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Col1);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : Col1) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Col1);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------
  //Column 2
  std::vector<int> Col2 = {6, 7, 8};
  // Player 1
  for (auto i : Col2) {
    if (Find(VecMap1, i)) {
      ++t;
      qDebug() << "vecmap1" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Col2);
    setWinPlayer(1);
    return  true;
  }
  t = 0;
  // Player 2
  for (auto i : Col2) {
    if (Find(VecMap2, i)) {
      ++t;
      qDebug() << "vecmap2" << t;
    }
  }
  if (t < 3) {
    retValue = false;
  } else {
    changeBackButtonColor(Col2);
    setWinPlayer(2);
    return true;
  }
  t = 0;
  //------------------------------------------------------------------------------------------------------------

  return retValue;
}

bool Widget::Find(const std::vector<int> &Vec, int value) {
  // If element found it returns true otherwise returns false.
  for (auto i = Vec.begin(); i < Vec.end(); ++i) {
    if(*i == value){
      return true;
    }
  }
  return false;
}
