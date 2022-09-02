#include "Command.hpp"

Command::Command() {
    this->answer = "";
    this->key = "";
}
Command::Command(std::string command, std::string answer) {
    this->answer = answer;
    this->key = command;
}
Command::~Command() {}
std::string Command::getKey() const {
    return this->key;
}
std::string Command::getAnswer() const {
    return this->answer;
}
void Command::setKey(std::string newKey) {
    this->key = newKey;    
}
void Command::setAnswer(std::string newAnswer) {
    this->answer = newAnswer;
}

std::istream &operator>>(std::istream& lhs, Command &rhs) {
    char command[100];
    char answer[100];
    lhs.getline(command, 100, ',');
    lhs.getline(answer, 100, '\n');
    rhs.setAnswer(answer);
    rhs.setKey(command);
    return lhs;

}
std::ostream &operator<<(std::ostream& lhs, Command &rhs) {
    return lhs;
}