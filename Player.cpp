//
// Created by piyum on 12/21/2022.
//

#include "Player.h"
#include <utility>
#include <iostream>
using namespace std;

Player::Player(string name, int playerID)
{
    this->name = std::move(name);
    this->playerID = playerID;
    setsMade = 0;
    for (int i = 0; i < 13; i++)
        handMap[i] = 0;
}

string Player::getName()
{
    return name;
}

vector<Card>& Player::getCurrentHand()
{
    return currentHand;
}

int Player::getSetsMade() const
{
    return setsMade;
}

void Player::addSet()
{
    setsMade++;
}

int Player::getPlayerID() const
{
    return playerID;
}

void Player::updateMap()
{
    int cardIndex = currentHand[currentHand.size() - 1].getIndex() % 13;
    handMap[cardIndex]++;
    cout << "debug4 " << handMap[cardIndex] << endl;
}

map<int, int> &Player::getHandMap()
{
    return handMap;
}

void Player::displayHand()
{
    cout << "Player " << playerID << ": " << name << endl;
    cout << "Current Hand" << endl;
    cout << "------------" << endl;
    if (currentHand.empty())
        cout << name << " has no cards in their hand." << endl;
    else
    {
        for (auto & i : currentHand)
            cout << i.getName() << endl;
    }


    cout << endl;
}