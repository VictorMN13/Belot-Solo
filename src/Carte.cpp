#include "../include/Carte.h"

Carte::Carte(const Culoare cul, const Rank ran): culoare(cul), rank(ran){};

Carte::Carte() {
    culoare = Culoare();
    rank = Rank();
}

int Carte::getCuloare() const {
    return culoare;
}

int Carte::getRank() const {
    return rank;
}

std::ostream& operator<<(std::ostream& os, const Carte& carte) {
    switch (carte.rank) {
        case nine: os << "9"; break;
        case ten: os << "10"; break;
        case jack: os << "J"; break;
        case queen: os << "Q"; break;
        case king: os << "K"; break;
        case ace: os << "A"; break;
        default: os << "0"; break;
    }
    switch (carte.culoare) {
        case pica: os << "♠"; break;
        case trefla: os << "♣"; break;
        case diamant: os << "♦"; break;
        case inima: os << "♥"; break;
        default: os << "0"; break;
    }
    return os;
}






