#include "OmAtuStrategy.h"
#include <unordered_map>

Culoare OmAtuStrategy::alegere(const PlayHand &hand, int idDealer, int idPlayer) {
    std::unordered_map<std::string, Culoare> map_input = {
        {"1", pica},
        {"2", trefla},
        {"3", diamant},
        {"4", inima},
        {"0", none}
    };
    std::cout << "alegeti atu sau da pass\n";
    if (idPlayer== idDealer) {
        std::cout << "sunteti obligat sa alegeti un atu si sa jucati runda\n";
    }
    std::cout << "Optiuni\n";
    std::cout << "1 - pica\n";
    std::cout << "2 - trefla\n";
    std::cout << "3 - diamant\n";
    std::cout << "4 - inima\n";
    std::cout << "0 - niciun atu (pass)\n";
    std::string s;
    std::cin >> s;// tratare exceptii lipsa
    return map_input[s];
}

 bool OmAtuStrategy::jucare(const Culoare c, PlayHand &) {
    int aux;
    std::cout << "Joci acest atu?\n";
    std::cin >> aux;
    return aux!=0;
    //lipsa exceptii
 }

