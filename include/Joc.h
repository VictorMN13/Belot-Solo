#pragma once
#include "Runda.h"
#include "tIstoric.h"
#include "BotAtuStrategy.h"
#include "Om.h"
#include <algorithm>
#include "Bot.h"
#include "OmAtuStrategy.h"
#include "BotJoacaStrategy.h"
#include "OmJoacaStrategy.h"

class Joc {
    static int round_g;
    std::vector<Player*> players;
    std::vector<Istoric<std::string, int>*> points;
    Pachet& pachet;
public:
    Joc();
    ~Joc();
    void createPlayers();
    void joacaRunda(int) const;
    void fullGame();
};

