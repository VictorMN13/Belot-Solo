#include <iostream>
#include "include/PlayHand.h"
#include "include/Pachet.h"
#include "include/Om.h"
#include "include/Bot.h"
#include "include/Runda.h"
#include "AtuStrategy.h"
#include "include/BotAtuStrategy.h"
#include "include/OmAtuStrategy.h"
#include "include/BotJoacaStrategy.h"
#include "include/OmJoacaStrategy.h"

int main() {
    Pachet& pachet = Pachet::getInstance();
    std::cout << pachet << '\n';
    Pachet::amestecare(pachet.getPachet());
    std::cout << pachet << std::endl;
    Pachet::taiere(pachet.getPachet(), 6);
    std::cout << pachet;
    std::vector<Player*> players1;
    auto s_bot1 = std::make_unique<BotAtuStrategy>();
    auto s_bot2 = std::make_unique<BotAtuStrategy>();
    auto s_om = std::make_unique<OmAtuStrategy>();
    auto s_jbot1 = std::make_unique<BotJoacaStrategy>();
    auto s_jbot2 = std::make_unique<BotJoacaStrategy>();
    auto s_jom = std::make_unique<BotJoacaStrategy>();
    auto s_jom1 = std::make_unique<OmJoacaStrategy>();
    auto s_om1 = std::make_unique<BotAtuStrategy>();
    players1.push_back(new Om(std::move(s_om), std::move(s_jom1), "Victor"));
    players1.push_back(new Bot(std::move(s_bot1), std::move(s_jbot1), "Bot1"));
    players1.push_back(new Bot(std::move(s_bot2), std::move(s_jbot2), "Bot2"));

    players1[0]->setJoacaStrategy(std::move(s_jom));
    players1[0]->setAtuStrategy(std::move(s_om1));

    Runda r(players1, 0);
    Runda::impartireCarti(r);
    r.desfasoara();
    r.rezultate();
    Runda::returnareCarti(r);
    Pachet::aranjare(pachet);
    std::cout << '\n';
    std::cout << pachet;
    for (int i = 0; i < players1.size(); i++) {
        delete players1[i];
    }
}
