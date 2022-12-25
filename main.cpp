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

/* -----Necessary Fixes & To-Dos-----
 * 1). a player with no cards in their hand can still be asked for a card. It will just go to goFish.
 *     Better to say ask someone else.
 *     FIXED - not tested.
 * 2). add comments and unit tests
 * 3). results should have ranking
 * 4). remove debug statements from FM
 * 5). function for cardNameConversion based on card index breaks the build.
 *     Figure out why and implement to avoid repeated code
 * 6). Implement a wait time function before big print statements.
 * 7). Play a full single player game to test if it works good.
 */