//
// Created by piyum on 12/26/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_PARTIALLYMULTIPLAYERGAME_H
#define GOFISHWITHPHILOSOPHERS2_PARTIALLYMULTIPLAYERGAME_H
#include "Game.h"

class PartiallyMultiplayerGame : public Game
{
private:
    vector<string> aiPlayerNames;
    int numHumans;
public:
    PartiallyMultiplayerGame(int numPlayers, int numHumans, Deck &d);
    void gameSetup();
    void gameplay();
};


#endif //GOFISHWITHPHILOSOPHERS2_PARTIALLYMULTIPLAYERGAME_H
