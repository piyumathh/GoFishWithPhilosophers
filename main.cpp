#include "Deck.h"
#include "FullyMultiplayerGame.h"
#include "SingleplayerGame.h"
using namespace std;

int main()
{
    Deck deck;
    //FullyMultiplayerGame game(4, deck);
    SingleplayerGame game(4, deck);
    return 0;
}

/* ---Necessary Fixes-----
 * 1) a player with no cards in their hand can still be asked for a card. It will just go to goFish.
 *    Better to say ask someone else.
 */