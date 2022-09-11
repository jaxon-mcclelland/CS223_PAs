#include "Player.hpp"

Player::Player() {
    this->name = "";
    this->score = 0;
}

Player::Player(std::string name) {
    this->name = name;
    this->score = 0;
}
Player::~Player() {

}

Player& Player::operator=(const Player& rhs) {
    if(this == &rhs) {
        return *this;
    }
    name = rhs.getName();
    score = rhs.getScore();
    return *this;
}
std::string Player::getName() const {
    return this->name;
}
int Player::getScore() const {
    return this->score;
}
void Player::changeName(std::string new_name) {
    this->name = new_name;
}
void Player::changeScore(int new_score) {
    this->score = new_score;
}
std::ostream& operator<<(std::ostream& lhs, const Player& rhs) {
    lhs << rhs.getName() << "," << rhs.getScore() << "\n";
    return lhs;
}
std::istream& operator>>(std::istream& lhs, Player& rhs) {
    char buffer[100];
    char name[100];
    lhs.getline(name, 100, ',');
    lhs.getline(buffer, 100, '\n');
    int score = atoi(buffer);
    rhs.changeName(name);
    rhs.changeScore(score);
    return lhs;

}