//
// Created by piyum on 12/21/2022.
//

#include "Game.h"
#include <bits/stdc++.h>
using namespace std;

Game::Game(int numPlayers, Deck &d)
{
    this->numPlayers = numPlayers;
    deck = d;
    gameOver = false;
    totalSetsMade = 0;
    deck.Shuffle(); //this stuff is common for all sorts of games and happens first
}

void Game::createPlayer(const string& name, int turnOrder)
{
    players.emplace_back(name, turnOrder);      //emplace is basically pushing back a new creation
}

void Game::dealHelper()
{   //this calls Deal
    int cardsPerPlayer;
    if (numPlayers == 3)
        cardsPerPlayer = 8;
    else if (numPlayers == 4)
        cardsPerPlayer = 7;
    else if (numPlayers == 6)
        cardsPerPlayer = 6;
    else
        cardsPerPlayer = 5;

    deck.Deal(cardsPerPlayer, players);
}

vector<Player> &Game::getPlayers()
{
    return players;
}

int Game::getNumPlayers() const
{
    return numPlayers;
}

bool Game::getEndCondition() const
{
    return gameOver;
}

Deck &Game::getDeck()
{
    return deck;
}

void Game::playerTurn(Player& currentPlayer)
{
    if (!currentPlayer.getCurrentHand().empty())
    {
        currentPlayer.displayHand();
        cout << "Ask a player for a card" << endl;

        int playerNum;
        int cardIndex;
        bool validAskCard = false;
        bool validAskPlayer = false;

        while (!validAskPlayer)
        {
            cout << "Enter the number of the player" << endl;
            for (int k = 0; k < getNumPlayers(); k++)
            {
                if (currentPlayer.getPlayerID() != k + 1)
                    cout << to_string(k+1) << ". " << getPlayers()[k].getName() << endl;
            }
            cin >> playerNum;
            if (validAskCheckPlayer(currentPlayer, playerNum))
                validAskPlayer = true;
            else
                cout << "Ask a player from the list." << endl;
        }

        //set a check for invalid asks
        while (!validAskCard)
        {
            cout << "Enter the card you want (type 11, 12, 0, 1 for Jack, Queen, King, Ace)" << endl;
            cin >> cardIndex;
            if (validAskCheckCard(currentPlayer, cardIndex))
            {
                validAskCard = true;
                cardGiving(getPlayers()[playerNum-1], currentPlayer, cardIndex);
            }
            else
                cout << "You can only ask for cards of a type you already have. Ask again!" << endl;
        }
    }
    else
    {
        currentPlayer.displayHand();
        if (!getDeck().getCards().empty())
        {
            currentPlayer.getCurrentHand().push_back(getDeck().Draw());
            cout << currentPlayer.getName() << " draws " << currentPlayer.getCurrentHand()[0].getName() << endl;  //0 coz there's only one card in hand at this stage
        }
        else
            cout << "There are no more cards in the deck! You have " << currentPlayer.getSetsMade() << " sets!" << endl;
    }
}

void Game::cardGiving(Player &askedPlayer, Player &playerThatAsked, int askedCardID)
{   //debug this. not all cards given
    bool hasMatches = false;
    for (int i = 0; i < askedPlayer.getCurrentHand().size(); i++)
    {
        if (askedPlayer.getCurrentHand()[i].getIndex() % 13 == askedCardID)
        {
            hasMatches = true;
            cout << askedPlayer.getName() << " gives " << playerThatAsked.getName() << " the " << askedPlayer.getCurrentHand()[i].getName() << endl;
            playerThatAsked.getCurrentHand().push_back(askedPlayer.getCurrentHand()[i]);
            playerThatAsked.updateMap();
            askedPlayer.getCurrentHand().erase(askedPlayer.getCurrentHand().begin() + i);
            askedPlayer.getHandMap()[askedCardID]--;
            i--;
        }
    }
    if (!hasMatches)
        goFish(askedPlayer, playerThatAsked, askedCardID);
    cout << "debug1" << endl;
    setMadeCheck(playerThatAsked);
}

bool Game::validAskCheckPlayer(Player &playerThatAsked, int askedPlayerIndex) const
{
    if (askedPlayerIndex > 0 && askedPlayerIndex <= getNumPlayers() && askedPlayerIndex != playerThatAsked.getPlayerID())
        return true;
    else
        return false;
}
bool Game::validAskCheckCard(Player &playerThatAsked, int askedCardIndex)
{
    if (playerThatAsked.getHandMap()[askedCardIndex] != 0)
        return true;
    else
        return false;
}

void Game::goFish(Player& askedPlayer, Player& playerThatAsked, int askedCardID)
{
    cout << askedPlayer.getName() << " doesn't have any " << askedCardID << "s. Go Fish!" << endl;
    if (!deck.getCards().empty())
    {
        playerThatAsked.getCurrentHand().push_back(deck.Draw());
        playerThatAsked.updateMap();
        cout << playerThatAsked.getName() << " draws " << playerThatAsked.getCurrentHand()[playerThatAsked.getCurrentHand().size()-1].getName() << endl;
    }
    else
        cout << "No more cards in the deck. Next turn!" << endl;
}

void Game::endConditionCheck()
{
    if (totalSetsMade == 13)
        gameOver = true;
}

void Game::setMadeCheck(Player &player)
{   //debug. set was made but only 3 cards were erased.
    //error due to erasing making container smaller
    for (int i = 0; i < 13; i++)    //hardcoded coz card packs are pretty standard yeah?
    {
        if (player.getHandMap()[i] == 4)
        {
            player.addSet();
            totalSetsMade++;
            cout << "debug2" << endl;
            setAnnouncement(player, i);
            player.getHandMap()[i] = 0;
            for (int j = 0; j < player.getCurrentHand().size(); j++)    //goes through the hand to find cards of the type that made the set
            {
                if (player.getCurrentHand()[j].getIndex() % 13 == i)    //check to see if the card being checked is a set card
                {
                    player.getCurrentHand().erase(player.getCurrentHand().begin() + j); //removes it from hand
                    j--;
                }
            }
        }
    }
}

void Game::resultsAnnouncement()
{   //handle tied cases later
    priority_queue<int, vector<int>, greater<>> results;
    for (const auto & i : getPlayers())
        results.push(i.getSetsMade());

    cout << endl;
    cout << "That's all folks!" << endl;
    for (auto & i : getPlayers())
        cout << i.getPlayerID() << ". " << i.getName() << " sets: " << i.getSetsMade() << endl;
}

void Game::setAnnouncement(Player &player, int cardIndex)
{
    cout << "debug3" << endl;
    string cardName;
    if (cardIndex == 0)
        cardName = "King";
    else if (cardIndex == 1)
        cardName = "Ace";
    else if (cardIndex == 11)
        cardName = "Jack";
    else if (cardIndex == 12)
        cardName = "Queen";
    else
        cardName = to_string(cardIndex);
    cout << player.getName() << " has made a set of " << cardName << "s!" << endl;
}