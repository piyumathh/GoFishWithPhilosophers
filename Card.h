//
// Created by piyum on 12/21/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_CARD_H
#define GOFISHWITHPHILOSOPHERS2_CARD_H
#include <string>
using namespace std;

class Card
{
private:
    int index;  // 1- 13 spades, 14-26 clubs, 27-39 hearts, 40-52 diamonds
    string name;
public:
    explicit Card(int index);
    string getName();
    int getIndex() const;
};


#endif //GOFISHWITHPHILOSOPHERS2_CARD_H
