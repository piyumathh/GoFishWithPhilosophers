//
// Created by piyum on 12/21/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_DECK_H
#define GOFISHWITHPHILOSOPHERS2_DECK_H
#include "Card.h"
#include "RandomNumberGenerator.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;

class Deck
{
private:
    vector<Card> cards;
public:
    Deck();
    void Shuffle();
    void Deal(int perPlayer, vector<Player>& players);
    Card Draw();
    vector<Card>& getCards();
};


#endif //GOFISHWITHPHILOSOPHERS2_DECK_H
