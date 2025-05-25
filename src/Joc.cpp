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
    for (const auto ist: log) {
        delete ist;
    }
}

void Joc::createPlayers() {
    auto sa_bot1 = std::make_unique<BotAtuStrategy>();
    auto sa_bot2 = std::make_unique<BotAtuStrategy>();
    auto sa_om1 = std::make_unique<BotAtuStrategy>();
    auto sj_bot1 = std::make_unique<BotJoacaStrategy>();
    auto sj_bot2 = std::make_unique<BotJoacaStrategy>();
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

void Joc::joacaRunda(int dealer) {
    Pachet::amestecare(pachet.getPachet());
    Runda r(players, dealer);
    Pachet::taiere(pachet.getPachet(), Player::taiereCarti());
    Runda::impartireCarti(r);
    r.desfasoara();
    r.rezultate();
    Runda::afisPctRunda(r);
    Runda::returnareCarti(r);
    Pachet::amestecare(pachet.getPachet());
    for (int i = 0; i <= 2; i++) {
        points[i]->addSecond(players[i]->get_pct_runda());
    }
    log.push_back(new Istoric<int, std::vector<std::string>>((++round_g), r.getLog()));
    std::cout << "==========" << Joc::round_g << std::endl;
}

void Joc::fullGame() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    createPlayers();
    Utilities::clearScreen();
    int dealer = 0;
    bool toate101 = std::all_of(points.begin(), points.begin() + 3, [](const auto& p) {
                        return p->getSecond() < 101;});
    while (toate101) {
        modOm();
        joacaRunda(dealer);
        dealer = (dealer+1) % 3;
        toate101 = std::all_of(points.begin(), points.begin() + 3, [](const auto& p) {
                        return p->getSecond() < 101;});
        std::cout << "\nPunctaj General:\n";
        for (auto x: points) {
            std::cout << x->getFirst() << " " << x->getSecond() << "\n";
        }
        std::cout << "Apasa enter pentru urmatoarea runda\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        Utilities::clearScreen();
    }

    std::cout << "\nPunctaj final:\n";
    for (auto x: points) {
        std::cout << x->getFirst() << " " << x->getSecond() << "\n";
    }
    std::cout << std::endl;
}

void Joc::modOm() {
    int x;
    std::cout << "Tastati 1 daca vreti sa modificati modul de joc sau 0 altfel\n";
    std::cin >> x;
    if (x == 1) {
        std::cout << "Tastati 1 pentru modul manual sau 2 pentru automat\n";
        std::cin >> x;
        switch (x) {
            case 1: {
                auto sa_om = std::make_unique<OmAtuStrategy>();
                auto sj_om = std::make_unique<OmJoacaStrategy>();
                players[0]->setAtuStrategy(std::move(sa_om));
                players[0]->setJoacaStrategy(std::move(sj_om));
                break;
            }
            case 2: {
                auto sa_om1 = std::make_unique<BotAtuStrategy>();
                auto sj_om1 = std::make_unique<BotJoacaStrategy>();
                players[0]->setAtuStrategy(std::move(sa_om1));
                players[0]->setJoacaStrategy(std::move(sj_om1));
                break;
            }
            default: {
                std::cout << "Nu corespunde\n";
                break;
            }
        }
    }
}

std::vector<Istoric<int, std::vector<std::string>>*> Joc::returnLog() {
    return this->log;
}






