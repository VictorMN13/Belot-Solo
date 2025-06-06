#include "../include/Pachet.h"
#include <random>
#include <algorithm>
#include <ranges>

Pachet::Pachet() {
    //std::cout << "constructor fara perametru Pachet" << std::endl;
    carti->reserve(24);
    for (int i = pica; i <= inima; i++) {
        for (int j = nine; j <= ace; j++) {
            Carte carte(static_cast<Culoare>(i), static_cast<Rank>(j));
            carti->push_back(carte);
        }
    }
}

Pachet::~Pachet() {
    //std::cout << "\ndestructor fara perametru Pachet" << std::endl;
    //delete carti;
}

void Pachet::amestecare(std::vector<Carte>* carti) {
    std::random_device rd;  // sursă de entropie reală
    std::mt19937 gen(rd());
    for (int i = carti->size() - 1; i >= 0; i--) {
        std::uniform_int_distribution<> dist(0, i);
        const int j = dist(gen);
        std::swap((*carti)[i], (*carti)[j]);
    }
}

std::vector<Carte>* Pachet::getPachet() const {
    return this->getContainer();
}

void Pachet::taiere(std::vector<Carte>* carti, const int x) {
    std::ranges::rotate(*carti, carti->begin() + (carti->size()-x));
}

Pachet& Pachet::getInstance() {
    static Pachet instance;
    return instance;
}

std::ostream& operator<<(std::ostream& os, const Pachet& pachet) {
    for (size_t i = 0; i <= pachet.carti->size() - 1; i++) {
        os << (*pachet.carti)[i] << " ";
    }
    return os;
}





