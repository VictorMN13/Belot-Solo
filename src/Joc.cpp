#include "../include/Joc.h"

Joc::Joc(): pachet(Pachet::getInstance()) {
    round_g = 0;
}

int Joc::round_g = 0;

Joc::~Joc() {
    for (int i = 0; i < players.size(); i++) {
        delete players[i];
        delete points[i];
    }
}

void Joc::createPlayers() {
    auto sa_bot1 = std::make_unique<BotAtuStrategy>();
    auto sa_bot2 = std::make_unique<BotAtuStrategy>();
    auto sa_om = std::make_unique<OmAtuStrategy>();
    auto sa_om1 = std::make_unique<BotAtuStrategy>();

    auto sj_bot1 = std::make_unique<BotJoacaStrategy>();
    auto sj_bot2 = std::make_unique<BotJoacaStrategy>();
    auto sj_om = std::make_unique<OmJoacaStrategy>();
    auto sj_om1 = std::make_unique<BotJoacaStrategy>();

    std::string x;
    std::cout << "Introduceti nickname-ul dvs:\n";
    std::getline(std::cin, x);
    players.push_back(new Om(std::move(sa_om1), std::move(sj_om1), (x!="")? x : "OM"));
    x = "";
    std::cout << "Introduceti numele primului bot:\n";
    std::getline(std::cin, x);
    players.push_back(new Bot(std::move(sa_bot1), std::move(sj_bot1), (x!="")? x : "BOT1"));
    x = "";
    std::cout << "Introduceti numele celui de-al doilea bot:\n";
    std::getline(std::cin, x);
    players.push_back(new Bot(std::move(sa_bot2), std::move(sj_bot2), (x!="")? x : "BOT2"));

    x = players[0]->getName();
    points.push_back(new Istoric<std::string, int>(x, 0));
    x = players[1]->getName();
    points.push_back(new Istoric<std::string, int>(x, 0));
    x = players[2]->getName();
    points.push_back(new Istoric<std::string, int>(x, 0));
}

void Joc::joacaRunda(int dealer) const {
    Runda r(players, dealer);
    Runda::impartireCarti(r);
    r.desfasoara();
    r.rezultate();
    Runda::afisPctRunda(r);
    Runda::returnareCarti(r);
    Pachet::amestecare(pachet.getPachet());
    for (int i = 0; i <= 2; i++) {
        points[i]->addSecond(players[i]->get_pct_runda());
    }
}

void Joc::fullGame() {
    createPlayers();
    Utilities::clearScreen();
    int dealer = 0;
    bool toate101 = std::all_of(points.begin(), points.begin() + 3, [](const auto& p) {
                        return p->getSecond() < 101;});
    while (toate101) {
        Utilities::clearScreen();
        joacaRunda(dealer);
        dealer = (dealer+1) % 3;
        toate101 = std::all_of(points.begin(), points.begin() + 3, [](const auto& p) {
                        return p->getSecond() < 101;});
    }
    for (int i = 0; i <= 2; i++) {
        std::cout << points[i]->getSecond() << " ";
    }
    std::cout << std::endl;
}




