#include "../include/OmAtuStrategy.h"
#include <unordered_map>
#include "../include/Exceptii.h"
#include <limits>

Culoare OmAtuStrategy::alegere(const PlayHand &hand, int idDealer, int idPlayer) {
    std::unordered_map<std::string, Culoare> map_input = {
        {"1", pica},
        {"2", trefla},
        {"3", diamant},
        {"4", inima},
        {"0", none}
    };

    std::string s;
    std::cin >> s;// tratare exceptii lipsa

    if (map_input.find(s) == map_input.end()) {
        throw AtuInvalidException();  // Input invalid (nu exista in map)
    }

    Culoare ales = map_input[s];

    if (idPlayer == idDealer && ales == none) {
        throw PasInterzisException();
    }

    return ales;
}

 bool OmAtuStrategy::jucare(const Culoare c, PlayHand &hand) {
    int aux;
    if (!(std::cin >> aux)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InputExceptionAtu();
    }

    return aux!=0;
 }

