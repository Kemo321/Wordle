#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the buttons to their respective slots
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_18, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_19, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_20, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_23, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_26, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);
    connect(ui->pushButton_27, &QPushButton::clicked, this, &MainWindow::on_LETTER_clicked);

    connect(ui->pushButton_28, &QPushButton::clicked, this, &MainWindow::on_DELETE_clicked);
    connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::on_ENTER_clicked);

    connect(ui->pushButton_29, &QPushButton::clicked, this, &MainWindow::RESTART);


    std::vector<QLabel*> labels =
        {
            ui->label, ui->label_2, ui->label_3, ui->label_4, ui->label_5,
            ui->label_6, ui->label_7, ui->label_8, ui->label_9, ui->label_10,
            ui->label_11, ui->label_12, ui->label_13, ui->label_14, ui->label_15,
            ui->label_16, ui->label_17, ui->label_18, ui->label_19, ui->label_20,
            ui->label_21, ui->label_22, ui->label_23, ui->label_24, ui->label_25
        };
    this->game.ui = this->ui;
    this->ui->label_26->setAlignment(Qt::AlignCenter);
    this->ui->label_26->setStyleSheet("QLabel {font-size: 24px; border: 4px solid black;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LETTER_clicked()
{
    ;QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(button)
    {
        QString letter = button->text();
        game.add_letter(letter.toStdString());
        update_game();
    }
}

void MainWindow::on_ENTER_clicked()
{
    game.enter();
    update_game();
}

void MainWindow::on_DELETE_clicked()
{
    game.delete_last();
    update_game();
}

void MainWindow::update_game()
{
    std::vector<QLabel*> labels =
        {
            ui->label, ui->label_2, ui->label_3, ui->label_4, ui->label_5,
            ui->label_6, ui->label_7, ui->label_8, ui->label_9, ui->label_10,
            ui->label_11, ui->label_12, ui->label_13, ui->label_14, ui->label_15,
            ui->label_16, ui->label_17, ui->label_18, ui->label_19, ui->label_20,
            ui->label_21, ui->label_22, ui->label_23, ui->label_24, ui->label_25
        };

    auto guesses = game.get_guesses();
    std::string correct_word = game.get_correct_word();

    for (int row = 0; row < guesses.size(); ++row)
    {
        auto& guess = guesses[row];
        for (int col = 0; col < guess.size(); ++col)
        {
            QString letter = QString(guess[col]);
            labels[row * 5 + col]->setText(letter);
            labels[row * 5 + col]->setAlignment(Qt::AlignCenter);
            if (guess[col] == correct_word[col] && row != game.row)
            {
            labels[row * 5 + col]->setStyleSheet("QLabel { color: green; font-size: 32px; border: 4px solid black;}");
            }
            else if (row != game.row)
            {
                auto x = std::find(correct_word.begin(), correct_word.end(), guess[col]);
                if (x != correct_word.end())
                    labels[row * 5 + col]->setStyleSheet("QLabel { color: yellow; font-size: 32px; border: 4px solid black;}");
                else
                    labels[row * 5 + col]->setStyleSheet("QLabel { color: red; font-size: 32px; border: 4px solid black;}");
            }
            else
            {
                labels[row * 5 + col]->setStyleSheet("QLabel { font-size: 32px; border: 4px solid black;}");
            }
        }
    }
}

void MainWindow::RESTART()
{
    this->game.restart();
    this->update_game();
    this->ui->label_26->setText(" ");
}
