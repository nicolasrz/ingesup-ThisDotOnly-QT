#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLabel>
#include "ownbutton.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPointer>
#include <QTimer>
#include <QTime>
#include "parameter.h"
#include "turn.h"
class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    ~Game();
    QPointer<QVBoxLayout> vLayout;
    QPointer<QHBoxLayout> hLayout;
    QPointer<QHBoxLayout> hInfoGame;
    QPointer<Parameter> parameter;
    QPointer<Turn> turn;
    QVector<QPointer<OwnButton>> buttonAddedInGrille;
    QPointer<OwnButton> buttonToKill;
    QPointer<QLabel> labelKill;
    QPointer<QLabel> labelButtonToKill;
    QPointer<QLabel> labelTurn;
    QPointer<QLabel> labelTurnCount;

    void touchedDotCountIncrement();
    int getTouchedDotCount();
private:
    void init();
    void initGrille();
    int touchedDotCount;
    QPointer<OwnButton> getRandomOwnButtonShowed();
    void changeButtonInGrille();
    void removeOwnButtonFromGrille(QPointer<OwnButton> ownButtonToRemove);
    int getNumberOfDotToKill(QPointer<OwnButton> ownButtonToKill);
    void newTurn();
    void step1();
    void toWinStep1(int position);
public slots:
    void touchDot();
  //  void timerUpdate();
};

#endif // GAME_H
