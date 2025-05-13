#include "../include/Player.h"
#include "../include/PlayHand.h"

int Player::id_gen = 0;

void Player::setHand(const PlayHand& _hand) {
    hand = _hand;
}

PlayHand* Player::getPHand() {
    return &hand;
}
