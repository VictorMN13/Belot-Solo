#include "../include/Runda.h"
#include "../include/Pachet.h"
#include "../include/PlayHand.h"
#include "../include/Player.h"
#include "../include/Om.h"
#include "../include/Bot.h"

Runda::Runda(const std::vector<Player*>& _players, const int _id):
    players(_players), dealer(_id) {

}

void Runda::setDeclarant(Runda & ob, int i) {
    ob.declarant = i;
}


void Runda::setAtu(Runda& ob, const Culoare c) {
    ob.atu = c;
}

void Runda::impartireCarti(Runda& r) {
    Pachet& p = Pachet::getInstance();
    std::vector<Carte>* carti_r = p.getPachet();
    PlayHand p1;
    PlayHand p2;
    PlayHand p3;
    for (int i=0; i<5; i++) {
        p1.add(carti_r->back());
        carti_r->pop_back();
        p2.add(carti_r->back());
        carti_r->pop_back();
        p3.add(carti_r->back());
        carti_r->pop_back();
    }
    r.players[(r.dealer+1)%3]->setHand(p1);
    r.players[(r.dealer+2)%3]->setHand(p2);
    r.players[r.dealer]->setHand(p3);
    std:: cout<< carti_r->back().getCuloare() << std::endl;
    for (int i=r.dealer+1; i<=r.dealer+3; i++) {
        std::cout << *(r.players[i%3]->getPHand()) << std::endl;
        if (r.players[i%3]->joacaAtu(carti_r->back().getCuloare())) {
            setAtu(r, carti_r->back().getCuloare());
            setDeclarant(r, i%3);
            break;
        };
    }
    if (r.declarant == -1) {
        for (int i=r.dealer+1; i<=r.dealer+3; i++) {
            // am ramas aici tre sa completez sa se aleaga atuul
            r.players[i%3]->alegeAtu(r.dealer);
        }
    }

    std::cout << r.atu << r.declarant << std::endl;


    std::cout << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}
