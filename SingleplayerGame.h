//
// Created by piyum on 12/24/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_SINGLEPLAYERGAME_H
#define GOFISHWITHPHILOSOPHERS2_SINGLEPLAYERGAME_H
#include "Game.h"
#include <string>
using namespace std;

class SingleplayerGame : public Game
{
private:
    vector<string> aiPlayerNames;
public:
    SingleplayerGame(int numPlayers, Deck &d);
    void gameSetup();
    void gameplay();
};


#endif //GOFISHWITHPHILOSOPHERS2_SINGLEPLAYERGAME_H
