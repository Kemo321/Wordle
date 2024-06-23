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


    std::vector<QTextEdit*> textEdits =
        {
            ui->textEdit, ui->textEdit_2, ui->textEdit_3, ui->textEdit_4, ui->textEdit_5,
            ui->textEdit_6, ui->textEdit_11, ui->textEdit_22, ui->textEdit_17, ui->textEdit_16,
            ui->textEdit_7, ui->textEdit_10, ui->textEdit_21, ui->textEdit_18, ui->textEdit_15,
            ui->textEdit_8, ui->textEdit_23, ui->textEdit_12, ui->textEdit_19, ui->textEdit_14,
            ui->textEdit_9, ui->textEdit_24, ui->textEdit_25, ui->textEdit_20, ui->textEdit_13
        };
    this->game.ui = this->ui;
    this->ui->textEdit_26->setAlignment(Qt::AlignCenter);
    this->ui->textEdit_26->setStyleSheet("QTextEdit {font-size: 24px;}");
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
    std::vector<QTextEdit*> textEdits =
    {
        ui->textEdit, ui->textEdit_2, ui->textEdit_3, ui->textEdit_4, ui->textEdit_5,
        ui->textEdit_6, ui->textEdit_11, ui->textEdit_22, ui->textEdit_17, ui->textEdit_16,
        ui->textEdit_7, ui->textEdit_10, ui->textEdit_21, ui->textEdit_18, ui->textEdit_15,
        ui->textEdit_8, ui->textEdit_23, ui->textEdit_12, ui->textEdit_19, ui->textEdit_14,
        ui->textEdit_9, ui->textEdit_24, ui->textEdit_25, ui->textEdit_20, ui->textEdit_13
    };

    auto guesses = game.get_guesses();
    std::string correct_word = game.get_correct_word();

    for (int row = 0; row < guesses.size(); ++row)
    {
        auto& guess = guesses[row];
        for (int col = 0; col < guess.size(); ++col)
        {
            QString letter = QString(guess[col]);
            textEdits[row * 5 + col]->setText(letter);
            textEdits[row * 5 + col]->setAlignment(Qt::AlignCenter);
            if (guess[col] == correct_word[col] && row != game.row)
            {
            textEdits[row * 5 + col]->setStyleSheet("QTextEdit { color: green; font-size: 32px;}");
            }
            else if (row != game.row)
            {
                auto x = std::find(correct_word.begin(), correct_word.end(), guess[col]);
                if (x != correct_word.end())
                    textEdits[row * 5 + col]->setStyleSheet("QTextEdit { color: yellow; font-size: 32px;}");
                else
                    textEdits[row * 5 + col]->setStyleSheet("QTextEdit { color: red; font-size: 32px;}");
            }
            else
            {
                textEdits[row * 5 + col]->setStyleSheet("QTextEdit { font-size: 32px;}");
            }
        }
    }
}

void MainWindow::RESTART()
{
    this->game.restart();
    this->update_game();
}
