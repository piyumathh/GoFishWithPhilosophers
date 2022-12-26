//
// Created by piyum on 12/26/2022.
//

#include "PartiallyMultiplayerGame.h"
PartiallyMultiplayerGame::PartiallyMultiplayerGame(int numPlayers, int numHumans, Deck &d) : Game(numPlayers, d)
{
        this->numHumans = numHumans;
        vector<string> aiNames = {"Socrates", "Descartes", "Nietzsche"};
        for (int i = 0; i < numPlayers - numHumans; i++)
            aiPlayerNames.push_back(aiNames[i]);
        gameSetup();
        gameplay();
}

void PartiallyMultiplayerGame::gameSetup()
{
    for (int i = 0; i < numHumans; i++)    //creates players
    {
        string s;
        cout << "Enter Player " << i + 1 << " name:" << endl;
        cin >> s;
        createPlayer(s, i + 1);
    }
    for (int i = numHumans; i < getNumPlayers(); i++)
        createPlayer(aiPlayerNames[i - numHumans], i + 1);

    cout << endl;
    dealHelper();
}

void PartiallyMultiplayerGame::gameplay()
{
    while (!getEndCondition())
    {
        for (int i = 0; i < numHumans; i++)
        {
            playerTurn(getPlayers()[i]);
            endConditionCheck();
        }
        for (int i = numHumans; i < getNumPlayers(); i++)
        {
            aiPlayerTurn(getPlayers()[i]);
            wait(4);
            endConditionCheck();
        }
    }
    cout << endl;
    resultsAnnouncement();
}