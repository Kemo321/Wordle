#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <vector>
#include "random_word.hpp"
#include "ui_mainwindow.h"

class Game
{
protected:
    bool await=false;
    std::string words[5];
    std::string correct_word;
    Ui::MainWindow *ui;
    random_word rw;
    int row=0;

public:
    Game();
    void delete_last();
    void enter();
    void add_letter(std::string letter);
    void won();
    void lost();
    void restart();
    std::string get_correct_word();

    std::vector<std::string> get_guesses() const;

    friend class MainWindow;
};

#endif // GAME_HPP
