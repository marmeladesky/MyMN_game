#include "widget.h"
#include "ui_widget.h"
#include <vector>
#include <string>
#include <QString>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget), PlayerChange(true)
{
  ui->setupUi(this);

  ui->resetButton->setEnabled(false);

  setFixedSize(400, 430);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::AddButtonToVector() {
  VecOfButtons.push_back(ui->button0_0);
  VecOfButtons.push_back(ui->button0_1);
  VecOfButtons.push_back(ui->button0_2);

  VecOfButtons.push_back(ui->button1_0);
  VecOfButtons.push_back(ui->button1_1);
  VecOfButtons.push_back(ui->button1_2);

  VecOfButtons.push_back(ui->button2_0);
  VecOfButtons.push_back(ui->button2_1);
  VecOfButtons.push_back(ui->button2_2);
}

QString &Widget::changePlayer() {
  if (PlayerChange == true) {
    PlayerChange = false;
    return PlayerChar = PLAYER1;
  } else {
    PlayerChange = true;
    return PlayerChar = PLAYER2;
  }
}

void Widget::AddtoMap(bool player, int index) {
  if (player == false) {
    VecMap1.push_back(index);
    // qDebug() << "Map1: " << index;
  } else {
    VecMap2.push_back(index);
    // qDebug() << "Map2: " << index;
  }
}

void Widget::on_button0_0_clicked() {
  VecOfButtons[0]->setText(changePlayer());
  VecOfButtons[0]->setEnabled(false);
  AddtoMap(PlayerChange, 0);
  isValidate();
}

void Widget::on_button0_1_clicked() {
  VecOfButtons[1]->setText(changePlayer());
  VecOfButtons[1]->setEnabled(false);
  AddtoMap(PlayerChange, 1);
  isValidate();
}

void Widget::on_button1_2_clicked() {
  VecOfButtons[5]->setText(changePlayer());
  VecOfButtons[5]->setEnabled(false);
  AddtoMap(PlayerChange, 5);
  isValidate();
}

void Widget::on_button0_2_clicked() {
  VecOfButtons[2]->setText(changePlayer());
  VecOfButtons[2]->setEnabled(false);
  AddtoMap(PlayerChange, 2);
  isValidate();
}

void Widget::on_button1_0_clicked() {
  VecOfButtons[3]->setText(changePlayer());
  VecOfButtons[3]->setEnabled(false);
  AddtoMap(PlayerChange, 3);
  isValidate();
}

void Widget::on_button1_1_clicked() {
  VecOfButtons[4]->setText(changePlayer());
  VecOfButtons[4]->setEnabled(false);
  AddtoMap(PlayerChange, 4);
  isValidate();
}

void Widget::on_button2_0_clicked() {
  VecOfButtons[6]->setText(changePlayer());
  VecOfButtons[6]->setEnabled(false);
  AddtoMap(PlayerChange, 6);
  isValidate();
}

void Widget::on_button2_1_clicked() {
  VecOfButtons[7]->setText(changePlayer());
  VecOfButtons[7]->setEnabled(false);
  AddtoMap(PlayerChange, 7);
  isValidate();
}

void Widget::on_button2_2_clicked() {
  VecOfButtons[8]->setText(changePlayer());
  VecOfButtons[8]->setEnabled(false);
  AddtoMap(PlayerChange, 8);
  isValidate();
}

void Widget::isValidate() {
  if (isWin()) {
    ui->groupBox->setEnabled(false);
  }
}

void Widget::changeBackButtonColor(std::vector<int> &vec) {
  auto itVec = vec.begin();
  VecOfButtons[*(itVec)]->setStyleSheet("* { background-color: rgb(57, 64, 69) }");
  VecOfButtons[*(itVec + 1)]->setStyleSheet("* { background-color: rgb(57, 64, 69) }");
  VecOfButtons[*(itVec + 2)]->setStyleSheet("* { background-color: rgb(57, 64, 69) }");
}

void Widget::setWinPlayer(int player) {
  if (player == 1) {
    ui->label->setText("Win First Player");
    ui->resetButton->setEnabled(true);
    ui->resetButton->setStyleSheet("* { background-color: rgb(85, 87, 83) }");
    // If win thirst plyer reset game to second
    PlayerChange = false;
  }
  if (player == 2) {
    ui->label->setText("Win Second Player");
    ui->resetButton->setEnabled(true);
    ui->resetButton->setStyleSheet("* { background-color: rgb(85, 87, 83) }");
    // If win thirst plyer reset game to second
    PlayerChange = true;
  }
}

void Widget::on_resetButton_clicked() {
  // Enable groupBox
  ui->groupBox->setEnabled(true);

  // Reset Text button and enable button
  VecOfButtons[0]->setText("");
  VecOfButtons[0]->setEnabled(true);

  VecOfButtons[1]->setText("");
  VecOfButtons[1]->setEnabled(true);

  VecOfButtons[2]->setText("");
  VecOfButtons[2]->setEnabled(true);

  VecOfButtons[3]->setText("");
  VecOfButtons[3]->setEnabled(true);

  VecOfButtons[4]->setText("");
  VecOfButtons[4]->setEnabled(true);

  VecOfButtons[5]->setText("");
  VecOfButtons[5]->setEnabled(true);

  VecOfButtons[6]->setText("");
  VecOfButtons[6]->setEnabled(true);

  VecOfButtons[7]->setText("");
  VecOfButtons[7]->setEnabled(true);

  VecOfButtons[8]->setText("");
  VecOfButtons[8]->setEnabled(true);

  // Change to Default color button
  VecOfButtons[0]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[1]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[2]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[3]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[4]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[5]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[6]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[7]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");
  VecOfButtons[8]->setStyleSheet("* { background-color: rgb(19, 25, 28) }");

  // Reset map1 and map2
  VecMap1.erase(VecMap1.begin(), VecMap1.end());
  qDebug() << "VecMap1 is empty";
  VecMap2.erase(VecMap2.begin(), VecMap2.end());
  qDebug() << "VecMap2 is empty";

  // Reset Label
  ui->label->setText("Player1 VS Player2");

  // Rest resetButton
  ui->resetButton->setEnabled(false);
  ui->resetButton->setStyleSheet("* { background-color: rgb(46, 52, 54) }");
}
