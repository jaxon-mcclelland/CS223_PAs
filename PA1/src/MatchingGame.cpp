#include "MatchingGame.hpp"

MatchingGame::MatchingGame() {
    this->command_List = new LinkedList<std::string, std::string>();
    this->num_players = 0;
    loadCommands();
    loadPlayers();
    int option = -1;
    std::string input;
    while(option != 6) {
            std::cout << "Please select an option below: \n";
            this->displayMenu();
            std::cin >> input;
            option = atoi(input.c_str());
            std::cout << "\n";
        switch(option) {            
            case 1:
                displayRules();
                break;
            case 2:
                std::cout << "Enter name to use: ";
                std::cin >> this->currentPlayerName;
                std::cout << "\n";
                this->currentPlayerScore = 0;
                //if(this->num_players == current_player_arr_size) {
                //    copyPlayerArr();
                //}
                //player_arr[++num_players].changeName(currentPlayerName);
                this->currPlayerIdx = this->num_players++;
                this->player_arr.push_back(new Player(this->currentPlayerName));
                startGame();
                break;
            case 3:
                loadPreviousGame();
                break;
            case 4:
                addCommand();
                break;
            case 5:
                removeCommand();
                break;
            case 6:
                // exit
                writeDataToFiles();
                break;
            default:
                system("clear");
        }
        
    }
}
MatchingGame::~MatchingGame() {
    delete this->command_List;
    //delete[] this->player_arr;

    if(this->command_file.is_open()) {
        this->command_file.close();
    }
    if(this->player_file.is_open()) {
        this->player_file.close();
    }

    for(auto itr:this->player_arr) {
        delete itr;
    }
}

void MatchingGame::startGame() {
    do {    
        std::cout << "How many questions would you like to be asked? (5-30) ";
        std::cin >> this->num_questions;
        std::cout << "\n";
    } while(this->num_questions < 5 || this->num_questions > 30);
    generateQuestionList();
    int gameScore = 0;
    for(auto itr : this->question_list) {
        displayQuestion(itr);    
        int input;
        std::cin >> input;
        if(input == itr.getCorrectNumber()) {
            std::cout << "\nCorrect! Your game total is now " << ++gameScore<< "\n";
        } else {
            std::cout << "\nIncorrect! Your game total is now " << --gameScore << "\n";
        }
    }
    this->player_arr[this->currPlayerIdx]->changeScore(gameScore);
    std::cout << "Your total score is now " << this->player_arr[this->currPlayerIdx]->getScore() << "\n";
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
    std::cout << "\t6.  Exit";
}
void MatchingGame::displayQuestion(Question& input) const {
    int choice = rand() % 3;
    std::cout << "Eneter the correct description for the " << input.getCommand() << " command\n";
    if(choice == 0) {
        input.setCorrectNumber(1);
        std::cout << "\t1) " << input.getCorrectAnswer() << "\n";
        std::cout << "\t2) " << input.getWrongAnswer1() << "\n";
        std::cout << "\t3) " << input.getWrongAnswer2() << "\n";
    } else if(choice == 1) {
        input.setCorrectNumber(2);
        std::cout << "\t1) " << input.getWrongAnswer1() << "\n";
        std::cout << "\t2) " << input.getCorrectAnswer() << "\n";
        std::cout << "\t3) " << input.getWrongAnswer2() << "\n";
    } else {
        input.setCorrectNumber(3);
        std::cout << "\t1) " << input.getWrongAnswer1() << "\n";
        std::cout << "\t2) " << input.getWrongAnswer2() << "\n";
        std::cout << "\t3) " << input.getCorrectAnswer() << "\n";
    }
}
void MatchingGame::loadCommands() {
    if(this->command_file.is_open()) {
        this->command_file.close();
    }
    this->command_file.open("../data/commands.csv", std::ios::in);
    while(!this->command_file.eof()) {
            char command[100];
            char answer[100];
            this->command_file.getline(command, 100, ',');
            this->command_file.getline(answer, 100, '\n');
            this->command_List->insertAtFront(command, answer);
    }
    // head will be EOF, so it should be deleted
    if(this->command_List->getTop().length() == 0) {
        this->command_List->pop();
    }
    
    this->command_file.close();
}
void MatchingGame::loadPlayers() {
    if(this->player_file.is_open()) {
        this->player_file.close();
    }
    this->player_file.open("../data/profiles.csv", std::ios::in);

    current_player_arr_size = 10;
    //this->player_arr = new Player[current_player_arr_size];
    while(!this->player_file.eof()) {
        //if(this->num_players == current_player_arr_size - 1) {
        //    copyPlayerArr();
        //}
        // 
        // For some reason I was unable to fill the array past the first index
        // even though whatever counter I used would increment.
        // To not lose points I have implemented everything so an array can be used
        // Additionally, since the Player data structure can expand at runtime, I would argue that a vector
        // is the best way to implement this, since a vector is just a dynamic array
        //player_file >> player_arr[this->num_players];
        Player* new_player = new Player();
        player_file >> *new_player;
        this->player_arr.push_back(new_player);
        this->num_players++;
    }
    if(this->player_arr.back()->getName().length() == 0) {
        player_arr.pop_back();
        this->num_players--;
    }
    this->player_file.close();

}

