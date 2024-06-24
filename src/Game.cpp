#include "Game.hpp"
#include <algorithm>


std::vector<std::string> Game::get_guesses() const
{
    std::vector<std::string> answer;

    for (auto word : words)
    {
        std::string copy = word;
        for (int i = 0; i < 5 - word.size() ; i++)
            copy += " ";
        answer.push_back(copy);
    }

    return answer;
}

void Game::delete_last()
{
    if (await)
        return;
    if (!this->words[this->row].empty())
    {
        this->words[this->row].pop_back();
        this->ui->label_26->setText(" ");
    }
    else
    {
        this->ui->label_26->setText("Cannot delete letter from empty word!");
    }
}

void Game::add_letter(std::string letter)
{
    if (await)
        return;
    if (this->words[this->row].size() < 5)
    {
        this->words[this->row] += letter;
        this->ui->label_26->setText(" ");
    }
    else
    {
        this->ui->label_26->setText("Word cannot be longer than 5 letters!");
    }
}

Game::Game() : rw(random_word())
{
    this->restart();
}

void Game::enter()
{
    if (await)
        return;
    if (this->words[this->row].size() == 5)
    {
        if (this->correct_word == this->words[this->row])
        {
            this->won();
            return;
        }
        auto x = std::find(this->rw.words_list.begin(), this->rw.words_list.end(), this->words[this->row]);

        if (x != this->rw.words_list.end())
        {
            this->row += 1;
            this->ui->label_26->setText(" ");
        }
        else
        {
            this->ui->label_26->setText("Word does not exist!");
        }
        if (row == 5)
            this->lost();
    }
}

std::string Game::get_correct_word()
{
    return this->correct_word;
}

void Game::won()
{
    this->ui->label_26->setText("Congratulations you have won!");
    await = true;
}

void Game::lost()
{
    QString info = QString("You have lost, the correct word was: %1").arg(QString::fromStdString(this->correct_word));
    this->ui->label_26->setText(info);
    await = true;
}

void Game::restart()
{
    this->row = 0;
    this->correct_word = this->rw.draw();
    for (auto &word : this->words)
        word = "";
    await = false;
}
