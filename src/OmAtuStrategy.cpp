#include "../include/OmAtuStrategy.h"
#include <unordered_map>
#include "../include/Exceptii.h"
#include <limits>

Culoare OmAtuStrategy::alegere([[maybe_unused]] const PlayHand &hand, int idDealer, int idPlayer) {
    std::unordered_map<std::string, Culoare> map_input = {
        {"1", pica},
        {"2", trefla},
        {"3", diamant},
        {"4", inima},
        {"0", none}
    };

    std::string s;
    std::cin >> s;// tratare exceptii lipsa

    if (!map_input.contains(s)) {
        throw AtuInvalidException();  // Input invalid (nu exista in map)
    }

    const Culoare ales = map_input[s];

    if (idPlayer == idDealer && ales == none) {
        throw PasInterzisException();
    }

    return ales;
}

 bool OmAtuStrategy::jucare([[maybe_unused]] const Culoare c, [[maybe_unused]] PlayHand &hand) {
    int aux;
    if (!(std::cin >> aux)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InputExceptionAtu();
    }

    return aux!=0;
 }

