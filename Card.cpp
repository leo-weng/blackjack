// Leo Weng 903128226

#include <string>
#include <stdlib.h>
#include "Card.h"

Card::Card() {
    int num = rand() % 13;
    std::string types[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    typeString = types[num];
    initial_value = values[num];
}

std::string Card::getType() const {
    return typeString;
}

int Card::getValue() const {
    return initial_value;
}
