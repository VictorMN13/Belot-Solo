#include "../include/Player.h"
#include "../include/PlayHand.h"

int Player::id_gen = 0;

void Player::setHand(const PlayHand& _hand) {
    hand = _hand;
}

PlayHand* Player::getPHand() {
    return &hand;
}

CardsWon *Player::getCardsWon() {
    return &cardsWon;
}

void Player::setJoacaStrategy(std::unique_ptr<JoacaStrategy> _joaca_strategy) {
    joaca_strategy = std::move(_joaca_strategy);
}

void Player::setAtuStrategy(std::unique_ptr<AtuStrategy> _atu_strategy) {
    atu_strategy = std::move(_atu_strategy);
}

