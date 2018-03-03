#include <iostream>
#include "Hand.cpp"
#include <string>

int main() {
    Hand hand("Player");
    ++hand;
    ++hand;
    hand.printHand();
    hand.printFirstCard();

    Hand hand2("Dealer");
    ++hand2;
    ++hand2;
    ++hand2;
    hand2.printHand();

    if (hand > hand2)
        std::cout << "Hand > hand2" << std::endl;
    else if (hand < hand2)
        std::cout << "Hand < hand2" << std::endl;
    else if (hand == hand2)
        std::cout << "Hand = hand2" << std::endl;
    else
        std::cout << "wat" << std::endl;

}
