#include <iostream>
#include "include/Pachet.h"

int main() {
    Pachet pachet;
    std::cout << pachet << '\n';
    Pachet::amestecare(pachet.getPachet());
    std::cout << pachet;
}