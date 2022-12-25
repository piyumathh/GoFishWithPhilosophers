//
// Created by piyum on 12/24/2022.
//

#include "SingleplayerGame.h"

SingleplayerGame::SingleplayerGame(int numPlayers, Deck &d) : Game(numPlayers, d)
{
    aiPlayerNames.emplace_back("Socrates");
    aiPlayerNames.emplace_back("Descartes");
    aiPlayerNames.emplace_back("Nietzsche");
    gameSetup();
    gameplay();
}

void SingleplayerGame::gameSetup()
{
    string s;
    cout << "Enter Player " << 1 << " name:" << endl;
    cin >> s;
    createPlayer(s,  1);

    //create AI players
    for (int i = 1; i < getNumPlayers(); i++)
        createPlayer(aiPlayerNames[i - 1], i + 1);

    cout << endl;
    dealHelper();
}

void SingleplayerGame::gameplay()
{
    while (!getEndCondition())
    {
        playerTurn(getPlayers()[0]); //the human player
        endConditionCheck();
        for (int i = 1; i < getNumPlayers(); i++)
        {
            aiPlayerTurn(getPlayers()[i]);
            endConditionCheck();
        }
    }
    cout << endl;
    resultsAnnouncement();
}
