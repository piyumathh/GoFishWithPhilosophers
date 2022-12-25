//
// Created by piyum on 12/21/2022.
//

#include "FullyMultiplayerGame.h"
FullyMultiplayerGame::FullyMultiplayerGame(int numPlayers, Deck &d) : Game(numPlayers, d)
{   //add this point numPlayers has been assigned and deck has been created and shuffled
    gameSetup();
    gameplay();
}

void FullyMultiplayerGame::gameSetup()
{
    for (int i = 0; i < Game::getNumPlayers(); i++)    //creates players
    {
        string s;
        cout << "Enter Player " << i + 1 << " name:" << endl;
        cin >> s;
        createPlayer(s, i + 1);
    }
    cout << endl;
    dealHelper();   //deal helper calls Deal() with the number of cardsPerPlayer. Cards are dealt after this line
}

void FullyMultiplayerGame::gameplay()
{
    while (!getEndCondition())
    {
        for (auto & i : getPlayers())
        {
            playerTurn(i);
            endConditionCheck();
        }
    }
    cout << endl;
    resultsAnnouncement();
}