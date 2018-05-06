//
// Created by Dvir on 5/4/2018.
//

#include "Player.h"

Player::Player(int player_id, int coins) : id(player_id), coins(coins),
                                    completed_chalanges(0),tree_type(IN_PLAYERS_TREE) {
    this->clan = nullptr;
    if (player_id<=0 || coins <0){
        throw invalidInput();
    }
}



Player::~Player() {}

bool Player::operator==(const Player &rhs) const {
    if (this->tree_type==IN_PLAYERS_TREE){
        return id == rhs.id;
    } else {
        return this->coins==rhs.coins;
    }
}

bool Player::operator!=(const Player &rhs) const {
    return (!(*this==rhs));
}


//printing should be in opposite inorder
bool Player::operator<(const Player &rhs) const {
    if (this->tree_type==IN_PLAYERS_TREE){
        return id < rhs.id;
    } else {
        if (this->coins==rhs.coins){
            return this->id > rhs.id;
        } else {
            return this->coins < rhs.coins;
        }
    }
}

bool Player::operator>(const Player &rhs) const {
    if (this->tree_type==IN_PLAYERS_TREE){
        return id < rhs.id;
    } else {
        if (this->coins==rhs.coins){
            return this->id > rhs.id;
        } else {
            return this->coins < rhs.coins;
        }
    }
}

ostream& operator<<(ostream& os,const Player& player){
    std::cout <<  "[" << player.id << "," << player.coins << "] ";
}

void Player::changeTreeType(const int &tree_type) {
    assert (tree_type == IN_PLAYERS_TREE || tree_type == IN_CLAN_TREE);
    this->tree_type = tree_type;
}

bool Player::operator>=(const Player &rhs) const {
    return false;
}

Player::Player() = default;


