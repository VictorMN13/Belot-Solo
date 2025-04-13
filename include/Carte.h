#pragma once
#include <iostream>

enum Culoare {pica=0, trefla, diamant, inima};
enum Rank {nine=0, ten, jack, queen, king, ace};

class Carte {
    Culoare culoare;
    Rank rank;
public:
    Carte();
    Carte(Culoare cul, Rank ran);
    ~Carte() = default;
    Culoare getCuloare() const;
    Rank getRank() const;
    friend std::ostream& operator<<(std::ostream& os, const Carte& carte);
    bool operator==(const Carte &carte) const;
    bool operator>(const Carte &carte) const;
    bool operator<(const Carte &carte) const;
};
