#pragma once
#include <iostream>
#include "CardsWon.h"
#include "PlayHand.h"
#include <memory>
#include "AtuStrategy.h"
#include "JoacaStrategy.h"
#include "Puncte.h"

class Player {
protected:
    int id;
    static int id_gen;
    std::string name;
    PlayHand hand;
    CardsWon cardsWon;
    std::unique_ptr<AtuStrategy> atu_strategy;
    std::unique_ptr<JoacaStrategy> joaca_strategy;
    int pct_runda = 0;
public:
    explicit Player(std::unique_ptr<AtuStrategy> atu_strategy, std::unique_ptr<JoacaStrategy> joaca_strategy, std::string name = "Unknown")
        : id(id_gen),
          name(std::move(name)),
          atu_strategy(std::move(atu_strategy)), joaca_strategy(std::move(joaca_strategy)) {id_gen++;}

    //Player(std::unique_ptr<AtuStrategy> strat, const std::string& _name = "Unknown"): id(id_gen), name(_name), atu_strategy(std::move(strat)) {id_gen++;};
    Player(const Player&) = delete;
    virtual ~Player() = default;
    void setHand(const PlayHand& _hand);
    PlayHand* getPHand();
    CardsWon* getCardsWon();
    void setAtuStrategy(std::unique_ptr<AtuStrategy> _atu_strategy);
    void setJoacaStrategy(std::unique_ptr<JoacaStrategy> _joaca_strategy);
    virtual bool joacaAtu(Culoare) = 0;
    virtual Culoare alegeAtu(int) = 0;
    virtual Carte joaca(std::vector<Carte>&, bool, Puncte&, Culoare atu, int) = 0;
    void set_pct_runda(int _pct_runda);
    int get_pct_runda() const;
    const std::string& getName();
    static int taiereCarti();
    bool humanStrategy() const;
};

