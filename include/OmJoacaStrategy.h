#include "JoacaStrategy.h"

class OmJoacaStrategy: public JoacaStrategy {
public:
    OmJoacaStrategy() = default;
    ~OmJoacaStrategy() = default;
    Carte miscare(std::vector<Carte> &, bool, Puncte &, Culoare, PlayHand &, int, int) override;
};