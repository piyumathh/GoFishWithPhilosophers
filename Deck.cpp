//
// Created by piyum on 12/21/2022.
//

#include "Deck.h"
Deck::Deck()
{
    for (int i = 1; i < 53; i++)
        cards.emplace_back(i);  //creates sorted deck
}

void Deck::Shuffle()
{   //https://www.youtube.com/watch?time_continue=362&v=Bsyvs82XliM&feature=emb_title&ab_channel=JohnSeiffertt
    vector<Card> newCards;
    while (!cards.empty())
    {
        int rand = RandomNumberGenerator::RandInt(0, cards.size() - 1);
        newCards.push_back(cards[rand]);
        cards.erase(cards.begin() + rand);
    }
    for (int i = 0; i < 52; i++)
    {
        cards.push_back(newCards[51 - i]);
        newCards.pop_back();        //shuffle empties temporary newCards vector and repopulates cards vector
    }
}

vector<Card> &Deck::getCards()
{
    return cards;
}

Card Deck::Draw()
{
    Card c = cards[cards.size() -1];    //drawing a card from top of the deck
    cards.pop_back();
    return c;
}

void Deck::Deal(int perPlayer, vector<Player>& players)
{
    cout << "Dealing cards" << endl;
    cout << "............." << endl;
    while (perPlayer > 0)   //repeats for a number of times
    {
        for (auto & player : players)   //each player gets a Drawn card
        {
            player.getCurrentHand().push_back(Draw());
            player.updateMap();
        }
        perPlayer--;
    }
}