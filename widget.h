#pragma once

#include <QWidget>
#include <vector>
#include <QPushButton>
#include <QString>
#include <iterator>

#define PLAYER1 'X'
#define PLAYER2 'O'

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  void AddButtonToVector(void);
  QString &changePlayer(void); // Change Player and return string for replace
                               // result in Button setText
  void AddtoMap(bool player, int index);
  bool isWin(void);
  bool Find(const std::vector<int> &, int value);
  void isValidate();
  void changeBackButtonColor(std::vector<int> &);
  void setWinPlayer(int);
  void parregio();

private slots:
  void on_button0_0_clicked();

  void on_button0_1_clicked();

  void on_button1_2_clicked();

  void on_button0_2_clicked();

  void on_button1_0_clicked();

  void on_button1_1_clicked();

  void on_button2_0_clicked();

  void on_button2_1_clicked();

  void on_button2_2_clicked();

  //void on_label_linkActivated(const QString &link);

  //void on_pushButton_clicked();

  void on_resetButton_clicked();

private:
  Ui::Widget *ui;
  std::vector<QPushButton *> VecOfButtons;

  QString PlayerChar;
  bool PlayerChange;

  std::vector<int> VecMap1;
  std::vector<int> VecMap2;
  uint countClickedButton;
};
