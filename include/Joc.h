#pragma once
#include "tIstoric.h"
#include "Om.h"
#include "Pachet.h"

class Joc {
    std::vector<Istoric<int, std::vector<std::string>>*> log;
    static int round_g;
    std::vector<Player*> players;
    std::vector<Istoric<std::string, int>*> points;
    Pachet& pachet;
public:
    Joc();
    ~Joc();
    void modOm() const;
    void createPlayers();
    void joacaRunda(int);
    void fullGame();
    std::vector<Istoric<int, std::vector<std::string>>*> returnLog();
};

