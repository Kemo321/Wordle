#include "random_word.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>


random_word::random_word()
{
    std::ifstream ifs("words.txt");
    ifs >> *this;
    ifs.close();
}

std::istream& operator>>(std::istream& is, random_word& rw)
{
    std::string temp;
    while (is >> temp)
    {
        rw.words_list.push_back(temp);
    }
    return is;
}

std::string random_word::draw()
{
    std::srand(time(NULL));
    int index = std::rand() % this->words_list.size();
    return this->words_list[index];
}
