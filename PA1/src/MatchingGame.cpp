#include "MatchingGame.hpp"
// REMEMBER THAT A SINGLE COMMAND CANNOT BE LISTED MORE THAN ONCE
// DO NOT WRITE UPDATES TO PROFILES.CSV UNTIL THE END
// 5-30 questions
MatchingGame::MatchingGame() {
    this->command_List = new LinkedList<std::string, std::string>();
    int option = 7;
    do {
        std::cout << "Please select an option below: \n";
        this->displayMenu();
        std::cin >> option;
        switch(option) {
            case 1:
                this->displayRules();
                option = 7;
                break;
            case 2:
                // start game
                break;
            case 3:
                // load previous game
                break;
            case 4:
                this->addCommand();
                option = 7;
                break;
            case 5:
                this->removeCommand();
                option = 7;
                // remove command
                break;
            case 6:
                break;
            
        }
    } while(option < 1 || option > 6);
}
MatchingGame::~MatchingGame() {
    
    if(this->command_file.is_open()) {
        this->command_file.close();
    }
    if(this->player_file.is_open()) {
        this->player_file.close();
    }
}
void MatchingGame::displayRules() const {
    std::cout << "The rules of the game are as follows:\n";
    std::cout << "\t 1) A user will be prompted with a command and 3 options for the command definition.\n";
    std::cout << "\t 2) Guessing the command definition correctly will net the user 1 point\n";
    std::cout << "\t 3) Guessing the command wrong will net the user -1 points\n";

}
void MatchingGame::displayMenu() const {
    std::cout << "\t1.  Game Rules\n";
    std::cout << "\t2.  Play Game\n";
    std::cout << "\t3.  Load Previous Game\n"; 
    std::cout << "\t4.  Add Command\n";
    std::cout << "\t5.  Remove Command\n"; 
    std::cout << "\t6.  Exit\n";
}
void MatchingGame::loadCommands() {
    if(this->command_file.is_open()) {
        this->command_file.close();
    }
    this->command_file.open("data/LinuxCommands.csv", std::ios::in);
    while(!this->command_file.eof()) {
            char command[100];
            char answer[100];
            this->command_file.getline(command, 100, ',');
            this->command_file.getline(answer, 100, '\n');
            this->command_List->insertAtFront(command, answer);
    }
}
void MatchingGame::loadPlayers() {

}
void MatchingGame::addCommand() {
    std::string command;
    std::string description;

    std::cout << "Enter linux command: ";
    std::cin >> command;
    std::cout << "\nEnter command description: ";
    std::cin >> description;
    std::cout << std::endl;
    // check for duplicates?
    if(command_List->findItem(command) != -1) {
        std::cout << "Item already exists in command list\n";
        return;
    }
    this->command_List->insertAtFront(command, description);
    std::cout << "Item successfully inserted\n";
}
void MatchingGame::removeCommand() {
    std::string command;
    std::string description;

    std::cout << "Enter linux command: ";
    std::cin >> command;
    std::cout << std::endl;
    // check for duplicates?
    if(command_List->findItem(command) == -1) {
        std::cout << "Item does not exist in command list\n";
        return;
    }
    this->command_List->removeNode(command);
    std::cout << "Item successfully removed\n";
}