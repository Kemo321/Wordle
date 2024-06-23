#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}

QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend class Game;

protected:

    Ui::MainWindow *ui;
    Game game;
    void update_game();

private slots:

    void on_ENTER_clicked();
    void on_DELETE_clicked();
    void on_LETTER_clicked();
    void RESTART();
};
#endif // MAINWINDOW_H
