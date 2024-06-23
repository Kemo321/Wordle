#ifndef RANDOM_WORD_H
#define RANDOM_WORD_H

#include <string>
#include <iostream>
#include <vector>

class random_word
{
protected:

    std::vector<std::string> words_list;

public:
    random_word();
    std::string draw();
    friend std::istream& operator>>(std::istream& is, random_word& rw);
    friend class Game;
};

#endif // RANDOM_WORD_H
