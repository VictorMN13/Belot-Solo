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
    std::vector<Istoric<int, std::vector<std::string>>*> log;
    static int round_g;
    std::vector<Player*> players;
    std::vector<Istoric<std::string, int>*> points;
    Pachet& pachet;
public:
    Joc();
    ~Joc();
    void modOm();
    void createPlayers();
    void joacaRunda(int);
    void fullGame();
    std::vector<Istoric<int, std::vector<std::string>>*> returnLog();
};

