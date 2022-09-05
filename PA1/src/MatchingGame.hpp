#include "LinkedList.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <string>


class MatchingGame {
    public:
        MatchingGame();
        ~MatchingGame();
        void displayMenu() const;
        void displayRules() const;
        void loadCommands();
        void loadPlayers();
        void addCommand();
        void removeCommand();

    private:
        std::fstream command_file;
        std::fstream player_file;
        LinkedList<std::string, std::string>* command_List;
        //Player player_arr[];
        
};