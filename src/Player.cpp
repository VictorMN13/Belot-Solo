#include "../include/Player.h"
#include "../include/PlayHand.h"
#include <random>
#include "../include/OmJoacaStrategy.h"

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

void Player::set_pct_runda(int _pct_runda) {
    pct_runda = _pct_runda;
}

const std::string& Player::getName() {
    return name;
}

int Player::get_pct_runda() const {
    return pct_runda;
}

int Player::taiereCarti() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 23);
    return distrib(gen);
}

bool Player::humanStrategy() const {
    if (dynamic_cast<OmJoacaStrategy*>(joaca_strategy.get()))
        return true;
    else
        return false;
}



