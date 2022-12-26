# GoFishWithPhilosophers
the card game Go Fish with AI players based on famous philosophers

current working branch is safety

This file is a description of the project at its current stage. There are 4 sections.
1) goes over the rules of Go Fish
2) describes the code flow
3) describes the classes
4) goes over future steps
some may find it helpful to read through 2) and 3) in parallel to understand the code easier

1).Go Fish rules
----------------
----------------
The goal of Go Fish is to make more sets of 4 than other players.
each player is dealt a  certain number of cards (the number of cards depends on the number of players). The rest of the cards are placed on the deck.
when it's your turn, you ask another player for cards of a type you already have in your hand. (e.g: if your hand is a 3, a 7, two Jacks, and an Ace; you can only ask for 3,7,J or A) The asked player must give all cards they own of that type.
If the asked player does not own any cards of that type, they would say "Go Fish", and you draw a card from the deck. If the deck is empty, it's the next player's turn.
If on your turn your hand is empty, you can't ask for any cards. You draw a card from the deck. You can't ask this turn. IF the deck is empty, next turn.
Once you have a set of 4 in your hand, you put it down. These cards won't be used again in this game.
When there are no more cards in anybody's hand or the deck (i.e: all 13 sets have been made), each player's sets are counted. The one with the most sets wins.

2). Code
--------
--------
main creates a deck object.
creates a singleplayer, multiplayer or partially multiplayer game. passes in the deck and player numbers.
  the base game constructor is initialized and calls shuffle on the deck (deck constructor creates a sorted deck)
  gameSetup is called from the derived class constructor and creates players, taking user input when needed.
  gameplay cycles through playerTurns and aiPlayerTurns until endCondition is met. these functions are in the base Game class.
    playerturn gets input for who and which card to ask. aiplayer turn figures this out itself. currently aiplayers ask a random player for cards of the type which       they have the most of.
      cardGiving functition is called. checks if the asked player has the asked card and updates each players currentHand and handMap accordingly. if the asked player       doesnt have it goFish is called.
        checks fr sets made and updates each players setsMade and totalSetsMade and calls sets announcement if yes.
    endCondition is checked at the end of every turn cycle. if it is, results announcement is called.


3).Classes
----------
----------
Card, Deck, Player, Game, SingleplayerGame, FullyMultiplayerGame, PartiallyMultiplayerGame, RandomNumberGenerator

Card
----
stores the name and id of a card. each card has an id. 1-13 is spades ace to king. 14-26 is clubs. 27-39 is hearts and 40-52 diamonds.
getters.

Deck
----
has a vector of cards w all the cards in the deck.
getter.
a shuffle function.
a deal function for the start of a game.
a draw function for drawing from the deck.

Random Number Generator
-----------------------
what it sounds like. used for shuffling.

Player
------
stores name, playerID, current hand vector, number of sets made, and hand map.
Hand map is a map that stores how many cards of each type the player has. Used for ai player strategy and checking if a set is made.
getters, displayCurrentHand function, updateHandmap function and addSet function (increments nummber of sets made)

Game
-----
This is where things happen. 
stores number of players, total sets made by all players(for determining end of the game), a vector of players, the deck, a boolean for gameOver, and the type of game 
getters
deal helper function - lets deal know how many cards a player should get depending on numPlayers
create player function
a function handling card giving (player asking another for a card, and its consequences)
checks for if a set is made, if a player's ask is valid, if the game is over
a function handling go fish condition (when the player one asked a card for doesnt have it)
a function handling empty hand condition (when a player's hand is empty)
functions for announcing when a set is made and when the game is over
a wait function to wait a number of seconds between phases of the game or turns
a playerTurn function that handles a human players turn
an aiPlayerTurn function handling an ai players turn

FullyMultiplayerGame
--------------------
inherits Game class
has a gameSetup function and gameplay function which are tailored for a human only game. 

SinglePlayerGame
----------------
inherits Game class
has a gameSetup function and gameplay function which are tailored for a one human vs ai game. 

PartiallyMultiplayerGame
------------------------
inherits Game class
has a gameSetup function and gameplay function which are tailored for a mixed game.
number of human players can be changed and the remainder of totalPlayers will be AI players.
A fully AI player game is possible by selecting 0 human players.
