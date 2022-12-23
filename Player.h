//
// Created by piyum on 12/21/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_PLAYER_H
#define GOFISHWITHPHILOSOPHERS2_PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "Card.h"
using namespace std;

class Player
{
private:
    string name;
    int setsMade;
    int playerID;
    vector<Card> currentHand;
    map<int, int> handMap;
public:
    Player(string name, int playerID);
    void addSet();
    [[nodiscard]] int getSetsMade() const;
    [[nodiscard]] int getPlayerID() const;
    vector<Card>& getCurrentHand();
    string getName();
    void updateMap();
    map<int, int>& getHandMap();
    void displayHand();
};


#endif //GOFISHWITHPHILOSOPHERS2_PLAYER_H
