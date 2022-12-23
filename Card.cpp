//
// Created by piyum on 12/21/2022.
//

#include "Card.h"
Card::Card(int index)
{
    this->index = index;
    //name assignment
    if (index % 13 > 1 && index % 13 < 11)
        name = to_string(index % 13);
    else if (index % 13 == 11)
        name = "Jack";
    else if (index % 13 == 12)
        name = "Queen";
    else if (index % 13 == 1)
        name = "Ace";
    else
        name = "King";

    name += " of ";

    if (index < 14)
        name += "Spades";
    else if (index < 27)
        name += "Clubs";
    else if (index < 40)
        name += "Hearts";
    else
        name+= "Diamonds";
}

string Card::getName()
{
    return name;
}

int Card::getIndex() const
{
    return index;
}