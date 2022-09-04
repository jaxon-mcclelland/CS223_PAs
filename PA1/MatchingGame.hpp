#include "LinkedList.h"
#include "Player.hpp"
#include <iostream>
#include <fstream>

class MatchingGame {
    public:
        MatchingGame();
        ~MatchingGame();
        void displayMenu();
        void loadCommands();
        void loadPlayers();
    private:
        std::fstream command_file;
        std::fstream player_file;
        LinkedList<std::string> command_List;
        Player player_arr[];

};