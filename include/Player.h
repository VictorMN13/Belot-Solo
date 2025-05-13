#pragma once
#include <iostream>
#include "CardsWon.h"
#include "PlayHand.h"

class Player {
protected:
    int id;
    static int id_gen;
    std::string name;
    PlayHand hand;
    //CardsWon cardsWon;
public:
    Player(const std::string& _name = "Unknown"): id(id_gen), name(_name) {id_gen++;};
    Player(const Player&) = delete;
    virtual ~Player() = default;
    void setHand(const PlayHand& _hand);
    PlayHand* getPHand();
    virtual bool joacaAtu(Culoare) = 0;
    virtual Culoare alegeAtu(int) = 0;
    //std::vector<int> combinatii() {};
};

