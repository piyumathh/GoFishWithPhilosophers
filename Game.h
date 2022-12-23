//
// Created by piyum on 12/21/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_GAME_H
#define GOFISHWITHPHILOSOPHERS2_GAME_H
#include <vector>
#include <iostream>
#include "Player.h"
#include "Deck.h"
using namespace std;

class Game
{
private:
    int numPlayers;
    int totalSetsMade;
    vector<Player> players;
    Deck deck;
    bool gameOver;
public:
    Game(int numPlayers, Deck& d);
    vector<Player>& getPlayers();
    [[nodiscard]] int getNumPlayers() const;
    void createPlayer(const string& name, int turnOrder);
    void dealHelper();
    [[nodiscard]] bool getEndCondition() const;
    Deck& getDeck();
    void cardGiving(Player& askedPlayer, Player& playerThatAsked, int askedCardID);
    static bool validAskCheckCard(Player& playerThatAsked, int askedCardIndex);
    bool validAskCheckPlayer(Player& playerThatAsked, int askedPlayerIndex) const;
    void setMadeCheck(Player& player);
    void endConditionCheck();
    void goFish(Player& askedPlayer, Player& playerThatAsked, int askedCardID);
    void resultsAnnouncement();
    static void setAnnouncement(Player& player, int cardIndex);
    void playerTurn(Player& currentPlayer);
};


#endif //GOFISHWITHPHILOSOPHERS2_GAME_H
