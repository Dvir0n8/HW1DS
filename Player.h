//
// Created by Dvir on 5/4/2018.
//
#ifndef WET1_PLAYER_H
#define WET1_PLAYER_H

#include "Clan.h"
#include "avl_node.h"

const int IN_CLAN_TREE = 0;
const int IN_PLAYERS_TREE = 1;


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

    bool operator==(const Player &rhs) const;

    bool operator!=(const Player &rhs) const;

    bool operator<(const Player &rhs) const;

    bool operator>(const Player &rhs) const;

    bool operator>=(const Player &rhs) const;


    void changeTreeType(const int &tree_type);

    friend ostream &operator<<(ostream &os, const Player &player);

    class PlayerException : public std::exception {
    };

    class invalidInput : PlayerException {
    };

    class playerSuccess : PlayerException {
    };

    class playerFailure : PlayerException {
    };


};


#endif //WET1_PLAYER_H
