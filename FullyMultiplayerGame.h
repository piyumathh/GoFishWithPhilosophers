//
// Created by piyum on 12/21/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_FULLYMULTIPLAYERGAME_H
#define GOFISHWITHPHILOSOPHERS2_FULLYMULTIPLAYERGAME_H
#include "Game.h"

class FullyMultiplayerGame : public Game
{
public:
    FullyMultiplayerGame(int numPlayers, Deck &d);  //inherits Game
    void gameSetup();    //this is where the shit happens
    void gameplay();
};


#endif //GOFISHWITHPHILOSOPHERS2_FULLYMULTIPLAYERGAME_H
