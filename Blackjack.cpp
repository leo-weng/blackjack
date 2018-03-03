// Leo Weng 903128226

#include <iostream>
#include <string>
#include "Blackjack.h"
#include "Hand.cpp"

Hit_or_Stand Blackjack::queryPlayer() {
    std::string input;
    bool go = true;
    while(go) {
        std::cout << "\n" << "Type (H/h) to HIT, or (S/s) to STAND\t";
        std::cin >> input;
        if (input == "H" || input == "h") {
            return HIT;
        } else if (input == "S" || input == "s") {
            return STAND;
        } else {
            std::cout << "Invalid input, please try again!" << std::endl;
        }
    }
}

double Blackjack::play(double bet) {
    playerBet = bet;
    bool playerBJ = false, dealerBJ = false;        // if anyone has a blackjack
    bool playerWin = false, dealerWin = false;      // if either can possibly win
    bool playerBust = false, dealerBust = false;    // if either busts
    std::string choice; // used for double down

    // deal two cards for each
    ++playerHand;
    ++dealerHand;
    ++playerHand;
    ++dealerHand;

    // player's turn
    playerHand.printHand();
    if (playerHand == 21) { //BLACKJACK!
        playerBJ = true;
        playerWin = true;
    } else {
        bool go = true;
        // choice to double down if player has the money
        if ((playerBet * 2) <= playerMoney) {
            std::cout << "Would you like to double down? (Y/y)\t";
            std::cin >> choice;
        }
        if (choice == "Y" || choice == "y") {
            playerBet *= 2;
            std::cout << "New bet: " << playerBet << std::endl;
            ++playerHand;
            playerHand.printHand();
        } else {
            playerChoice = queryPlayer();
            do {
                if (playerChoice == HIT) {
                    ++playerHand;
                    playerHand.printHand();
                } else {
                    break;
                }
                if (playerHand > 21 || playerHand == 21) {
                    if (playerHand == 21) {
                        playerWin = true;

                    }
                    break;
                }
                playerChoice = queryPlayer();
            } while(go);
        }
    }

    if (playerHand > 21) {    //automatically lose
        std::cout << "Sorry, you busted!" << std::endl;
        playerBust = true;
        playerWin = false;
        dealerWin = true;
    } else {
        // dealer's turn
        dealerHand.printHand();
        if (dealerHand == 21) { // dealer Blackjack!
            dealerBJ = true;
        } else {
            if (!playerBJ) {
                while (dealerHand < 17) {
                    std::cout << "Dealer hits!" << std::endl;
                    ++dealerHand;
                    dealerHand.printHand();
                }
                if (dealerHand > 21) {
                    std::cout << "Dealer busted!!" << std::endl;
                    dealerBust = true;
                    playerWin = true;
                    dealerWin = false;
                } else if (dealerHand == 21) {
                    std::cout << "Dealer stands!" << std::endl;
                    dealerWin = true;
                } else {
                    std::cout << "Dealer stands!" << std::endl;
                }
            }
        }
    }

    std::cout << "\n";
    if (!dealerBust && !playerBust) {
        // compare Blackjacks
        if (playerBJ) {
            if (dealerBJ) { //both blackjack
                std::cout << "You both got blackjack!" << std::endl;
                dealerWin = false;
                playerWin = false;
            } else {    //only player blackjack
                std::cout << "Congrats! You got a blackjack!" << std::endl;
                dealerWin = false;
                playerWin = true;
            }
        } else if (dealerBJ) {  // only dealer blackjack
            std::cout << "Oh man! The dealer got a blackjack!" << std::endl;
            dealerWin = true;
            playerWin = false;
        } else {    // neither blackjack
            if (playerHand > dealerHand) {
                dealerWin = false;
                playerWin = true;
            } else if (playerHand < dealerHand) {
                dealerWin = true;
                playerWin = false;
            } else {
                std::cout << "You both have the same values!" << std::endl;
                dealerWin = false;
                playerWin = false;
            }
        }
    }

    if ((dealerWin && playerWin) || (!dealerWin && !playerWin)) {
        std::cout << "--It's a push!--" << std::endl;
    } else if (playerWin && !dealerWin) {
        std::cout << "$$$YOU WIN$$$" << std::endl;
        playerMoney = playerMoney + (playerBet * 1.5);
    } else if (!playerWin && dealerWin){
        std::cout << "&&&YOU LOSE&&&" << std::endl;
        playerMoney = playerMoney - playerBet;
    }
    std::cout << "\nYour money left: " << playerMoney << " dollars" << std::endl;
    return playerMoney;
}
