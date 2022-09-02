#include "LinkedList.h"
#include "Player.hpp"
#include <iostream>

class MatchingGame {
    public:
        MatchingGame();
        ~MatchingGame();
        void displayMenu();
        void loadCommands();
        void loadPlayers();
    private:
        LinkedList<std::string> command_List;
        Player player_arr[];

};