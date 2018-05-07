//
// Created by Dvir on 5/4/2018.
//

#include <assert.h>
#include "Player.h"

Player::Player(int player_id, int coins) : id(player_id), coins(coins),
                                    completed_chalanges(0),tree_type(SORT_BY_ID) {
    this->clan = nullptr;
    if (player_id<=0 || coins <0){
        throw invalidInput();
    }
}



Player::~Player() {}

bool Player::operator==(const Player &rhs) const {
    if (this->tree_type==SORT_BY_ID){
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
    if (this->tree_type==SORT_BY_ID){
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
    if (this->tree_type==SORT_BY_ID){
        return id > rhs.id;
    } else {
        if (this->coins==rhs.coins){
            return this->id < rhs.id;
        } else {
            return this->coins > rhs.coins;
        }
    }
}

ostream& operator<<(ostream& os,const Player& player){
    std::cout <<  "[" << player.id << "," << player.coins << "] ";
}

void Player::changeTreeType(const int &tree_type) {
    assert (tree_type == SORT_BY_ID || tree_type == SORT_BY_COINS);
    this->tree_type = tree_type;
}

bool Player::operator>=(const Player &rhs) const {
    return false;
}

void Player::setClan(Clan *clan) {
    this->clan = clan;
}

void Player::increaseCompletedChalanges(int completed_chalanges) {
    this->completed_chalanges++;
}

int Player::getId() const {
    return id;
}

int Player::getCoins() const {
    return coins;
}

Clan *Player::getClan() const {
    return clan;
}

int Player::getCompleted_chalanges() const {
    return completed_chalanges;
}

int Player::getTree_type() const {
    return tree_type;
}

Player &Player::operator=(const Player &player) {
    this->coins = player.coins;
    this->tree_type = player.tree_type;
    this->id = player.id;
    this->clan = player.clan;
    this->completed_chalanges = player.completed_chalanges;
    return *this;
}

void Player::addCoins(int coins) {
    if (coins <0){
        throw invalidInput();
    }
    this->coins+=coins;
}

Player::Player() = default;


