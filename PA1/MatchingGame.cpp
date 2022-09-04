#include "MatchingGame.hpp"

MatchingGame::MatchingGame() {
}
MatchingGame::~MatchingGame() {}
void MatchingGame::displayMenu() {
    std::cout << "PLease select an option listed below\n";
    std::cout << "\t1) Game Rules\n";
    std::cout << "\t2) Play Game\n";
    std::cout << "\t3) Load Previous Game\n";
    std::cout << "\t4) Add Command\n";
    std::cout << "\t5) Remove Command\n";
    std::cout << "\t6) Exit\n";
}
void MatchingGame::loadCommands() {
    if(this->command_file.is_open()) {
        this->command_file.close();
    }
    this->command_file.open("data/LinuxCommands.csv", std::ios::in);
}
void MatchingGame::loadPlayers() {

}