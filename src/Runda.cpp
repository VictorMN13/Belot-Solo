#include "../include/Runda.h"
#include "../include/Pachet.h"
#include "../include/PlayHand.h"
#include "../include/Player.h"
#include "../include/Om.h"
#include "../include/Bot.h"

Runda::Runda(const std::vector<Player*>& _players, const int _id):
    players(_players), atu(none), dealer(_id) {
    puncte.init();
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
    if (carti_r->back().getRank() != jack) {
        std::cout << "Cartea decizionala: " << carti_r->back() << std::endl;
        for (int i = r.dealer + 1; i <= r.dealer + 3; i++) {
            //std::cout << *(r.players[i % 3]->getPHand()) << std::endl;
            if (r.players[i % 3]->joacaAtu(carti_r->back().getCuloare())) {
                setAtu(r, carti_r->back().getCuloare());
                setDeclarant(r, i % 3);
                break;
            };
        }
        if (r.declarant == -1) {
            for (int i = r.dealer + 1; i <= r.dealer + 3; i++) {
                Culoare rs_player = r.players[i % 3]->alegeAtu(r.dealer);
                if (rs_player != none) {
                    setDeclarant(r, i % 3);
                    setAtu(r, rs_player);
                };
            }
        }
    } else {
        std::cout << "BIZON\n";
        setDeclarant(r, (r.dealer+1)%3);
        setAtu(r,  carti_r->back().getCuloare());
    }
    r.puncte.set_pct(r.atu);
    std::cout << "Runda este jucata de: " << r.players[r.declarant]->getName() << " cu atu-ul: " << Carte::afisCuloare(r.atu) << "\n";
    for (int i=0; i<3; i++) {
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
}

int Runda::tur(Runda &r, int id_init) {
    CardsWon tur_carti;
    int id_winner;
    Carte win_card;
    std::vector<Carte>& v = tur_carti.get_carti();
    Carte c1 = r.players[id_init]->joaca(v, true, r.puncte, r.atu, r.declarant);
    v.push_back(c1);
    c1 = r.players[(id_init+1)%3]->joaca(v, true, r.puncte, r.atu, r.declarant);
    v.push_back(c1);
    c1 = r.players[(id_init+2)%3]->joaca(v, true, r.puncte, r.atu, r.declarant);
    v.push_back(c1);
    Culoare obl_culoare = v[0].getCuloare();
    if (Utilities::bate(r.atu, v[0], v[1], obl_culoare, r.puncte)) {
        id_winner = (id_init)%3;
        win_card = v[0];
    } else {
        id_winner = (id_init+1)%3;
        win_card = v[1];
    }
    if (Utilities::bate(r.atu, v[2], win_card, obl_culoare, r.puncte)) {
        id_winner = (id_init+2)%3;
        win_card = v[2];
    }
    CardsWon& plWon = *r.players[id_winner]->getCardsWon();
    plWon += tur_carti;
    return id_winner;
}

void Runda::desfasoara() {
    int initiator = declarant;
    for (int i=0; i<8; i++) {
        int x = tur(*this, initiator);
        initiator = x;
        log.push_back("Tur castigat de jucatorul: "+players[x]->getName()+'\n');
    }
}

void Runda::rezultate() {
    int x1 = CardsWon::calcPuncte(*players[(declarant+1)%3]->getCardsWon(), puncte);
    int x2 = CardsWon::calcPuncte(*players[(declarant+2)%3]->getCardsWon(), puncte);
    x1 = std::round(x1/10.0);
    x2 = std::round(x2/10.0);
    int xD = 16 - x1 - x2;
    if (xD == 0)
        xD = -10;
    if (x1 == 0)
        x1 = -10;
    if (x2 == 0)
        x2 = -10;
    //std::cout << x1 << " " << x2 << " " << xD << "\n";
    int maxim = xD;
    maxim = std::max(maxim, x1);
    maxim = std::max(maxim, x2);
    if (maxim!=xD) {
        if (maxim == x1) {
            x1 += xD;
            xD = -10;
            players[declarant]->set_pct_runda(xD);
            players[(declarant+1)%3]->set_pct_runda(x1);
            players[(declarant+2)%3]->set_pct_runda(x2);
        }
        else {
            x2 += xD;
            xD = -10;
            players[declarant]->set_pct_runda(xD);
            players[(declarant+1)%3]->set_pct_runda(x1);
            players[(declarant+2)%3]->set_pct_runda(x2);
        }
    } else {
        players[declarant]->set_pct_runda(xD);
        players[(declarant+1)%3]->set_pct_runda(x1);
        players[(declarant+2)%3]->set_pct_runda(x2);
    }
    // mai ai de pus punctele undeva
}

void Runda::returnareCarti(Runda &r) {
    Pachet& pachet = Pachet::getInstance();
    std::vector<Carte>* pack = pachet.getPachet();
    for (auto& p: r.players) {
        CardsWon& c = *p->getCardsWon();
        std::vector<Carte>& carti = c.get_carti();
        while (!carti.empty()) {
            pack->push_back(carti.back());
            carti.pop_back();
        }
    }
}

void Runda::afisPctRunda(Runda &r) {
    std::cout << "Rezultatele rundei:\n";
    for (auto& x: r.players) {
        std::cout << x->getName() << ": " <<  x->get_pct_runda() << "\n";
    }
    std::cout << "\n";
}




