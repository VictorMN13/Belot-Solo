#include <iostream>
#include "include/PlayHand.h"
#include "include/Pachet.h"
#include "include/Om.h"
#include "include/Bot.h"
#include "include/Runda.h"

int main() {
    Pachet& pachet = Pachet::getInstance();
    std::cout << pachet << '\n';
    Pachet::amestecare(pachet.getPachet());
    std::cout << pachet << std::endl;
    Pachet::taiere(pachet.getPachet(), 6);
    std::cout << pachet;
    std::vector<Player*> players1;
    players1.push_back(new Om("Victor"));
    players1.push_back(new Bot("Bot1"));
    players1.push_back(new Bot("Bot2"));

    Runda r(players1, 0);
    Runda::impartireCarti(r);

    for (int i = 0; i < players1.size(); i++) {
        delete players1[i];
    }
}