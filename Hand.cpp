// Leo Weng 903128226

#include <iostream>
#include <string>
#include "Card.cpp"
#include "Hand.h"

void Hand::updateValue() {
    value += cards[number_of_cards]->getValue();
    if (value > 21 && number_of_aces > 0) {
        value -= 10;
        number_of_aces --;
    }
    number_of_cards ++;
}

Hand::Hand(std::string person) {
    hand_holder = person;
    value = 0;
    number_of_cards = 0;
    number_of_aces = 0;
}

Hand::~Hand() {
    delete[] cards;
}

Hand& Hand::operator++() {
    Card *card = new Card();
    if (card->getType() == "Ace") {
        number_of_aces ++;
    }
    cards[number_of_cards] = card;
    //std::cout << card->getType() << " " << card->getValue() << std::endl;
    //std::cout << cards[number_of_cards]->getType() << " " << cards[number_of_cards]->getValue() << std::endl;
    updateValue();
    return *this;
}

bool Hand::operator>(const Hand & rhs) const {
    if (value > rhs.value)
        return true;
    return false;
}
bool Hand::operator>(int rhs) const {
    if (value > rhs)
        return true;
    return false;
}

bool Hand::operator<(const Hand & rhs) const {
    if (value < rhs.value)
        return true;
    return false;
}
bool Hand::operator<(int rhs) const {
    if (value < rhs)
        return true;
    return false;
}

bool Hand::operator==(const Hand & rhs) const {
    if (value == rhs.value)
        return true;
    return false;
}
bool Hand::operator==(int rhs) const {
    if (value == rhs)
        return true;
    return false;
}

void Hand::printHand() {
    std::cout << "\n";
    std::cout << hand_holder << "'s hand is: ";
    for (int i = 0; i < number_of_cards; i++) {
        std::cout << cards[i]->getType();
        if (i != number_of_cards - 1)
        {
            std::cout << ", ";
        } else {
            std::cout << "\n";
        }
    }
    std::cout << hand_holder << "'s hand value is: " << value << std::endl;
}

void Hand::printFirstCard() {
    std::cout << "First card is: " << cards[0]->getType() << std::endl;
}
