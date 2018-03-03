#include <iostream>
#include "Card.cpp"
#include <string>

int main() {
    for (int i = 0; i < 9; i++) {
        Card *card = new Card();
        std::cout << card->getType() << " " << card->getValue() << std::endl;
    }
}
