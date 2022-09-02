#include "Player.hpp"

Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
}
Player::~Player() {

}
std::string Player::getName() const {
    return this->name;
}
int Player::getScore() const {
    return this->score;
}
void Player::changeScore(int new_score) {
    this->score = new_score;
}