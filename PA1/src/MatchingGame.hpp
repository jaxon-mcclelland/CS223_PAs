#include "LinkedList.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <string>


class MatchingGame {
    public:
        MatchingGame();
        ~MatchingGame();
        void startGame();
        void displayMenu() const;
        void displayRules() const;
        void loadCommands();
        void loadPlayers();
        void addCommand();
        void removeCommand();
        void copyPlayerArr();
        void writeDataToFiles();
    private:
        std::fstream command_file;
        std::fstream player_file;
        LinkedList<std::string, std::string>* command_List;        
        Player* player_arr;
        int num_players;

};