//
// Created by Dvir on 5/4/2018.
//
#ifndef WET1_PLAYER_H
#define WET1_PLAYER_H

#include "Clan.h"
#include "avl_node.h"

const int SORT_BY_COINS = 0;
const int SORT_BY_ID = 1;


class Player {
    int id;
    int coins;
    Clan *clan;
    int completed_chalanges;
    int tree_type;

public:
    Player(int id, int coins);

    Player();

    ~Player();
    Player& operator=(const Player& player);
    bool operator==(const Player &rhs) const;

    bool operator!=(const Player &rhs) const;

    bool operator<(const Player &rhs) const;

    bool operator>(const Player &rhs) const;

    bool operator>=(const Player &rhs) const;


    void changeTreeType(const int &tree_type);

    friend ostream &operator<<(ostream &os, const Player &player);

    void setClan(Clan *clan);

    void increaseCompletedChalanges(int completed_chalanges);

    int getId() const;

    int getCoins() const;

    Clan *getClan() const;

    int getCompleted_chalanges() const;

    int getTree_type() const;

    void addCoins(int coins);

    class PlayerException : public std::exception {
    };

    class invalidInput : PlayerException {
    };

    class playerSuccess : PlayerException {
    };

    class playerFailure : PlayerException {
    };


};


class updateClanPred {
    int ID;
    Clan* clan;
public:
    updateClanPred(int ID,Clan* clan) : ID(ID), clan(clan) {};
    bool operator()(Player& player) {
        if (player.getId() == this->ID) {
            player.setClan(this->clan);
            return true;
        }
        return false;
    }

};
#endif //WET1_PLAYER_H