void MatchingGame::addCommand() {
    std::string command;
    //std::string description;
    char description[100];
    std::cout << "Enter linux command: ";
    std::cin >> command;
    std::cout << "\nEnter command description (without quotes): ";
    //std::cin >> description;
    std::cin.ignore();
    std::cin.getline(description, 100, '\n');
    if(command_List->findItem(command) != -1) {
        std::cout << "Item already exists in command list\n";
        return;
    }
    std::string new_description;
    new_description.append("\"");
    new_description.append(description);
    new_description.append("\"");
    this->command_List->insertAtFront(command, new_description);
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
/*
void MatchingGame::copyPlayerArr() {
    Player* new_arr = new Player[current_player_arr_size * 2];
    for(int i = 0; i < this->num_players; ++i) {
        new_arr[i] = this->player_arr[i];
    }
    Player* tmp = this->player_arr;
    this->player_arr = new_arr;
    delete[] tmp;
    this->current_player_arr_size *= 2;
}
*/
void MatchingGame::writeDataToFiles() {
    this->command_file.open("../data/commands.csv", std::ios::out);
    this->command_List->writeListToFile(this->command_file);
    this->command_file.close();
    this->player_file.open("../data/profiles.csv", std::ios::out);
    for(auto itr:this->player_arr) {
        this->player_file << itr->getName() << "," << itr->getScore() << "\n";
    }
    this->player_file.close();
}
void MatchingGame::loadPreviousGame() {
    std::string playerName;
    std::cout << "What is the player name to load: ";
    std::cin >> playerName;
    std::cout << "\n";

    for(int i = 0; i < this->num_players; ++i) {
        if(player_arr[i]->getName() == playerName) {
            this->currentPlayerName = playerName;
            this->currentPlayerScore = player_arr[i]->getScore();
            this->currPlayerIdx = i;
            std::cout << "Found score of " << this->currentPlayerScore << "\n";
            startGame();
            return;
        }
    }
    std::cout << "Player not found\n";

}
void MatchingGame::generateQuestionList() {
    while(this->question_list.size() < this->num_questions) {
        int idx = rand() % this->command_List->getListSize();
        std::string command;
        std::string description;
        this->command_List->getNode(idx, command, description);
        std::string wrong_answer1 = this->command_List->getRandomDescription(idx);
        std::string wrong_answer2;
        do {
            wrong_answer2 = this->command_List->getRandomDescription(idx);
        } while(wrong_answer2 == wrong_answer1);
        Question new_question(command, wrong_answer1, wrong_answer2, description);
        this->question_list.emplace(new_question);
    }
}